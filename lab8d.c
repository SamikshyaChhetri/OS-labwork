// WAP to implement File Allocation using Inode

#include <stdio.h>
#include <stdbool.h>

#define MAX_FILES 10

typedef struct
{
    int index;
    bool allocated;
    int block_numbers[10];
} Inode;

void initialize_inodes(Inode inodes[], int num_inodes)
{
    for (int i = 0; i < num_inodes; i++)
    {
        inodes[i].index = i;
        inodes[i].allocated = false;
        for (int j = 0; j < 10; j++)
        {
            inodes[i].block_numbers[j] = -1;
        }
    }
}

bool allocate_file(Inode inodes[], int num_inodes, int file_index, int block_numbers[], int num_blocks)
{
    if (file_index < 0 || file_index >= num_inodes)
    {
        printf("Invalid file index.\n");
        return false;
    }

    if (inodes[file_index].allocated)
    {
        printf("File %d is already allocated.\n", file_index);
        return false;
    }

    if (num_blocks > 10)
    {
        printf("Cannot allocate file %d. Exceeds maximum block limit.\n", file_index);
        return false;
    }

    for (int i = 0; i < num_blocks; i++)
    {
        inodes[file_index].block_numbers[i] = block_numbers[i];
    }

    inodes[file_index].allocated = true;
    printf("File %d allocated successfully.\n", file_index);
    return true;
}

void deallocate_file(Inode inodes[], int num_inodes, int file_index)
{
    if (file_index < 0 || file_index >= num_inodes)
    {
        printf("Invalid file index.\n");
        return;
    }

    if (!inodes[file_index].allocated)
    {
        printf("File %d is not allocated.\n", file_index);
        return;
    }

    inodes[file_index].allocated = false;
    for (int i = 0; i < 10; i++)
    {
        inodes[file_index].block_numbers[i] = -1;
    }

    printf("File %d deallocated successfully.\n", file_index);
}

void display_inodes(Inode inodes[], int num_inodes)
{
    printf("Inodes:\n");
    printf("Index\tAllocated\tBlock Numbers\n");
    for (int i = 0; i < num_inodes; i++)
    {
        printf("%d\t%s\t\t", inodes[i].index, inodes[i].allocated ? "Yes" : "No");
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", inodes[i].block_numbers[j]);
        }
        printf("\n");
    }
}

int main()
{
    int num_inodes;
    Inode inodes[MAX_FILES];

    printf("Enter the number of inodes: ");
    scanf("%d", &num_inodes);

    initialize_inodes(inodes, num_inodes);

    int file_to_allocate, num_blocks;
    int block_numbers[10];

    printf("Enter the index of the file to allocate: ");
    scanf("%d", &file_to_allocate);

    printf("Enter the number of blocks for file %d: ", file_to_allocate);
    scanf("%d", &num_blocks);

    if (num_blocks <= 0 || num_blocks > 10)
    {
        printf("Invalid number of blocks.\n");
        return 1;
    }

    printf("Enter the block numbers for file %d: ", file_to_allocate);
    for (int i = 0; i < num_blocks; i++)
    {
        scanf("%d", &block_numbers[i]);
    }

    allocate_file(inodes, num_inodes, file_to_allocate, block_numbers, num_blocks);
    display_inodes(inodes, num_inodes);

    int file_to_deallocate;
    printf("Enter the index of the file to deallocate (-1 to exit): ");
    scanf("%d", &file_to_deallocate);

    while (file_to_deallocate != -1)
    {
        deallocate_file(inodes, num_inodes, file_to_deallocate);
        display_inodes(inodes, num_inodes);

        printf("Enter the index of the file to deallocate (-1 to exit): ");
        scanf("%d", &file_to_deallocate);
    }

    printf("Name: Samikshya Baniya Chhetri\n");
    printf("Rollno.: 03\n");
    printf("Class: BSc. CSIT, 4th sem\n");

    return 0;
}
