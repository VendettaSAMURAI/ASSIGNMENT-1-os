#include <conio.h>
#include <Stdio.h>

void main()
{
    int max;
    int i, j, n, t, p[max], bt[max], wt[max], tat[max], temp[max], compl[max];
    float awt = 0, atat = 0;

    system("cls");

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the process numbers: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    printf("Enter the burst time of the processes: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }
    // Applying Bubble sort to sort according the Burst time...
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++) // corrected variable name 'i' to 'j'
        {
            if (bt[j] > bt[j + 1])
            {
                t = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = t;

                t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;
            }
        }
    }
    printf("Process \t Burst time \t Waiting time \t Turnaround time \n");
    for (i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;
        for (j = 0; j < i; j++) // corrected variable name 'i' to 'j'
        {
            wt[i] += bt[j];
        }
        tat[i] = wt[i] + bt[i];
        awt += wt[i];
        atat += tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }
    awt /= n;
    atat /= n;
    printf("Average waiting time: %f\n", awt);
    printf("Average turnaround time: %f", atat);
    getch();
    
}