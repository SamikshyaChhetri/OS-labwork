// WAP to simulate SSTF Disk Scheduling Algorithm

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_REQUESTS 100

int find_closest_request(int requests[], bool visited[], int num_requests, int current_position)
{
    int min_distance = INT_MAX;
    int closest_request = -1;
    for (int i = 0; i < num_requests; i++)
    {
        if (!visited[i])
        {
            int distance = abs(requests[i] - current_position);
            if (distance < min_distance)
            {
                min_distance = distance;
                closest_request = i;
            }
        }
    }
    return closest_request;
}

void sstf_disk_scheduling(int requests[], int num_requests, int head_position)
{
    bool visited[MAX_REQUESTS] = {false};
    int total_distance = 0;
    int current_position = head_position;

    printf("Sequence: ");
    for (int i = 0; i < num_requests; i++)
    {
        int closest_request = find_closest_request(requests, visited, num_requests, current_position);
        visited[closest_request] = true;
        int distance = abs(requests[closest_request] - current_position);
        total_distance += distance;
        current_position = requests[closest_request];
        printf("%d ", current_position);
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

    printf("\nSSTF Disk Scheduling\n");
    sstf_disk_scheduling(requests, num_requests, head_position);

    printf("Name: Samikshya Baniya Chhetri\n");
    printf("Rollno.: 03\n");
    printf("Class: BSc. CSIT, 4th sem\n");

    return 0;
}
