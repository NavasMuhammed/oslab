#include <stdio.h>




void sortArrival(
    
)
void find_waiting_time(int processes[], int n, int bt[], int at[], int wt[])
{
    int servicetime[n];
    servicetime[0] = at[0];
    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        servicetime[i] = servicetime[i - 1] + bt[i - 1];
        wt[i] = servicetime[i] - at[i];
        if (wt[i] < 0)
        {
            wt[i] = 0;
        }
    }
}
void turn_around_time(int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
    }
}
void findavgTime(int processes[], int n, int bt[], int at[])
{
    int wt[n], tat[n], totalwt = 0, totaltat = 0;
    float avg_wt, avg_tat;
    find_waiting_time(processes, n, bt, at, wt);
    turn_around_time(processes, n, bt, wt, tat);

    printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        totaltat = totaltat + at[i];
        printf("\t %d \t\t\t %d\t\t\t %d\t\t\t %d", processes[i], bt[i], wt[i], tat[i]);
        printf("\n");
    }
}
void main()
{
    int i, process[100], bt[100], at[100], n;
    printf("Enter number of processes");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Process no:");
        scanf("%d", &process[i]);
        printf("Burst time: ");
        scanf("%d", &bt[i]);
        printf("Arrival time: ");
        scanf("%d", &at[i]);
    }
    findavgTime(process, n, bt, at);
}