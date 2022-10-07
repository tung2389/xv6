#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"
#include "param.h"

int
main(int argc, char *argv[]) {
    struct pstat ps;
    int rc = getpinfo(&ps);
    printf(1, "Return code: %d \n", rc);
    for (int i = 0; i < NPROC; i++) {
        printf(1, "%d %d %d %d \n", ps.inuse[i], ps.tickets[i], ps.pid[i], ps.ticks[i]);
    }
    exit();
}