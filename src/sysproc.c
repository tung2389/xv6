#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "pstat.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_settickets(void) {
  /*
  edge cases:
    - No parameter
    - number of tickets <= 0
  */  
  int new_tickets;
  if (argint(0, &new_tickets) < 0) {
    return -1;
  }
  if (new_tickets <= 0) {
    return -1;
  }
  return settickets(new_tickets);
}

int
sys_getpinfo(void) {
  /*
  edge cases:
    - No parameter
    - Null ptr
  */
  struct pstat *ps;
  if (argptr(0, (char **) &ps, sizeof(struct pstat)) < 0) {
    return -1;
  }
  if (ps == NULL) {
    return -1;
  }
  return getpinfo(ps);
}

// Start of code added by Brian, Tung, and Khoi, hw5
int sys_mprotect(void){
  int addr, len;
  if (argint(0,&addr)<0 || argint(1, &len)<0){
    return -1;
  }
  if (addr < 0 || len <= 0) {
    return -1;
  }
  return mprotect((void*)addr, len);
}

int sys_munprotect(void){
  int addr, len;
  if (argint(0,&addr)<0 || argint(1, &len)<0){
    return -1;
  }
  if (addr < 0 || len <= 0) {
    return -1;
  }
  return munprotect((void*)addr, len);
}
// End of code added by Brian, Tung, and Khoi, hw5

// Start of code added by Tung, Khoi and Brian 
int
sys_clone(void) {
  void *fcn, *arg1, *arg2, *stack;
  if (argptr(0, (char **) &fcn, sizeof(void (*)(void *, void*))) < 0 ||
      argptr(1, (char **) &arg1, sizeof(void *)) < 0 ||
      argptr(2, (char **) &arg2, sizeof(void *)) < 0 ||
      argptr(3, (char **) &stack, PGSIZE) < 0 
  ) {
    return -1;
  }
  return clone(fcn, arg1, arg2, stack);
}

int sys_join(void){
  void *stack;
  if (argptr(0, (char **) &stack, sizeof(void *)) < 0){
    return -1;
  }
  return join(&stack);
}