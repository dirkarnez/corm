#include <stdio.h>
#include <string.h>

struct book{
   char title[10];
   double price;
   int pages;
};

char arr[3][10] = {"title", "price", "pages"};

// book_equal should be a proxy
union book_equal{
   void* title;
   void* price;
   void* pages;
};

struct book * db_select_book(union book_equal* be)  {
    printf("select from \"book\" where id == 1");
    return NULL;
}

int main(){
   
   struct book b1 = {"Learn C", 675.50, 325};

   union book_equal be = { .title = NULL };
   struct book *strptr = db_select_book(&be);
   
   return 0;
}

