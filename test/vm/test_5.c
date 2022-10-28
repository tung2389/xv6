// Start of code added by Tung, Khoi and Brian 
#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[]) {
    int *pg1 = (int *) 0x1001;
    int rc = mprotect((void *) pg1, 2);
    if (rc == -1){
        printf(1, "XV6_TEST_OUTPUT misalignment\n");
        exit();
    }
    printf(1, "This line should not be printed \n");
    exit();
}