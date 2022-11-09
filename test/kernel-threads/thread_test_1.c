// Test shared memory, lock and create threads.
#include "types.h"
#include "stat.h"
#include "user.h"

uint shared_global = 99;
lock_t mylock;

void test_thread_create(void *arg1, void *arg2) {

    lock_acquire(&mylock);
    printf(1, "XV6_TEST_OUTPUT: thread's shared_global value: %d\n", * ((uint *) arg1));
    *(int *)arg2 = *(int *)arg1;

    lock_release(&mylock);

    printf(1, "XV6_TEST_OUTPUT: thread's heap_var value: %d\n", * ((uint *) arg2));
    exit();
}

int main(int argc, char *argv[]) {
    lock_init(&mylock);
    uint *heap_var = (uint *) malloc(sizeof(uint));
    *heap_var = 9999;
    printf(1, "XV6_TEST_OUTPUT: process's shared_global value: %d\n", shared_global);
    printf(1, "XV6_TEST_OUTPUT: process's heap_var value: %d\n", *heap_var);
    thread_create(test_thread_create, &shared_global, heap_var);
    thread_create(test_thread_create, &shared_global, heap_var);
    thread_join();
    thread_join();
    exit();
}