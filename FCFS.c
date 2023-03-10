#include <conio.h>
#include <stdio.h>

#define max 30

void main()
{
    int i, j, n, bt[max], at[max], wt[max], tat[max], temp[max], compl [max];
    float awt = 0, atat = 0;

    system("cls");

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time of each process:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    printf("Enter the arrival time of each process:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
    }

    // Initialize the first element of temp to 0
    temp[0] = 0;

    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");

    for (i = 0; i < n; i++)
    {
        // Calculate waiting time, turnaround time, and completion time for each process
        wt[i] = 0;
        tat[i] = 0;
        temp[i + 1] = temp[i] + bt[i];
        wt[i] = temp[i] - at[i];
        tat[i] = wt[i] + bt[i];
        compl [i] = temp[i + 1];

        // Add waiting time and turnaround time to the total
        awt += wt[i];
        atat += tat[i];

        // Print the results for the current process
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], at[i], wt[i], tat[i], compl [i]);
    }

    // Calculate the average
    awt /= n;
    atat /= n;

    printf("Average Waiting Time: %f\n", awt);
    printf("Average Turnaround Time: %f\n", atat);
    getch();
}