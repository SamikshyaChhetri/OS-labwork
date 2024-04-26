// WAP to simulate Linked File Allocation Technique

#include <stdio.h>
#include <stdbool.h>

#define MAX_FILES 10

typedef struct
{
    int index;
    int next_block;
    bool allocated;
} File;

void initialize_files(File files[], int num_files)
{
    for (int i = 0; i < num_files; i++)
    {
        files[i].index = i;
        files[i].next_block = -1;
        files[i].allocated = false;
    }
}

bool allocate_file(File files[], int num_files, int file_index, int start_block)
{
    if (file_index < 0 || file_index >= num_files)
    {
        printf("Invalid file index.\n");
        return false;
    }
    if (files[file_index].allocated)
    {
        printf("File %d is already allocated.\n", file_index);
        return false;
    }
    files[file_index].next_block = start_block;
    files[file_index].allocated = true;
    printf("File %d allocated successfully.\n", file_index);
    return true;
}

void deallocate_file(File files[], int num_files, int file_index)
{
    if (file_index < 0 || file_index >= num_files)
    {
        printf("Invalid file index.\n");
        return;
    }
    if (!files[file_index].allocated)
    {
        printf("File %d is not allocated.\n", file_index);
        return;
    }
    files[file_index].next_block = -1;
    files[file_index].allocated = false;
    printf("File %d deallocated successfully.\n", file_index);
}

void display_files(File files[], int num_files)
{
    printf("Files:\n");
    printf("Index\tNext Block\tAllocated\n");
    for (int i = 0; i < num_files; i++)
    {
        printf("%d\t%d\t\t%s\n", files[i].index, files[i].next_block, files[i].allocated ? "Yes" : "No");
    }
}

int main()
{
    int num_files;
    printf("Enter the number of files: ");
    scanf("%d", &num_files);

    File files[MAX_FILES];
    initialize_files(files, num_files);

    int file_to_allocate, start_block;
    printf("Enter the index of the file to allocate: ");
    scanf("%d", &file_to_allocate);
    printf("Enter the starting block for file %d: ", file_to_allocate);
    scanf("%d", &start_block);
    allocate_file(files, num_files, file_to_allocate, start_block);
    display_files(files, num_files);

    int file_to_deallocate;
    printf("Enter the index of the file to deallocate (-1 to exit): ");
    scanf("%d", &file_to_deallocate);
    while (file_to_deallocate != -1)
    {
        deallocate_file(files, num_files, file_to_deallocate);
        display_files(files, num_files);
        printf("Enter the index of the file to deallocate (-1 to exit): ");
        scanf("%d", &file_to_deallocate);
    }

    printf("Name: Samikshya Baniya Chhetri\n");
    printf("Rollno.: 03\n");
    printf("Class: BSc. CSIT, 4th sem\n");

    return 0;
}
