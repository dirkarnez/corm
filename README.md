corm
====
### TODOs
- [ ] memory issue
  - [ ] use string builder facilities
    - https://github.com/maxim2266/str 
- [ ] Code generator (in python)
  - https://github.com/dirkarnez/tbuild/tree/main/examples/codegen
    - [ ] generate dry-run / assertion for compilation (as C does not support static assertion on `const`) 
- [ ] demonstration
  - mariadb using [dirkarnez/mariadb-connector-c-prebuilt](https://github.com/dirkarnez/mariadb-connector-c-prebuilt)
  - baremetal environment
- [ ] nice interface
  - do not use `union` to store generic value, instead, generate multiple functions for each type
- [ ] **May use private interface to hide magic number inside structs, eg same struct different values for generic programming**
- [ ] builder pattern (reference to libcurl example code)
  - [dirkarnez/c-builder-pattern](https://github.com/dirkarnez/c-builder-pattern)
- [ ] .rodata
  - ```c
    struct SIMPLE
    {
        int a;
        char b;
        double c;
    };
    
    static volatile const struct SIMPLE a = {};
    ```
  - [ ] offset
    - ```c
      #include <stddef.h>
      #include <stdio.h>
      
      struct address {
         char name[50];
         char street[50];
         int phone;
      };
         
      int main()
      {
         printf("address 结构中的 name 偏移 = %d 字节。\n",
         offsetof(struct address, name));
         
         printf("address 结构中的 street 偏移 = %d 字节。\n",
         offsetof(struct address, street));
         
         printf("address 结构中的 phone 偏移 = %d 字节。\n",
         offsetof(struct address, phone));
      
         return(0);
      }
      ```
