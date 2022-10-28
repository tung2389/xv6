// Start of code added by Tung, Khoi and Brian 
#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[]) {
    int *pg1 = (int *) 0x1000;
    int rc = mprotect((void *) pg1, 2);
    printf(1, "mprotect return: %d \n", rc);
    printf(1, "Reading is allowed: %d \n", *pg1);
    printf(1, "Writing is prohibited \n");
    *pg1 = 1;
    printf(1, "This line should not be printed \n");
    exit();
}