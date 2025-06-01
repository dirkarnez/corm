#include <stdio.h>
#include <string.h>
#include <assert.h>

// Define a structure for a book with a title, price, and number of pages
struct book {
    char title[10]; // Title of the book (fixed size)
    double price;   // Price of the book
    int pages;      // Number of pages in the book
};

// An array to hold the names of the fields in the book struct
char *myArray[] = {
    "title", // Field name for title
    "price", // Field name for price
    "pages"  // Field name for pages
}; 

// Array representing the data types of each field
// 9 = string, 10 = integer (for simplicity)
unsigned int types[] = {
    9,  // Title is a string
    10, // Price is a double (treated as integer for simplicity)
    10  // Pages is an integer
}; 

// Enum-like structure to define the fields by name
typedef struct {
    enum book_fields_enum { 
        title = 0, 
        price = 1,
        pages = 2
    } field; // Index for pages
} book_equal_t;


typedef struct  {
    char* ptr;
    unsigned int length;
} string_ptr_value_t; // Struct as a member of the union

// Union to hold either an integer or a string value
union ValueBox {
    int integer_value;  // For integer types
    string_ptr_value_t  string_ptr_value;
    char* string_literal_value;
};

// void a (book_equal_t_wrapper b) {
//     printf(b.field.title)
// }
// Function to simulate a database query for a book, based on a field index and value
struct book* db_select_book(book_equal_t* field_index_struct, union ValueBox* box) {
    static unsigned int base = 0; // Base index for the fields
    static unsigned int fields_count = 3; // Total number of fields
    static char* table_name = "books"; // Name of the table

    // Buffer to hold the value for the query
    char value_buffer[100];

    // Check if the field is a string or an integer
    if (types[base + field_index_struct->field] == 9) {
        // If it's a string, format it accordingly
        sprintf(value_buffer, "`%s`", box->string_literal_value);
    } else {
        // If it's an integer, format it as an integer
        sprintf(value_buffer, "%d", box->integer_value);
    }

    // Print the simulated SQL query
    printf("select * from `%s` where `%s` = %s\n", table_name, myArray[base + field_index_struct->field], value_buffer);
    return NULL; // In a real implementation, this would return a pointer to the result
}

// Main function to demonstrate the ORM functionality
int main() {
    // Create a book instance with specific values
    struct book b1 = {"Learn C", 675.50, 325};

    // select_books(db, one filter function)
    // Or(list of filter function) is one filter function
    // And(list of filter function) is one filter function
    
    struct book *strptr_1 = db_select_book(
        &(book_equal_t){ .field = title }, 
        &(union ValueBox){ .string_literal_value = "123" }
    );

    // Simulate a database query for the price field
    struct book *strptr_2 = db_select_book(
        &(book_equal_t){ .field = price }, 
        &(union ValueBox){ .integer_value = 123 });

    char buffer[] = "12345";

    struct book *strptr_3 = db_select_book(
        &(book_equal_t){ .field = title }, 
        &(union ValueBox){ .string_ptr_value = (string_ptr_value_t){ .ptr = buffer, .length = sizeof(buffer) } }
    );

    return 0; // End of the program
}

```
int string_get_size(u64 size, u64 blk_size, const enum string_size_units units,
		    char *buf, int len)
{
	enum string_size_units units_base = units & STRING_UNITS_MASK;
	static const char *const units_10[] = {
		"", "k", "M", "G", "T", "P", "E", "Z", "Y",
	};
	static const char *const units_2[] = {
		"", "Ki", "Mi", "Gi", "Ti", "Pi", "Ei", "Zi", "Yi",
	};
	static const char *const *const units_str[] = {
		[STRING_UNITS_10] = units_10,
		[STRING_UNITS_2] = units_2,
	};
	static const unsigned int divisor[] = {
		[STRING_UNITS_10] = 1000,
		[STRING_UNITS_2] = 1024,
	};
	static const unsigned int rounding[] = { 500, 50, 5 };
	int i = 0, j;
	u32 remainder = 0, sf_cap;
	char tmp[12];
	const char *unit;

	tmp[0] = '\0';
```
