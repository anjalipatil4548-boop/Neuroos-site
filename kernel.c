/* NeuroOS kernel (concept code, simplified for learning) */
#include <stdio.h>
#include "scheduler.h"

int main(void) {
    printf("NeuroOS kernel 0.1 started\n");
    scheduler_init();
    scheduler_add("shell", 5);
    scheduler_add("neuro-ai", 3);
    scheduler_add("backup", 1);
    for (int tick = 0; tick < 6; tick++) {
        scheduler_run_tick();
    }
    return 0;
}
