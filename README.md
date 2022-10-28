# XV6 OS

## New features:
- getreadcount system call.
- Lottery scheduler.
- Prevent null pointer dereference. 
- mprotect and munprotect system calls to marked pages as read-only and unmarked pages.

## Testing
- To test getreadcount:
```
./test-getreadcount.sh
```
- To test null pointer dereference, mprotect and munprotect:
```
./test-vm.sh
```