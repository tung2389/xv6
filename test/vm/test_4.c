// Start of code added by Tung, Khoi and Brian 
#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{   
    char *p = (char *)0x1000;
    int ret = mprotect((void *)p, 1);
    printf(1, "Return value of mprotect on memory 0x1000: %d\n", ret);

    if(fork() == 0)
    {
        printf(1, "Inside child process\n");
        *p = 'w';

        printf(1, "This should not be printed\n");
        exit();
    }
    else
    {
        (void)wait();
        printf(1, "Parent done waiting\n");
    }
    
    exit();
}