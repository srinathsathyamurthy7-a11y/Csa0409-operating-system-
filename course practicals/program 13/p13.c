#include <stdio.h>

int main()
{
    int block[10], process[10];
    int nb, np;

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    printf("Enter block sizes:\n");
    for(int i=0; i<nb; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &np);

    printf("Enter process sizes:\n");
    for(int i=0; i<np; i++)
        scanf("%d", &process[i]);

    printf("\nFirst Fit Allocation\n");

    for(int i=0; i<np; i++)
    {
        int allocated = 0;
        for(int j=0; j<nb; j++)
        {
            if(block[j] >= process[i])
            {
                printf("Process %d (%d KB) -> Block %d\n", i+1, process[i], j+1);
                block[j] -= process[i];
                allocated = 1;
                break;
            }
        }

        if(!allocated)
            printf("Process %d (%d KB) -> Not Allocated\n", i+1, process[i]);
    }

    return 0;
}
