// WAP in C to simulate SJF CPU Scheduling Algorithm

#include <stdio.h>
struct Process
{
    int processId;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

void calculateTimes(struct Process processes[], int n)
{
    int remainingTime[n];
    int completed = 0;
    int currentTime = 0;
    for (int i = 0; i < n; i++)
    {
        remainingTime[i] = processes[i].burstTime;
    }
    while (completed < n)
    {
        int shortestJob = -1;
        int shortestBurst = 9999;
        for (int i = 0; i < n; i++)
        {
            if (processes[i].arrivalTime <= currentTime && remainingTime[i] < shortestBurst &&
                remainingTime[i] > 0)
            {
                shortestJob = i;
                shortestBurst = remainingTime[i];
            }
        }
        if (shortestJob == -1)
        {
            currentTime++;
            continue;
        }
        remainingTime[shortestJob]--;
        currentTime++;
        if (remainingTime[shortestJob] == 0)
        {
            processes[shortestJob].completionTime = currentTime;
            processes[shortestJob].turnaroundTime = processes[shortestJob].completionTime -
                                                    processes[shortestJob].arrivalTime;
            processes[shortestJob].waitingTime = processes[shortestJob].turnaroundTime -
                                                 processes[shortestJob].burstTime;
            completed++;
        }
    }
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
    }

    calculateTimes(processes, n);
    float avgWaitingTime = calculateAverageWaitingTime(processes, n);
    float avgTurnaroundTime = calculateAverageTurnaroundTime(processes, n);
    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
    printf("Name: Samikshya Baniya Chhetri\nRoll no: 03\nClass: Bsc.CSIT 4th semester ");

    return 0;
}
