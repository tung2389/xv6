// Start of code added by Brian, Tung, and Khoi 
#include "types.h"
#include "stat.h"
#include "user.h"

// Test to write after unprotect
// int
// main(int argc, char *argv[]) {
//     int ret = mprotect((void*)4096, 3);
//     printf(1, "Return value of mprotect : %d\n", ret);

//     ret = munprotect((void*)4096, 1);
//     printf(1, "Return value of munprotect : %d\n", ret);

    // *(char**)0x1000 = "this should not cause a pagefault";

//     printf(1, "Written to 0x1000\n");
//     exit();
// }

// Test to write after protect
// int
// main(int argc, char *argv[]) {
//     int *pg1 = (int *) 0x1000;
//     int rc = mprotect((void *) pg1, 2);
//     printf(1, "mprotect return: %d \n", rc);
//     printf(1, "Reading is allowed: %d \n", *pg1);
//     printf(1, "Writing is prohibited \n");
//     *pg1 = 1;
//     printf(1, "This line should not be printed \n");
//     exit();
// }

// Test write after protect on child
// int main(int argc, char *argv[])
// {   
//     char *p = (char *)0x1000;
//     int ret = mprotect((void *)p, 1);
//     printf(1, "Return value of mprotect on memory 0x1000: %d\n", ret);

//     if(fork() == 0)
//     {
//         printf(1, "Inside child process\n");
//         *p = 'w';

//         printf(1, "This should not be printed\n");
//         exit();
//     }
//     else
//     {
//         (void)wait();
//         printf(1, "Parent done waiting\n");
//     }
    
//     exit();
// }

// Test misalignment
// int
// main(int argc, char *argv[]) {
//     int *pg1 = (int *) 0x1001;
//     int rc = mprotect((void *) pg1, 2);
//     if (rc == -1){
//         printf(1, "misalignment\n");
//         exit();
//     }
//     printf(1, "This line should not be printed \n");
//     exit();
// }

// Test 0 or negative length
int
main(int argc, char *argv[]) {
    int *pg1 = (int *) 0x1001;
    int rc = mprotect((void *) pg1, 0);
    if (rc == -1){
        printf(1, "invalid len\n");
        exit();
    }
    printf(1, "This line should not be printed \n");
    exit();
}
// End of code added by Brian, Tung, and Khoi