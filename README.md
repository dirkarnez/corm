corm
====
### TODOs
- [ ] memory issue
  - [ ] use string builder facilities
- [ ] Code generator (in python)
- [ ] demonstration
  - mariadb
  - baremetal environment
- [ ] use `enum`
  - ```c
    #include <stdio.h>
    
    enum Status {
        SUCCESS = 1,  // Starting from 1
        ERROR = 2,    // Automatically assigned 2
        PENDING = 3   // Automatically assigned 3
    };
    
    int main() {
        enum Status currentStatus;
    
        currentStatus = SUCCESS;
    
        if (currentStatus == SUCCESS) {
            printf("Operation was successful.\n");
        } else if (currentStatus == ERROR) {
            printf("An error occurred.\n");
        } else if (currentStatus == PENDING) {
            printf("Operation is pending.\n");
        }
    
        return 0;
    }
    ```
