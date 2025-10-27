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

    select_book(bookname);
    select_book(bookname);
    select_book_where();
    select_book_run();
    return 0;
}
