// Start of code added by Tung, Khoi and Brian 
// Test invalid call to join
#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
  int ret = join((void**)0xFFFF);
  printf(1, "XV6_TEST_OUTPUT: Return value of join system call: %d\n", ret);
  exit();
}