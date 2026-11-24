#ifndef SCHEDULER_H
#define SCHEDULER_H
void scheduler_init(void);
void scheduler_add(const char *name, int priority);
void scheduler_run_tick(void);
#endif
