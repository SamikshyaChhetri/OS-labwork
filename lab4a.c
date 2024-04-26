// WAP in C to simulate shared memory concept for IPC.

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h> // Added for using string functions
#define SHM_SIZE 1024

int main()
{
    int shmid;
    key_t key;
    char *shmaddr;

    // Generate a unique key
    key = ftok(".", 'R');
    if (key == -1)
    {
        perror("ftok");
        exit(1);
    }

    // Create shared memory segment
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1)
    {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment to process address space
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (char *)-1)
    {
        perror("shmat");
        exit(1);
    }

    // Write data to shared memory
    sprintf(shmaddr, "Hello! shared memory!");

    // Read data from shared memory
    printf("Data read from shared memory: %s\n", shmaddr);
    printf("\nName: Samikshya Baniya\n");
    printf("Roll no.: 03\n");

    // Detach shared memory segment from process address space
    if (shmdt(shmaddr) == -1)
    {
        perror("shmdt");
        exit(1);
    }

    // Mark the shared memory segment to be destroyed
    if (shmctl(shmid, IPC_RMID, NULL) == -1)
    {
        perror("shmctl");
        exit(1);
    }

    return 0;
}
