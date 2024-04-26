// Process creation and termination

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    // Create a child process
    pid = fork();

    if (pid < 0)
    {
        // Fork failed
        fprintf(stderr, "Fork failed.\n");
        return 1;
    }
    else if (pid == 0)
    {
        // Child process
        printf("Child process created. PID: %d\n", getpid());
        // Simulate some work in the child process
        sleep(3);
        printf("Child process terminating. PID: %d\n", getpid());
        exit(0); // Terminate the child process
    }
    else
    {
        // Parent process
        printf("Parent process. PID: %d\n", getpid());
        printf("Waiting for child process to terminate...\n");
        wait(NULL); // Wait for any child process to terminate
        printf("Child process has terminated.\n");
        printf("Name: Samikshya Baniya Chhetri\nRoll no: 03\nClass: Bsc.CSIT 4th semester ");
    }

    return 0;
}
