#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SQL_BUILDER_INIT_SIZE 256

typedef struct {
    char *query;
    size_t size;
    size_t capacity;
} SQLBuilder;

// Function to create a new SQLBuilder
SQLBuilder* create_sql_builder() {
    SQLBuilder *builder = (SQLBuilder *)malloc(sizeof(SQLBuilder));
    builder->size = 0;
    builder->capacity = SQL_BUILDER_INIT_SIZE;
    builder->query = (char *)malloc(builder->capacity);
    builder->query[0] = '\0'; // Initialize the query string
    return builder;
}

// Function to append strings to the SQL query
void sql_builder_append(SQLBuilder *builder, const char *str) {
    size_t len = strlen(str);
    if (builder->size + len >= builder->capacity) {
        builder->capacity *= 2; // Double the capacity
        builder->query = (char *)realloc(builder->query, builder->capacity);
    }
    strcat(builder->query, str);
    builder->size += len;
}

// Function to add a SELECT statement
void sql_builder_select(SQLBuilder *builder, const char *columns) {
    sql_builder_append(builder, "SELECT ");
    sql_builder_append(builder, columns);
}

// Function to add a FROM clause
void sql_builder_from(SQLBuilder *builder, const char *table) {
    sql_builder_append(builder, " FROM ");
    sql_builder_append(builder, table);
}

// Function to add a WHERE clause
void sql_builder_where(SQLBuilder *builder, const char *condition) {
    sql_builder_append(builder, " WHERE ");
    sql_builder_append(builder, condition);
}

// Function to get the final SQL query
const char* sql_builder_get_query(SQLBuilder *builder) {
    return builder->query;
}

// Function to free the SQLBuilder
void sql_builder_free(SQLBuilder *builder) {
    free(builder->query);
    free(builder);
}

// Example usage
int main() {
    SQLBuilder *builder = create_sql_builder();
    
    sql_builder_select(builder, "id, name, age");
    sql_builder_from(builder, "users");
    sql_builder_where(builder, "age > 18");

    printf("Generated SQL: %s\n", sql_builder_get_query(builder));

    sql_builder_free(builder);
    return 0;
}
