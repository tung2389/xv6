# XV6 OS

## New features:
- ```getreadcount``` system call.
- Lottery scheduler.
- Prevent null pointer dereference. 
- ```mprotect``` and ```munprotect``` system calls to marked pages as read-only and unmarked pages.
- kernel threads using ```thread_create``` and ```thread_join```.
- ticket lock with ```lock_init```, ```lock_acquire``` and ```lock_release```.

## Testing
- To test getreadcount:
```
./test-getreadcount.sh
```
- To test null pointer dereference, mprotect and munprotect:
```
./test-vm.sh
```
- To test kernel threads:
```
./test-kernel-threads.sh
```