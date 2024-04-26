// WAP in C to simulate Round Robin CPU Scheduling Algorithm

#include <stdio.h>
struct Process
{
    int processId;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

void calculateTimes(struct Process processes[], int n, int timeQuantum)
{
    int remainingTime[n];
    int completed = 0;
    int currentTime = 0;

    // Initialize remainingTime array
    for (int i = 0; i < n; i++)
    {
        remainingTime[i] = processes[i].burstTime;
    }

    while (completed < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (remainingTime[i] > 0)
            {
                if (remainingTime[i] <= timeQuantum)
                {
                    currentTime += remainingTime[i];
                    remainingTime[i] = 0;
                    processes[i].completionTime = currentTime;
                    processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
                    processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
                    completed++;
                }
                else
                {
                    currentTime += timeQuantum;
                    remainingTime[i] -= timeQuantum;
                }
            }
        }
    }
}

void displayResult(struct Process processes[], int n)
{
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].processId, processes[i].arrivalTime,
               processes[i].burstTime, processes[i].completionTime, processes[i].turnaroundTime,
               processes[i].waitingTime);
    }
}

float calculateAverageWaitingTime(struct Process processes[], int n)
{
    float totalWaitingTime = 0;
    for (int i = 0; i < n; i++)
    {
        totalWaitingTime += processes[i].waitingTime;
    }
    return totalWaitingTime / n;
}

float calculateAverageTurnaroundTime(struct Process processes[], int n)
{
    float totalTurnaroundTime = 0;
    for (int i = 0; i < n; i++)
    {
        totalTurnaroundTime += processes[i].turnaroundTime;
    }
    return totalTurnaroundTime / n;
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];
    for (int i = 0; i < n; i++)
    {
        printf("Process %d\n", i + 1);
        processes[i].processId = i + 1;
        printf("Enter arrival time: ");
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burstTime);
        processes[i].remainingTime = processes[i].burstTime;
    }
    int timeQuantum;
    printf("Enter the time quantum: ");
    scanf("%d", &timeQuantum);
    calculateTimes(processes, n, timeQuantum);
    displayResult(processes, n);
    float avgWaitingTime = calculateAverageWaitingTime(processes, n);
    float avgTurnaroundTime = calculateAverageTurnaroundTime(processes, n);
    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
    printf("Name: Samikshya Baniya Chhetri\nRoll no: 03\nClass: Bsc.CSIT 4th semester ");

    return 0;
}
