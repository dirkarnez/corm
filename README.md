corm
====
### TODOs
- [ ] memory issue
  - [ ] use string builder facilities
    - https://github.com/maxim2266/str
- [ ] Builder pattern
  - [Abusing Go Syntax to Create a Domain-Specific Language | Gopher Academy Blog](https://blog.gopheracademy.com/advent-2016/go-syntax-for-dsls/)
- [ ] [FreshRSS/lib/Minz/ModelPdo.php at edge · FreshRSS/FreshRSS](https://github.com/FreshRSS/FreshRSS/blob/edge/lib/Minz/ModelPdo.php)
- [ ] Code generator (in python)
  - https://github.com/dirkarnez/tbuild/tree/main/examples/codegen
    - [ ] generate dry-run / assertion for compilation (as C does not support static assertion on `const`) 
- [ ] demonstration
  - mariadb using [dirkarnez/mariadb-connector-c-prebuilt](https://github.com/dirkarnez/mariadb-connector-c-prebuilt)
  - baremetal environment
- [ ] nice interface
  - do not use `union` to store generic value, instead, generate multiple functions for each type
- [ ] **May use private interface to hide magic number inside structs, eg same struct different values for generic programming**
- [ ] [SOCI (master)](https://soci.sourceforge.net/doc/master/)
- [ ] builder pattern (reference to libcurl example code)
  - [dirkarnez/c-builder-pattern](https://github.com/dirkarnez/c-builder-pattern)
- [ ] adapters for db dialects
  - [mysql 预处理stmt操作（写入数据库和从数据库中取出）-CSDN博客](https://blog.csdn.net/v6543210/article/details/103220593)
- [ ] adapter for plain prepared statement generation
- [ ] https://github.com/kataras/iris/blob/main/_examples/database/mysql/entity/product.go
- [ ] [dirkarnez/go-mariadb-no-orm](https://github.com/dirkarnez/go-mariadb-no-orm)
- [ ] .rodata (must corm must check in pe / elf / mach-o viewer)
  - ```c
    struct SIMPLE
    {
        int a;
        char b;
        double c;
    };
    
    static volatile const struct SIMPLE a = {};
    ```
  - [ ] lookup array
    - ```c
      https://github.com/openjdk/loom/blob/fibers/src/java.base/windows/native/libnio/MappedMemoryUtils.c
      static JNINativeMethod methods[] = {
          {"isLoaded0", "(JJJ)Z",             (void *)&MappedMemoryUtils_isLoaded0},
          {"load0",     "(JJ)V",              (void *)&MappedMemoryUtils_load0},
          {"unload0",   "(JJ)V",              (void *)&MappedMemoryUtils_unload0},
          {"force0",    "(" FD "JJ)V",        (void *)&MappedMemoryUtils_force0},
      };
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
### Reference
- [uptrace/bun: SQL-first Golang ORM](https://github.com/uptrace/bun)
