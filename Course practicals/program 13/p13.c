#include <stdio.h>

void firstFit(int block[], int m, int process[], int n) {
    int allocation[n], i, j;

    for (i = 0; i < n; i++)
        allocation[i] = -1;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (block[j] >= process[i]) {
                allocation[i] = j;
                block[j] -= process[i];
                break;
            }
        }
    }

    printf("\nFirst Fit:\n");
    for (i = 0; i < n; i++) {
        if (allocation[i] != -1)
            printf("Process %d -> Block %d\n", i + 1, allocation[i] + 1);
        else
            printf("Process %d -> Not Allocated\n", i + 1);
    }
}

void bestFit(int block[], int m, int process[], int n) {
    int allocation[n], i, j, best;

    for (i = 0; i < n; i++)
        allocation[i] = -1;

    for (i = 0; i < n; i++) {
        best = -1;

        for (j = 0; j < m; j++) {
            if (block[j] >= process[i]) {
                if (best == -1 || block[j] < block[best])
                    best = j;
            }
        }

        if (best != -1) {
            allocation[i] = best;
            block[best] -= process[i];
        }
    }

    printf("\nBest Fit:\n");
    for (i = 0; i < n; i++) {
        if (allocation[i] != -1)
            printf("Process %d -> Block %d\n", i + 1, allocation[i] + 1);
        else
            printf("Process %d -> Not Allocated\n", i + 1);
    }
}

void worstFit(int block[], int m, int process[], int n) {
    int allocation[n], i, j, worst;

    for (i = 0; i < n; i++)
        allocation[i] = -1;

    for (i = 0; i < n; i++) {
        worst = -1;

        for (j = 0; j < m; j++) {
            if (block[j] >= process[i]) {
                if (worst == -1 || block[j] > block[worst])
                    worst = j;
            }
        }

        if (worst != -1) {
            allocation[i] = worst;
            block[worst] -= process[i];
        }
    }

    printf("\nWorst Fit:\n");
    for (i = 0; i < n; i++) {
        if (allocation[i] != -1)
            printf("Process %d -> Block %d\n", i + 1, allocation[i] + 1);
        else
            printf("Process %d -> Not Allocated\n", i + 1);
    }
}

int main() {
    int m, n, i;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    int block[m], b1[m], b2[m];

    printf("Enter block sizes:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &block[i]);
        b1[i] = block[i];
        b2[i] = block[i];
    }

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int process[n];

    printf("Enter process sizes:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &process[i]);

    firstFit(block, m, process, n);
    bestFit(b1, m, process, n);
    worstFit(b2, m, process, n);

    return 0;
}
