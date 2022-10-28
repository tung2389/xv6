// Start of code added by Tung, Khoi and Brian 
#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[]) {
    int ret = mprotect((void*)4096, 3);
    printf(1, "Return value of mprotect : %d\n", ret);

    ret = munprotect((void*)4096, 1);
    printf(1, "Return value of munprotect : %d\n", ret);

    *(char**)0x1000 = "this should not cause a pagefault";

    printf(1, "XV6_TEST_OUTPUT Written to 0x1000\n");
    exit();
}