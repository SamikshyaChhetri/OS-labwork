// WAP in C to simulate message passing concept for IPC.

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MAX_MESSAGE_SIZE 1024

struct message
{
    long mtype;
    char mtext[MAX_MESSAGE_SIZE];
};

int main()
{
    int msgid;
    struct message msg;
    key_t key;

    // Generate a unique key
    key = ftok(".", 'M');
    if (key == -1)
    {
        perror("ftok");
        exit(1);
    }

    // Create or access message queue
    msgid = msgget(key, IPC_CREAT | 0666);
    if (msgid == -1)
    {
        perror("msgget");
        exit(1);
    }

    // Send message
    msg.mtype = 1;
    strcpy(msg.mtext, "Hello message queue!");
    if (msgsnd(msgid, &msg, sizeof(struct message), 0) == -1)
    {
        perror("msgsnd");
        exit(1);
    }
    printf("Message Sent.\n");

    // Receive message
    if (msgrcv(msgid, &msg, sizeof(struct message), 1, 0) == -1)
    {
        perror("msgrcv");
        exit(1);
    }
    printf("Message received: %s\n", msg.mtext);
    printf("\nName: Samikshya Baniya\n");
    printf("Rollno.: 03\n");

    // Remove message queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1)
    {
        perror("msgctl");
        exit(1);
    }

    return 0;
}
