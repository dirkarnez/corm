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
    /* container = */book_select(bookname);
    /* container = */book_select(/* expression*/);
    /* container = */book_where(/*ast-like object*/);
    /* container = */book_having(bookname);
    /* container = */book_group_by(bookname/*,  other fields */);
    /* container = */book_order_by_ascending(bookname);
    /* container.*/run();
    return 0;
}
