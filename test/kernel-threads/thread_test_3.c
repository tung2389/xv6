// Start of code added by Tung, Khoi and Brian 
// Test invalid call to clone
#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
  int ret = clone((void*)0xFFFF, (void*)31415, (void*)0, (void*)0);
  printf(1, "XV6_TEST_OUTPUT: Return value of clone system call: %d\n", ret);

  exit();
}