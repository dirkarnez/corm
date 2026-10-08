#include <iostream>
#include <meta>
#include <string>
#include <string_view>
#include <unordered_map>
#include <sstream>

// ==========================================
// 1. Target ORM Struct / Model
// ==========================================
struct User {
    int id;
    std::string name;
    int age;
    std::string email;
};

// ==========================================
// 2. ORM Core reflection Engine (C++26)
// ==========================================
class SimpleORM {
public:
    // A: Serialize an object into an SQL INSERT statement
    template <typename T>
    static std::string to_insert_query(const T& obj, std::string_view table_name) {
        constexpr std::meta::info type_info = ^^T;
        constexpr auto access_ctx = std::meta::access_context::current();
        
        std::ostringstream columns;
        std::ostringstream values;
        
        bool first = true;

        // template for unrolls loops at compile-time over metadata
        template for (constexpr auto member : std::meta::nonstatic_data_members_of(type_info, access_ctx)) {
            if (!first) {
                columns << ", ";
                values << ", ";
            }
            first = false;

            // Extract the field name as a compile-time string
            constexpr std::string_view field_name = std::meta::identifier_of(member);
            columns << field_name;

            // Extract and append values using the splicer [: member :]
            auto&& value = obj.[:member:];
            using MemberType = decltype(value);

            if constexpr (std::is_same_v<MemberType, std::string>) {
                values << "'" << value << "'"; // Escape strings for SQL
            } else {
                values << value;
            }
        }

        std::ostringstream query;
        query << "INSERT INTO " << table_name << " (" << columns.str() << ") VALUES (" << values.str() << ");";
        return query.str();
    }

    // B: Hydrate/Deserialize an object from a string-key Database row dictionary
    template <typename T>
    static T hydrate(const std::unordered_map<std::string, std::string>& db_row) {
        T obj{};
        constexpr std::meta::info type_info = ^^T;
        constexpr auto access_ctx = std::meta::access_context::current();

        template for (constexpr auto member : std::meta::nonstatic_data_members_of(type_info, access_ctx)) {
            constexpr std::string_view field_name = std::meta::identifier_of(member);
            
            // Look up the field name string in the db map
            if (auto it = db_row.find(std::string(field_name)); it != db_row.end()) {
                auto&& field_ref = obj.[:member:];
                using MemberType = std::decay_t<decltype(field_ref)>;

                // Map data types accordingly
                if constexpr (std::is_same_v<MemberType, int>) {
                    field_ref = std::stoi(it->second);
                } else if constexpr (std::is_same_v<MemberType, std::string>) {
                    field_ref = it->second;
                }
                // (Extendable to double, bool, etc.)
            }
        }
        return obj;
    }
};

// ==========================================
// 3. Execution Execution
// ==========================================
int main() {
    // ---- Test Case 1: Serialization (Object -> SQL String Mapping) ----
    User alice{1, "Alice Smith", 28, "alice@example.com"};
    
    std::string sql = SimpleORM::to_insert_query(alice, "users");
    std::cout << "--- Generated SQL Query ---\n" << sql << "\n\n";

    // ---- Test Case 2: Deserialization (String Dictionary -> Object) ----
    std::unordered_map<std::string, std::string> mock_db_row = {
        {"id", "42"},
        {"name", "Bob Jones"},
        {"age", "35"},
        {"email", "bob@domain.com"}
    };

    User bob = SimpleORM::hydrate<User>(mock_db_row);

    std::cout << "--- Hydrated Object From Database ---\n";
    std::cout << "ID:    " << bob.id << "\n";
    std::cout << "Name:  " << bob.name << "\n";
    std::cout << "Age:   " << bob.age << "\n";
    std::cout << "Email: " << bob.email << "\n";

    return 0;
}
