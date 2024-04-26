// WAP to simulate C-SCAN Disk Scheduling Algorithm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_REQUESTS 100

void cscan_disk_scheduling(int requests[], int num_requests, int head_position, int num_tracks)
{
    int total_distance = 0;
    int current_position = head_position;
    printf("Sequence: ");

    // Move the head to the end of the disk
    for (int track = current_position; track <= num_tracks; track++)
    {
        for (int i = 0; i < num_requests; i++)
        {
            if (requests[i] == track)
            {
                total_distance += abs(requests[i] - current_position);
                current_position = requests[i];
                printf("%d ", current_position);
            }
        }
    }

    // Move the head to the beginning of the disk
    total_distance += num_tracks - current_position;
    current_position = 0;
    printf("0 ");

    // Move the head to the requested tracks in ascending order
    for (int track = 1; track <= head_position; track++)
    {
        for (int i = 0; i < num_requests; i++)
        {
            if (requests[i] == track)
            {
                total_distance += abs(requests[i] - current_position);
                current_position = requests[i];
                printf("%d ", current_position);
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

    printf("Enter the total number of tracks on the disk: ");
    scanf("%d", &num_tracks);

    printf("\nC-SCAN Disk Scheduling\n");
    cscan_disk_scheduling(requests, num_requests, head_position, num_tracks);

    printf("Name: Samikshya Baniya Chhetri\n");
    printf("Rollno.: 03\n");
    printf("Class: BSc. CSIT, 4th sem\n");

    return 0;
}
