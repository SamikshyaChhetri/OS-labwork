// WAP to simulate Free Space Management using Linked List

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // Include <stdlib.h> for malloc

#define MAX_BLOCKS 64

typedef struct Node
{
    int block_number;
    struct Node *next;
} Node;

void initialize_list(Node **head)
{
    *head = NULL;
}

bool insert_node(Node **head, int block_number)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return false;
    }
    new_node->block_number = block_number;
    new_node->next = NULL;
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
    return true;
}

bool remove_node(Node **head, int block_number)
{
    if (*head == NULL)
    {
        return false;
    }
    Node *current = *head;
    Node *prev = NULL;
    while (current != NULL)
    {
        if (current->block_number == block_number)
        {
            if (prev == NULL)
            {
                *head = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            free(current);
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

void display_list(Node *head)
{
    printf("Linked List: ");
    Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->block_number);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    int num_blocks;
    Node *head = NULL;
    printf("Enter the number of blocks: ");
    scanf("%d", &num_blocks);
    initialize_list(&head);
    int block_to_allocate;
    printf("Enter the block number to allocate: ");
    scanf("%d", &block_to_allocate);
    if (insert_node(&head, block_to_allocate))
    {
        display_list(head);
    }
    int block_to_deallocate;
    printf("Enter the block number to deallocate (-1 to exit): ");
    scanf("%d", &block_to_deallocate);
    while (block_to_deallocate != -1)
    {
        if (remove_node(&head, block_to_deallocate))
        {
            printf("Block %d deallocated successfully.\n", block_to_deallocate);
        }
        else
        {
            printf("Block %d not found.\n", block_to_deallocate);
        }
        display_list(head);
        printf("Enter the block number to deallocate (-1 to exit): ");
        scanf("%d", &block_to_deallocate);
    }
    printf("Name: Samikshya Baniya Chhetri\n");
    printf("Rollno.: 03\n");
    printf("Class: BSc. CSIT, 4th sem\n");
    return 0;
}
