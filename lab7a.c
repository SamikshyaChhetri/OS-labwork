// WAP in C to simulate FIFO Page Replacement Algorithm

#include <stdio.h>
#define MAX_FRAMES 10
void fifoPageReplacement(int pages[], int numPages, int numFrames)
{
    int frames[MAX_FRAMES];
    int pageFaults = 0;
    int nextFrameIndex = 0;

    // Initialize frames with -1
    for (int i = 0; i < numFrames; i++)
    {
        frames[i] = -1;
    }

    // Simulate page replacement
    for (int i = 0; i < numPages; i++)
    {
        int page = pages[i];
        int found = 0;

        // Check if page is already in a frame
        for (int j = 0; j < numFrames; j++)
        {
            if (frames[j] == page)
            {
                found = 1;
                break;
            }
        }

        // If page is not found, replace the oldest page in the frame
        if (!found)
        {
            frames[nextFrameIndex] = page;
            nextFrameIndex = (nextFrameIndex + 1) % numFrames;
            pageFaults++;
        }

        // Print the current state of frames
        printf("Page %d: ", page);
        for (int j = 0; j < numFrames; j++)
        {
            if (frames[j] == -1)
            {
                printf("- ");
            }
            else
            {
                printf("%d ", frames[j]);
            }
        }
        printf("\n");
    }
    printf("Total Page Faults: %d\n", pageFaults);
}

int main()
{
    int numPages, numFrames;
    int pages[MAX_FRAMES];

    printf("Enter the number of pages: ");
    scanf("%d", &numPages);

    if (numPages <= 0 || numPages > MAX_FRAMES)
    {
        printf("Invalid number of pages.\n");
        return 1; // Exit with error
    }

    printf("Enter the page reference string:\n");
    for (int i = 0; i < numPages; i++)
    {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &numFrames);

    if (numFrames <= 0 || numFrames > MAX_FRAMES)
    {
        printf("Invalid number of frames.\n");
        return 1; // Exit with error
    }

    fifoPageReplacement(pages, numPages, numFrames);

    printf("Name: Samikshya Baniya Chhetri\n");
    printf("Roll no.: 03\n");
    printf("Class : BSc.CSIT, 4th sem\n");
    return 0;
}
