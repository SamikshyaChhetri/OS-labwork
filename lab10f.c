// WAP to simulate C-LOOK Disk Scheduling Algorithm

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_REQUESTS 100

void clook_disk_scheduling(int requests[], int num_requests, int head_position, int num_tracks)
{
    int total_distance = 0;
    int current_position = head_position;
    printf("Sequence: ");

    // Find the index of the first request greater than or equal to the current position
    int start_index = 0;
    for (int i = 0; i < num_requests; i++)
    {
        if (requests[i] >= current_position)
        {
            start_index = i;
            break;
        }
    }

    // Process requests in the right direction
    for (int i = start_index; i < num_requests; i++)
    {
        total_distance += abs(requests[i] - current_position);
        current_position = requests[i];
        printf("%d ", current_position);
    }

    // Process requests in the left direction (from beginning to start_index - 1)
    for (int i = 0; i < start_index; i++)
    {
        total_distance += abs(requests[i] - current_position);
        current_position = requests[i];
        printf("%d ", current_position);
    }

    printf("\nTotal Head Movement: %d\n", total_distance);
}

int main()
{
    int requests[MAX_REQUESTS];
    int num_requests;
    int head_position;
    int num_tracks;

    printf("Enter the number of disk requests: ");
    scanf("%d", &num_requests);

    printf("Enter the disk requests: ");
    for (int i = 0; i < num_requests; i++)
    {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head_position);

    printf("Enter the total number of tracks on the disk: ");
    scanf("%d", &num_tracks);

    printf("\nC-LOOK Disk Scheduling\n");
    clook_disk_scheduling(requests, num_requests, head_position, num_tracks);

    printf("Name: Samikshya Baniya Chhetri\n");
    printf("Rollno.: 03\n");
    printf("Class: BSc. CSIT, 4th sem");

    return 0;
}
