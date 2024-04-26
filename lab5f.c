// WAP in C to simulate Preemptive Priority Scheduling Algorithm

#include <stdio.h>
struct Process
{
    int processId;
    int arrivalTime;
    int burstTime;
    int priority;
    int remainingTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

void calculateTimes(struct Process processes[], int n)
{
    int currentTime = 0;
    int completed = 0;
    while (completed < n)
    {
        int highestPriority = 9999;
        int highestPriorityIndex = -1;
        for (int i = 0; i < n; i++)
        {
            if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime > 0 &&
                processes[i].priority < highestPriority)
            {
                highestPriority = processes[i].priority;
                highestPriorityIndex = i;
            }
        }
        if (highestPriorityIndex != -1)
        {
            processes[highestPriorityIndex].remainingTime--;
            currentTime++;
            if (processes[highestPriorityIndex].remainingTime == 0)
            {
                completed++;
                processes[highestPriorityIndex].completionTime = currentTime;
                processes[highestPriorityIndex].turnaroundTime =
                    processes[highestPriorityIndex].completionTime - processes[highestPriorityIndex].arrivalTime;
                processes[highestPriorityIndex].waitingTime =
                    processes[highestPriorityIndex].turnaroundTime - processes[highestPriorityIndex].burstTime;
            }
        }
        else
        {
            currentTime++;
        }
    }
}

void displayResult(struct Process processes[], int n)
{
    printf("Process\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].processId,
               processes[i].arrivalTime,
               processes[i].burstTime, processes[i].priority, processes[i].completionTime,
               processes[i].turnaroundTime, processes[i].waitingTime);
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
        printf("Enter priority: ");
        scanf("%d", &processes[i].priority);
        processes[i].remainingTime = processes[i].burstTime;
    }
    calculateTimes(processes, n);
    displayResult(processes, n);
    float avgWaitingTime = calculateAverageWaitingTime(processes, n);
    float avgTurnaroundTime = calculateAverageTurnaroundTime(processes, n);
    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
    printf("Name: Samikshya Baniya Chhetri\nRoll no: 03\nClass: Bsc.CSIT 4th semester ");

    return 0;
}
