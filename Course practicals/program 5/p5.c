#include <stdio.h>

int main()
{
    int n, bt[10], pr[10], wt[10], tat[10], p[10];
    int i, j, temp;
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        p[i] = i + 1;
        printf("Enter Burst Time and Priority of P%d: ", i + 1);
        scanf("%d%d", &bt[i], &pr[i]);
    }

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(pr[i] > pr[j])
            {
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    wt[0] = 0;

    for(i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    printf("\nProcess\tBT\tPriority\tWT\tTAT\n");

    for(i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
        awt += wt[i];
        atat += tat[i];
        printf("P%d\t%d\t%d\t\t%d\t%d\n", p[i], bt[i], pr[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", awt / n);
    printf("\nAverage Turnaround Time = %.2f", atat / n);

    return 0;
}
