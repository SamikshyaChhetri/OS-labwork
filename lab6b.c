/*WAP for deadlock detection in the system having multiple type of resources. The
program should list the deadlocked process in case of deadlock detection results
true*/

#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for exit()

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int allocation[MAX_PROCESSES][MAX_RESOURCES];
int maximum[MAX_PROCESSES][MAX_RESOURCES];
int available[MAX_RESOURCES];
int marked[MAX_PROCESSES];
int numProcesses, numResources;

void readInput()
{
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);
    printf("Enter the number of resources: ");
    scanf("%d", &numResources);

    printf("Enter the resource allocation matrix:\n");
    for (int i = 0; i < numProcesses; i++)
    {
        printf("Process %d:\n", i);
        for (int j = 0; j < numResources; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter the maximum resource matrix:\n");
    for (int i = 0; i < numProcesses; i++)
    {
        printf("Process %d:\n", i);
        for (int j = 0; j < numResources; j++)
        {
            scanf("%d", &maximum[i][j]);
        }
    }

    printf("Enter the available resources:\n");
    for (int i = 0; i < numResources; i++)
    {
        scanf("%d", &available[i]);
    }
}

void markUnsafe(int process)
{
    marked[process] = 1;
}

int isMarked(int process)
{
    return marked[process];
}

int isSafeState()
{
    int work[MAX_RESOURCES];
    int finish[MAX_PROCESSES] = {0}; // Initialize finish array locally

    // Initialize work array
    for (int i = 0; i < numResources; i++)
    {
        work[i] = available[i];
    }

    int count = 0;
    while (count < numProcesses)
    {
        int found = 0;

        for (int i = 0; i < numProcesses; i++)
        {
            if (!isMarked(i))
            {
                int j;
                for (j = 0; j < numResources; j++)
                {
                    if (maximum[i][j] - allocation[i][j] > work[j])
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
                    finish[i] = 1;
                    found = 1;
                    count++;
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
        for (int i = 0; i < numProcesses; i++)
        {
            if (!finish[i])
            {
                markUnsafe(i);
            }
        }
        return 0; // System is in an unsafe state
    }
}

void displayDeadlockedProcesses()
{
    printf("Deadlocked processes: ");
    int deadlock = 0;
    for (int i = 0; i < numProcesses; i++)
    {
        if (isMarked(i))
        {
            printf("%d ", i);
            deadlock = 1;
        }
    }
    if (!deadlock)
    {
        printf("None");
    }
    printf("\n");
}

int main()
{
    readInput();
    if (isSafeState())
    {
        printf("The system is in a safe state.\n");
    }
    else
    {
        printf("The system is in an unsafe state.\n");
        displayDeadlockedProcesses();
    }
    printf("Name: Samikshya Baniya Chhetri\n");
    printf("Roll no.: 03\n");
    printf("Class : BSc.CSIT, 4th sem\n");
    return 0;
}
