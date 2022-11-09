// Start of code added by Tung, Khoi and Brian 
// Test thread ID of clone and join
#include "types.h"
#include "stat.h"
#include "user.h"

void test_thread_create(void *arg1, void *arg2) {
  // Do something
  *(int *)arg2 = *(int *)arg1;
  exit();
}

int main(int argc, char *argv[])
{
  void *stack = sbrk(4096);
  memset(stack, 0, 4096);

  int pid1 = clone(test_thread_create, (void*)123, (void*)456, stack);
  int pid2 = join(&stack);

  if(pid1 == pid2)
  {
    printf(1, "XV6_TEST_OUTPUT: Same PID\n");
  }
  else
  {
    printf(1, "XV6_TEST_OUTPUT: Different PID\n");
  }
  exit();
}