/* AI-style scheduler: tasks that are used more get a higher score */
#include <stdio.h>
#include <string.h>
#include "scheduler.h"

#define MAX_TASKS 8

typedef struct { char name[16]; int priority; int usage; } Task;
static Task tasks[MAX_TASKS];
static int count = 0;

void scheduler_init(void) { count = 0; }

void scheduler_add(const char *name, int priority) {
    if (count >= MAX_TASKS) return;
    strncpy(tasks[count].name, name, 15);
    tasks[count].priority = priority;
    tasks[count].usage = 0;
    count++;
}

void scheduler_run_tick(void) {
    int best = 0, best_score = -1;
    for (int i = 0; i < count; i++) {
        int score = tasks[i].priority * 2 + tasks[i].usage;  /* learns from usage */
        if (score > best_score) { best_score = score; best = i; }
    }
    tasks[best].usage++;
    printf("tick: running %s (score %d)\n", tasks[best].name, best_score);
}
