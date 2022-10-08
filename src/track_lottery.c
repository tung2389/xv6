#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"
#include "param.h"

void busy() {
    while (1) {
        long s = 0;
        for (long i = 0; i < 0x7fffffff; i++) {
            s = (s + i) % 0x7fffffff;
        }
    };
} 

int
main(int argc, char *argv[]) {
    int pids[3];
    int tickets[3] = {10, 20, 30};

    for (int i = 0; i < 3; i++) {
        settickets(tickets[i]);
        pids[i] = fork();
        // Child process
        if (pids[i] == 0) {
            busy();
        }
    }

    struct pstat ps;
    int time = 0;

    while (time < 100) {
        if (getpinfo(&ps) < 0) {
            break;
        }
        for (int i = 0; i < 3; i++) {
            int pid = pids[i];
            for (int j = 0; j < NPROC; j++) {
                if (ps.pid[j] == pid) {
                    printf(1, "%d", ps.ticks[j]);
                    if (i < 2) {
                        printf(1, ",");
                    }
                    break;
                }
            }
        }
        printf(1, "\n");
        time += 1;
        sleep(30);
    }

    for (int i = 0; i < 3; i++) {
        kill(pids[i]);
    }
    for (int i = 0; i < 3; i++) {
        wait();
    }
    exit();
}