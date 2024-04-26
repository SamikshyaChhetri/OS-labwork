// WAP to simulate FCFS Disk Scheduling Algorithm

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // Include limits.h for INT_MAX
#define MAX_REQUESTS 100

void fcfs_disk_scheduling(int requests[], int num_requests, int head_position)
{
    int total_distance = 0;
    int current_position = head_position;
    printf("Sequence: ");
    for (int i = 0; i < num_requests; i++)
    {
        int current_request = requests[i];
        int distance = abs(current_request - current_position);
        total_distance += distance;
        current_position = current_request;
        printf("%d ", current_request);
    }
    printf("\nTotal Head Movement: %d\n", total_distance);
}

int main()
{
    int requests[MAX_REQUESTS];
    int num_requests;
    int head_position;

    printf("Enter the number of disk requests (max %d): ", MAX_REQUESTS);
    scanf("%d", &num_requests);

    if (num_requests <= 0 || num_requests > MAX_REQUESTS)
    {
        printf("Invalid number of requests. Please enter a number between 1 and %d.\n", MAX_REQUESTS);
        return 1; // Return with an error code
    }

    printf("Enter the disk requests: ");
    for (int i = 0; i < num_requests; i++)
    {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head_position);

    printf("\nFCFS Disk Scheduling\n");
    fcfs_disk_scheduling(requests, num_requests, head_position);

    printf("Name: Samikshya Baniya Chhetri\n");
    printf("Rollno.: 03\n");
    printf("Class: BSc. CSIT, 4th sem\n");

    return 0;
}
