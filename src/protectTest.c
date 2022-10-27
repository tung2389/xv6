// #include "types.h"
// #include "stat.h"
// #include "user.h"

// int
// main(int argc, char *argv[]) {
//     int ret = mprotect((void*)4096, 5);
//     printf(1, "XV6_TEST_OUTPUT: Return value of mprotect : %d\n", ret);

//     // ret = munprotect((void*)4096, 1);
//     // printf(1, "XV6_TEST_OUTPUT: Return value of munprotect : %d\n", ret);

//     *(char**)0x1000 = "this should not cause a pagefault";

//     printf(1, "XV6_TEST_OUTPUT: Written to 0x1000\n");
//     exit();
// }

#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[]) {
    int *pg1 = (int *) 4096;
    int rc = mprotect((void *) pg1, 2);
    printf(1, "mprotect return: %d \n", rc);
    printf(1, "Reading is allowed: %d \n", *pg1);
    printf(1, "Writing is prohibited \n");
    *pg1 = 1234;
    printf(1, "This line should not be printed \n");
    exit();
}