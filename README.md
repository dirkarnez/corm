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
- [ ] **May use private interface to hide magic number inside structs, eg same struct different values for generic programming**
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
