#include <stdio.h>

int pid[10], bt[10], arivt[10];
int n, i, wt[10], ct[10], tat[10];
int total_wt = 0;
int total_tat = 0;
float avg_wt, avg_tat;

int main() {
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("\nEnter process ids for all processes: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &pid[i]);
    }
    printf("Enter burst time for all processes: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }
    printf("Enter arrival time for all processes: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arivt[i]);
    }
    for (i = 0; i < n; i++) {
        ct[i] = 0;
    }
    for (i = 0; i < n; i++) {
        tat[i] = 0;
    }
    ct[0] = bt[0];
    for (i = 1; i < n; i++) {
        if (arivt[i] == 0) {
            ct[i] = bt[i];
        }
        if (ct[i - 1] >= arivt[i]) {
            ct[i] = ct[i - 1] + bt[i];
        }
        if (ct[i - 1] < arivt[i]) { //under idle time condition
            ct[i] = arivt[i] + bt[i];
        }
    }
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - arivt[i];
        total_tat += tat[i];
    }
    for (i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
        total_wt += wt[i];
    }
    avg_tat = (float)total_tat / n;
    avg_wt = (float)total_wt / n;

    // Print TAT and WT for each process
    printf("Turn Around Time     Waiting Time for each process\n");
    for (i = 0; i < n; i++) {
        printf("%d \t\t\t %d\n", tat[i], wt[i]);
    }
    printf("\nAverage TAT: %f\n", avg_tat);
    printf("Average WT: %f\n", avg_wt);
}
