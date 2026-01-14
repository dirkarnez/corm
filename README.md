corm
====
### TODOs
- [ ] memory issue
  - [ ] use string builder facilities
    - https://github.com/maxim2266/str
- [ ] Builder pattern
  - [Abusing Go Syntax to Create a Domain-Specific Language | Gopher Academy Blog](https://blog.gopheracademy.com/advent-2016/go-syntax-for-dsls/)
- [ ] Generate higher-order functions
  - [dirkarnez/c-higher-order-function](https://github.com/dirkarnez/c-higher-order-function/tree/main) 
- [ ] [FreshRSS/lib/Minz/ModelPdo.php at edge · FreshRSS/FreshRSS](https://github.com/FreshRSS/FreshRSS/blob/edge/lib/Minz/ModelPdo.php)
- [ ] Code generator (in python)
  - https://github.com/dirkarnez/tbuild/tree/main/examples/codegen
    - [ ] generate dry-run / assertion for compilation (as C does not support static assertion on `const`)
    - [ ] data types
      - https://html.spec.whatwg.org/multipage/input.html
    - [CG/SQL | CG/SQL](https://cgsql.dev/)
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
      ```c
      static struct iwlwifi_opmode_table {
      	const char *name;			/* name: iwldvm, iwlmvm, etc */
      	const struct iwl_op_mode_ops *ops;	/* pointer to op_mode ops */
      	struct list_head drv;		/* list of devices using this op_mode */
      } iwlwifi_opmode_table[] = {		/* ops set when driver is initialized */
      	[DVM_OP_MODE] = { .name = "iwldvm", .ops = NULL },
      	[MVM_OP_MODE] = { .name = "iwlmvm", .ops = NULL },
      #if IS_ENABLED(CPTCFG_IWLMLD)
      	[MLD_OP_MODE] = { .name = "iwlmld", .ops = NULL },
      #endif
      #if IS_ENABLED(CPTCFG_IWLXVT)
      	[XVT_OP_MODE] = { .name = "iwlxvt", .ops = NULL },
      #endif
      };
      
      
      
      static const struct {
      	const char *name;
      	u32 num;
      } advanced_lookup[] = {
      	{ "USER_ASSERT", 0x33 },
      	{ "NMI_INTERRUPT_WDG", 0x34 },
      	{ "SYSASSERT", 0x35 },
      	{ "UCODE_VERSION_MISMATCH", 0x37 },
      	{ "BAD_COMMAND", 0x38 },
      	{ "BAD_COMMAND", 0x39 },
      	{ "NMI_INTERRUPT_DATA_ACTION_PT", 0x3C },
      	{ "FATAL_ERROR", 0x3D },
      	{ "NMI_TRM_HW_ERR", 0x46 },
      	{ "NMI_INTERRUPT_TRM", 0x4C },
      	{ "NMI_INTERRUPT_BREAK_POINT", 0x54 },
      	{ "NMI_INTERRUPT_WDG_RXF_FULL", 0x5C },
      	{ "NMI_INTERRUPT_WDG_NO_RBD_RXF_FULL", 0x64 },
      	{ "NMI_INTERRUPT_HOST", 0x66 },
      	{ "NMI_INTERRUPT_LMAC_FATAL", 0x70 },
      	{ "NMI_INTERRUPT_UMAC_FATAL", 0x71 },
      	{ "NMI_INTERRUPT_OTHER_LMAC_FATAL", 0x73 },
      	{ "NMI_INTERRUPT_ACTION_PT", 0x7C },
      	{ "NMI_INTERRUPT_UNKNOWN", 0x84 },
      	{ "NMI_INTERRUPT_INST_ACTION_PT", 0x86 },
      	{ "NMI_INTERRUPT_PREG", 0x88 },
      	{ "PNVM_MISSING", FW_SYSASSERT_PNVM_MISSING },
      	{ "ADVANCED_SYSASSERT", 0 },
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
