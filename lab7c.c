// WAP in C to simulate LRU Page Replacement Algorithm
#include <stdio.h>
#include <stdbool.h>
#define MAX_FRAMES 10
#define MAX_PAGES 50

int findLeastRecentlyUsedPage(int pages[], int numPages, int frames[], int numFrames, int startIndex)
{
    int pageIndex = -1;
    int leastRecentlyUsedIndex = startIndex;

    for (int i = 0; i < numFrames; i++)
    {
        int currentPage = frames[i];
        bool found = false;

        for (int j = startIndex; j >= 0; j--)
        {
            if (pages[j] == currentPage)
            {
                found = true;
                if (j < leastRecentlyUsedIndex)
                {
                    leastRecentlyUsedIndex = j;
                    pageIndex = i;
                }
                break;
            }
        }

        if (!found)
            return i;
    }

    return pageIndex;
}

void lruPageReplacement(int pages[], int numPages, int numFrames)
{
    int frames[MAX_FRAMES] = {-1};
    int pageFaults = 0;

    for (int i = 0; i < numPages; i++)
    {
        int currentPage = pages[i];
        bool pageFound = false;

        for (int j = 0; j < numFrames; j++)
        {
            if (frames[j] == currentPage)
            {
                pageFound = true;
                break;
            }
        }

        if (!pageFound)
        {
            int pageIndex = findLeastRecentlyUsedPage(pages, numPages, frames, numFrames, i - 1);
            frames[pageIndex] = currentPage;
            pageFaults++;
        }

        printf("Page: %d\tFrames: ", currentPage);
        for (int j = 0; j < numFrames; j++)
        {
            if (frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
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

    printf("\nLRU Page Replacement Algorithm\n");
    lruPageReplacement(pages, numPages, numFrames);

    printf("\nName: Samikshya Baniya Chhetri\n");
    printf("Roll no.: 03\n");
    printf("Class: BSc. CSIT, 4th sem\n");

    return 0;
}
