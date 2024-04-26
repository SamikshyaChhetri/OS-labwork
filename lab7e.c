// WAP in C to simulate LFU Page Replacement Algorithm
#include <stdio.h>
#include <stdbool.h>
#define MAX_FRAMES 10
#define MAX_PAGES 50

typedef struct
{
    int page_number;
    int frequency;
    bool valid;
} Page;

int findLeastFrequentPage(Page frames[], int numFrames)
{
    int pageIndex = 0;
    int minFrequency = frames[0].frequency;
    for (int i = 1; i < numFrames; i++)
    {
        if (frames[i].frequency < minFrequency)
        {
            minFrequency = frames[i].frequency;
            pageIndex = i;
        }
    }
    return pageIndex;
}

void lfuPageReplacement(int pages[], int numPages, int numFrames)
{
    Page frames[MAX_FRAMES] = {{-1, 0, true}}; // Initialize valid field to true
    int pageFaults = 0;

    for (int i = 0; i < numPages; i++)
    {
        int currentPage = pages[i];
        bool pageFound = false;

        for (int j = 0; j < numFrames; j++)
        {
            if (frames[j].page_number == currentPage)
            {
                frames[j].frequency++;
                pageFound = true;
                break;
            }
        }

        if (!pageFound)
        {
            int pageIndex = findLeastFrequentPage(frames, numFrames);
            frames[pageIndex].page_number = currentPage;
            frames[pageIndex].frequency = 1;
            frames[pageIndex].valid = true;
            pageFaults++;
        }

        printf("Page: %d\tFrames: ", currentPage);
        for (int j = 0; j < numFrames; j++)
        {
            if (!frames[j].valid)
                printf("- ");
            else
                printf("%d ", frames[j].page_number);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main()
{
    int pages[MAX_PAGES];
    int numPages, numFrames;

    printf("Enter the number of pages: ");
    scanf("%d", &numPages);

    printf("Enter the page references: ");
    for (int i = 0; i < numPages; i++)
    {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &numFrames);

    printf("\nLFU Page Replacement Algorithm\n");
    lfuPageReplacement(pages, numPages, numFrames);

    printf("Name: Samikshya Baniya Chhetri\n");
    printf("Roll no.: 03\n");
    printf("Class: BSc. CSIT, 4th sem\n");

    return 0;
}
