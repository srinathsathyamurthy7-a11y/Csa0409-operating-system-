#include <stdio.h>

int main()
{
    int n, bt[10], pr[10], rt[10], wt[10], tat[10];
    int i, time = 0, completed = 0, min, shortest;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter Burst Time and Priority of P%d: ", i + 1);
        scanf("%d%d", &bt[i], &pr[i]);
        rt[i] = bt[i];
    }

    while(completed != n)
    {
        min = 9999;
        shortest = -1;

        for(i = 0; i < n; i++)
        {
            if(rt[i] > 0 && pr[i] < min)
            {
                min = pr[i];
                shortest = i;
            }
        }

        rt[shortest]--;
        time++;

        if(rt[shortest] == 0)
        {
            completed++;
            tat[shortest] = time;
            wt[shortest] = tat[shortest] - bt[shortest];
        }
    }

    printf("\nProcess\tBT\tPriority\tWT\tTAT\n");

    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t\t%d\t%d\n", i + 1, bt[i], pr[i], wt[i], tat[i]);

    return 0;
}
