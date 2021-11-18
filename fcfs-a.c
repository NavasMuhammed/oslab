#include <stdio.h>

int main()
{
    // Inputting the values
    int n, wt[100], tat[100], at[100], bt[100], temp[100];
    float total_wt, total_tat;

    printf("enter no of processes:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("enter no of burst:");
        scanf("%d", &bt[i]);
        printf("enter no of arrival:");
        scanf("%d", &at[i]);
    }

    // Finding the wait time and tat 
    wt[0] = 0;
    tat[0] = bt[0];
    temp[0] = bt[0];

    for(int i = 0; i < n; ++i)
    {
        temp[i] = bt[i] + temp[i - 1];
        wt[i] = temp[i - 1] - at[i]; 
        tat[i] = bt[i] + wt[i];    
    }

    printf("process   arrival     burst   turn    wait");
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        
        printf("%d\t", i + 1);
        printf("%d\t\t", at[i]);
        printf("%d\t\t", bt[i]);
        printf("%d\t\t", tat[i]);
        printf("%d\t\t", wt[i]);
        printf("\n");
    }

    return 0;
}