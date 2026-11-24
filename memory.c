/* NeuroOS memory manager demo: simple block allocator */
#include <stdio.h>

#define TOTAL_BLOCKS 16          /* 16 blocks x 128 KB = 2048 KB */
static int used[TOTAL_BLOCKS];

int mem_alloc(int blocks) {
    int run = 0;
    for (int i = 0; i < TOTAL_BLOCKS; i++) {
        run = used[i] ? 0 : run + 1;
        if (run == blocks) {
            int start = i - blocks + 1;
            for (int j = start; j <= i; j++) used[j] = 1;
            return start;
        }
    }
    return -1;                   /* out of memory */
}

void mem_free(int start, int blocks) {
    for (int i = start; i < start + blocks; i++) used[i] = 0;
}

void mem_status(void) {
    int n = 0;
    printf("[");
    for (int i = 0; i < TOTAL_BLOCKS; i++) { printf(used[i] ? "#" : "."); n += used[i]; }
    printf("] %d/%d blocks used\n", n, TOTAL_BLOCKS);
}

int main(void) {
    int a = mem_alloc(4), b = mem_alloc(6);
    printf("shell got block %d, neuro-ai got block %d\n", a, b);
    mem_status();
    mem_free(a, 4);
    mem_status();
    return 0;
}
