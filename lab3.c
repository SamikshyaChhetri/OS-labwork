// Thread Creation and termination
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Function to be executed by the thread
void *thread_function(void *arg)
{
    printf("Thread created. Thread ID: %lu\n", (unsigned long)pthread_self());
    // Simulate some work in the thread
    sleep(3);
    printf("Thread terminating. Thread ID: %lu\n", (unsigned long)pthread_self());
    pthread_exit(NULL); // Terminate the thread
}

int main()
{
    pthread_t thread_id;

    // Create a thread
    if (pthread_create(&thread_id, NULL, thread_function, NULL) != 0)
    {
        fprintf(stderr, "Thread creation failed.\n");
        return 1;
    }

    printf("Main thread. Thread ID: %lu\n", (unsigned long)pthread_self());

    // Wait for the thread to terminate
    if (pthread_join(thread_id, NULL) != 0)
    {
        fprintf(stderr, "Thread join failed.\n");
        return 1;
    }

    printf("Thread has terminated.\n");
    printf("Name: Samikshya Baniya Chhetri\nRoll no: 03\nClass: Bsc.CSIT 4th semester ");

    return 0;
}
