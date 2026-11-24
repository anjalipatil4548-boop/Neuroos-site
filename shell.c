/* NeuroOS shell demo: reads commands and runs them */
#include <stdio.h>
#include <string.h>

int main(void) {
    char line[128];
    printf("neuro-sh 0.1 (type help, exit to quit)\n");
    while (1) {
        printf("neuro@os:~$ ");
        if (!fgets(line, sizeof line, stdin)) break;
        line[strcspn(line, "\n")] = 0;
        if (strcmp(line, "exit") == 0) break;
        else if (strcmp(line, "help") == 0) printf("help, about, exit\n");
        else if (strcmp(line, "about") == 0) printf("NeuroOS 0.1 - AI learning OS\n");
        else if (line[0]) printf("command not found: %s\n", line);
    }
    return 0;
}
