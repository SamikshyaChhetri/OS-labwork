// WAP in C to simulate Second Chance Page Replacement Algorithm

#include <stdio.h>
#include <stdbool.h>
#define MAX_FRAMES 10
#define MAX_PAGES 50

typedef struct
{
    int page_number;
    bool referenced;
} Page;

int findSecondChancePage(Page frames[], int numFrames, int startIndex)
{
    int pageIndex = -1;

    for (int i = startIndex; i < numFrames; i++)
    {
        if (!frames[i].referenced)
        {
            pageIndex = i;
            break;
        }
        else
        {
            frames[i].referenced = false; // Give the page a second chance
        }
    }

    if (pageIndex == -1)
    {
        // If no page without a reference bit is found, select the first one again
        pageIndex = startIndex;
    }

    return pageIndex;
}

void secondChancePageReplacement(int pages[], int numPages, int numFrames)
{
    Page frames[MAX_FRAMES] = {{-1, false}};
    int pageFaults = 0;
    int frameIndex = 0;

    for (int i = 0; i < numPages; i++)
    {
        int currentPage = pages[i];
        bool pageFound = false;

        for (int j = 0; j < numFrames; j++)
        {
            if (frames[j].page_number == currentPage)
            {
                frames[j].referenced = true; // Set reference bit
                pageFound = true;
                break;
            }
        }

        if (!pageFound)
        {
            int pageIndex = findSecondChancePage(frames, numFrames, frameIndex);
            frames[pageIndex].page_number = currentPage;
            frames[pageIndex].referenced = true;
            pageFaults++;
            frameIndex = (frameIndex + 1) % numFrames;
        }

        printf("Page: %d\tFrames: ", currentPage);
        for (int j = 0; j < numFrames; j++)
        {
            if (frames[j].page_number == -1)
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

    printf("\nSecond Chance Page Replacement Algorithm\n");
    secondChancePageReplacement(pages, numPages, numFrames);

    printf("\nName: Samikshya Baniya Chhetri\n");
    printf("Roll no.: 03\n");
    printf("Class: BSc. CSIT, 4th sem\n");

    return 0;
}
