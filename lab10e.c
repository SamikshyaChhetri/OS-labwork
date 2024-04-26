// WAP to simulate LOOK Disk Scheduling Algorithm

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_REQUESTS 100

void look_disk_scheduling(int requests[], int num_requests, int head_position, int num_tracks)
{
    int total_distance = 0;
    int current_position = head_position;
    bool direction_up = true;
    printf("Sequence: ");

    while (true)
    {
        // Process requests in the current direction
        for (int i = 0; i < num_requests; i++)
        {
            if (requests[i] == current_position)
            {
                total_distance += abs(requests[i] - current_position);
                printf("%d ", current_position);
            }
        }

        // Move the head to the next track
        if (direction_up)
        {
            current_position++;
            if (current_position > num_tracks)
            {
                direction_up = false;
                current_position = num_tracks - 1;
            }
        }
        else
        {
            current_position--;
            if (current_position < 0)
            {
                break;
            }
        }
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

    printf("\nLOOK Disk Scheduling\n");
    look_disk_scheduling(requests, num_requests, head_position, num_tracks);

    printf("Name: Samikshya Baniya Chhetri\n");
    printf("Rollno.: 03\n");
    printf("Class: BSc. CSIT, 4th sem");

    return 0;
}
