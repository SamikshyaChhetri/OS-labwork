// WAP to implement Bankers Algorithm for multiple type of resources to decide
//  safe/unsafe state.
#include <stdio.h>
#define MAX_PROCESSES 10
#define MAX_RESOURCES 10
int available[MAX_RESOURCES];
int maximum[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int safeSequence[MAX_PROCESSES];
int completed[MAX_PROCESSES];
int numProcesses, numResources;
void readInput()
{
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);
    printf("Enter the number of resources: ");
    scanf("%d", &numResources);
    printf("Enter the available resources:\n");
    for (int i = 0; i < numResources; i++)
    {
        scanf("%d", &available[i]);
    }
    printf("Enter the maximum resource allocation for each process:\n");
    for (int i = 0; i < numProcesses; i++)
    {
        printf("Process %d:\n", i);
        for (int j = 0; j < numResources; j++)
        {
            scanf("%d", &maximum[i][j]);
        }
    }
    printf("Enter the current resource allocation for each process:\n");
    for (int i = 0; i < numProcesses; i++)
    {
        printf("Process %d:\n", i);
        for (int j = 0; j < numResources; j++)
        {
            scanf("%d", &allocation[i][j]);
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
}
int isSafe()
{
    int work[MAX_RESOURCES];
    int finish = 0;
    // Initialize work and finish arrays
    for (int i = 0; i < numResources; i++)
    {
        work[i] = available[i];
        completed[i] = 0;
    }
    // Find a safe sequence
    int count = 0;
    while (count < numProcesses)
    {
        int found = 0;
        for (int i = 0; i < numProcesses; i++)
        {
            if (completed[i] == 0)
            {
                int j;
                for (j = 0; j < numResources; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        break;
                    }
                }
                if (j == numResources)
                {
                    for (int k = 0; k < numResources; k++)
                    {
                        work[k] += allocation[i][k];
                    }
                    safeSequence[count++] = i;
                    completed[i] = 1;
                    found = 1;
                }
            }
        }
        if (found == 0)
        {
            break;
        }
    }
    if (count == numProcesses)
    {
        return 1; // System is in a safe state
    }
    else
    {
        return 0; // System is in an unsafe state
    }
}
void displaySafeSequence()
{
    printf("Safe Sequence: ");
    for (int i = 0; i < numProcesses; i++)
    {
        printf("%d ", safeSequence[i]);
    }
    printf("\n");
}
int main()
{
    readInput();
    if (isSafe())
    {
        printf("The system is in a safe state.\n");
        displaySafeSequence();
    }
    else
    {
        printf("The system is in an unsafe state.\n");
    }
    printf("Name: Reshma Adhikaril\n");
    printf("Roll no.: 21\n");
    printf("Class : BSc.CSIT, 4th sem\n");
    return 0;
}