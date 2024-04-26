// WAP to simulate Free Space Management using Bitmaps

#include <stdio.h>
#include <stdbool.h>

#define MAX_BLOCKS 64

void initialize_bitmap(bool bitmap[], int num_blocks)
{
    for (int i = 0; i < num_blocks; i++)
    {
        bitmap[i] = false;
    }
}

void allocate_block(bool bitmap[], int num_blocks, int block_number)
{
    if (block_number < 0 || block_number >= num_blocks)
    {
        printf("Invalid block number.\n");
        return;
    }
    bitmap[block_number] = true;
    printf("Block %d allocated successfully.\n", block_number);
}

void deallocate_block(bool bitmap[], int num_blocks, int block_number)
{
    if (block_number < 0 || block_number >= num_blocks)
    {
        printf("Invalid block number.\n");
        return;
    }
    bitmap[block_number] = false;
    printf("Block %d deallocated successfully.\n", block_number);
}

void display_bitmap(bool bitmap[], int num_blocks)
{
    printf("Bitmap:\n");
    for (int i = 0; i < num_blocks; i++)
    {
        printf("%c ", bitmap[i] ? '1' : '0');
    }
    printf("\n");
}

int main()
{
    int num_blocks;
    printf("Enter the number of blocks: ");
    scanf("%d", &num_blocks);

    bool bitmap[MAX_BLOCKS];
    initialize_bitmap(bitmap, num_blocks);

    int block_to_allocate;
    printf("Enter the block number to allocate: ");
    scanf("%d", &block_to_allocate);
    allocate_block(bitmap, num_blocks, block_to_allocate);
    display_bitmap(bitmap, num_blocks);

    int block_to_deallocate;
    printf("Enter the block number to deallocate (-1 to exit): ");
    scanf("%d", &block_to_deallocate);
    while (block_to_deallocate != -1)
    {
        deallocate_block(bitmap, num_blocks, block_to_deallocate);
        display_bitmap(bitmap, num_blocks);
        printf("Enter the block number to deallocate (-1 to exit): ");
        scanf("%d", &block_to_deallocate);
    }

    printf("Name: Samikshya Baniya Chhetri\n");
    printf("Rollno.: 03\n");
    printf("Class: BSc. CSIT, 4th sem\n");
    return 0;
}
