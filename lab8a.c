// WAP to simulate Contiguous File Allocation Technique
#include <stdio.h>
#include <stdbool.h>
#define MAX_BLOCKS 100
typedef struct
{
    int start_block;
    int length;
    bool allocated;
} File;

void initialize_blocks(bool blocks[], int num_blocks)
{
    for (int i = 0; i < num_blocks; i++)
    {
        blocks[i] = false;
    }
}

bool allocate_file(File files[], int num_files, bool blocks[], int num_blocks, int file_index, int file_size)
{
    int start_block = -1;
    int consecutive_blocks = 0;

    for (int i = 0; i < num_blocks; i++)
    {
        if (!blocks[i])
        {
            consecutive_blocks++;
            if (consecutive_blocks == file_size)
            {
                start_block = i - file_size + 1;
                break;
            }
        }
        else
        {
            consecutive_blocks = 0;
        }
    }

    if (start_block != -1)
    {
        files[file_index].start_block = start_block;
        files[file_index].length = file_size;
        files[file_index].allocated = true;

        for (int i = start_block; i < start_block + file_size; i++)
        {
            blocks[i] = true;
        }
        return true;
    }
    return false;
}

void deallocate_file(File files[], int num_files, bool blocks[], int num_blocks, int file_index)
{
    int start_block = files[file_index].start_block;
    int file_size = files[file_index].length;

    for (int i = start_block; i < start_block + file_size; i++)
    {
        blocks[i] = false;
    }
    files[file_index].allocated = false;
}

void display_blocks(bool blocks[], int num_blocks)
{
    printf("Blocks: ");
    for (int i = 0; i < num_blocks; i++)
    {
        printf("%c ", blocks[i] ? 'X' : '-');
    }
    printf("\n");
}

void display_files(File files[], int num_files)
{
    printf("Files:\n");
    printf("Index\tStart Block\tLength\tAllocated\n");

    for (int i = 0; i < num_files; i++)
    {
        printf("%d\t%d\t\t%d\t%s\n", i, files[i].start_block, files[i].length, files[i].allocated ? "Yes" : "No");
    }
}

int main()
{
    int num_blocks;
    bool blocks[MAX_BLOCKS];
    int num_files;
    File files[MAX_BLOCKS];

    printf("Enter the number of blocks: ");
    scanf("%d", &num_blocks);
    initialize_blocks(blocks, num_blocks);

    printf("Enter the number of files: ");
    scanf("%d", &num_files);

    for (int i = 0; i < num_files; i++)
    {
        int file_size;
        printf("Enter the size of file %d: ", i);
        scanf("%d", &file_size);

        bool allocated = allocate_file(files, num_files, blocks, num_blocks, i, file_size);
        if (allocated)
        {
            printf("File %d allocated successfully.\n", i);
        }
        else
        {
            printf("Failed to allocate file %d.\n", i);
        }
        display_blocks(blocks, num_blocks);
        display_files(files, num_files);
    }

    // Deallocate files
    int file_to_deallocate;
    printf("Enter the index of the file to deallocate (-1 to exit): ");
    scanf("%d", &file_to_deallocate);
    while (file_to_deallocate != -1)
    {
        if (file_to_deallocate >= 0 && file_to_deallocate < num_files && files[file_to_deallocate].allocated)
        {
            deallocate_file(files, num_files, blocks, num_blocks, file_to_deallocate);
            printf("File %d deallocated successfully.\n", file_to_deallocate);
        }
        else
        {
            printf("Invalid file index or file is not allocated.\n");
        }
        display_blocks(blocks, num_blocks);
        display_files(files, num_files);
        printf("Enter the index of the file to deallocate (-1 to exit): ");
        scanf("%d", &file_to_deallocate);
    }

    printf("Name: Samikshya Baniya Chhetri\n");
    printf("Roll no.: 03\n");
    printf("Class: BSc. CSIT, 4th sem\n");

    return 0;
}
