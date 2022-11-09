#include "types.h"
#include "stat.h"
#include "user.h"

int shared_global = 0;
lock_t mylock;
int global;

void test_thread_create(void *arg1, void *arg2) {

    lock_acquire(&mylock);
    printf(1, "thread's shared_global value: %d\n", * ((uint *) arg1));
    *(int *)arg1 = *(int *)arg2;

    lock_release(&mylock);

    printf(1, "thread's heap_var value: %d\n", * ((uint *) arg2));
    exit();
}

int main(int argc, char *argv[]) {
    lock_init(&mylock);
    uint *heap_var = (uint *) malloc(sizeof(uint));
    *heap_var = 9999;
    printf(1, "process's shared_global value: %d\n", shared_global);
    printf(1, "process's heap_var value: %d\n", *heap_var);
    thread_create(test_thread_create, &shared_global, heap_var);
    thread_create(test_thread_create, &shared_global, heap_var);
    thread_join();
    thread_join();
    exit();
}

// void threadfunc(void *arg1, void *arg2) {
//   for (int i = 0; i < 1000; i++) {
//     lock_acquire(&mylock);
//     shared_global++;
//     lock_release(&mylock);
//   }
//   exit();
// }

// void threadfunc2(void *arg1, void *arg2) {
//   for (int i = 0; i < 1000; i++) {
//     lock_acquire(&mylock);
//     shared_global--;
//     lock_release(&mylock);
//   }
//   exit();
// }

// int main(int argc, char *argv[])
// {
//   lock_init(&mylock);
//   thread_create(threadfunc, (void*)0x123, (void *)0x456);
//   thread_create(threadfunc2, (void*)0xabc, (void *)0xdef);
//   thread_join();
//   thread_join();

//   printf(1, "shared_global's final value: %d\n", shared_global);
//   exit();
// }


// int main(int argc, char *argv[])
// {
//   int ret = clone((void*)0xFFFF, (void*)31415, (void*)0, (void*)0);
//   printf(1, "XV6_TEST_OUTPUT : Return value of clone system call: %d\n", ret);

//   exit();
// }

// int main(int argc, char *argv[])
// {
//   int ret = join((void**)0xFFFF);
//   printf(1, "XV6_TEST_OUTPUT : Return value of join system call: %d\n", ret);
//   exit();
// }

// void threadfunc(void *arg1, void *arg2) {
//   *(int *)arg2 = (int)arg1;
//   exit();
// }

// int main(int argc, char *argv[])
// {
//   void *stack = sbrk(4096);
//   // memset(stack, 0, 4096);

//   int pid1 = clone(threadfunc, (void*)31415, (void*)0, (void *)stack);
//   int pid2 = join(&stack);

//   if(pid1 == pid2)
//   {
//     printf(1, "XV6_TEST_OUTPUT : Correct PIDs returned by clone() and join()\n");
//   }
//   else
//   {
//     printf(1, "XV6_TEST_OUTPUT : PIDs returned by clone() and join() do not match..!\n");
//   }
//   exit();
// }