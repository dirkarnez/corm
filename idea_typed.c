#include <stdio.h>

typedef struct {
    int (*func_ptr)(int);
} B;

int sum(int a) {
    return a + 1;
}

int select_book(B *b) {
    return b->func_ptr(10);
}

#define bookname (&(B){.func_ptr = sum})

int main() {
    // SELECT CustName, State, COUNT(*) AS ‘No. of Orders’ FROM `Order` GROUP BY State, CustName HAVING COUNT(*)>1 ORDER BY CustName;
    /* container = */book_select(book_name);
    /* container = */book_select(/* expression*/);
    /* container = */book_where(/*ast-like object*/);
    /* container = */book_having(book_name);
    /* container = */book_group_by(book_name/*,  other fields */);
    /* container = */book_order_by_ascending(book_name);
    /* container.*/run();
    /*
    the container has the fields specified in `book_select`, so it returns an array of entity, 
    eneity should not be struct, but container, so we can get data / field names / property name by generated functions
    */
    return 0;
}
