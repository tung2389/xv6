// Test concurrency on updating variable
#include "types.h"
#include "stat.h"
#include "user.h"

int shared_global = 12;
lock_t mylock;

void test_thread_create(void *arg1, void *arg2) {
  for (int i = 0; i < 1000; i++) {
    lock_acquire(&mylock);
    shared_global++;
    lock_release(&mylock);
  }
  exit();
}

void test_thread_create2(void *arg1, void *arg2) {
  for (int i = 0; i < 1000; i++) {
    lock_acquire(&mylock);
    shared_global--;
    lock_release(&mylock);
  }
  exit();
}

int main(int argc, char *argv[])
{
  lock_init(&mylock);
  thread_create(test_thread_create, (void*)0x123, (void *)0x456);
  thread_create(test_thread_create2, (void*)0xabc, (void *)0xdef);
  thread_join();
  thread_join();

  printf(1, "XV6_TEST_OUTPUT: shared_global's value: %d\n", shared_global);
  exit();
}