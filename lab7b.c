// WAP in C to simulate Optimal Page Replacement Algorithm

#include <stdio.h>
#include <stdbool.h>
#define MAX_FRAMES 10
#define MAX_PAGES 100
int findOptimalPage(int pages[], int numPages, int frames[], int numFrames, int startIndex)
{
    int index = -1;
    int farthest = startIndex;

    for (int i = 0; i < numFrames; i++)
    {
        int frame = frames[i];
        bool found = false;

        for (int j = startIndex; j < numPages; j++)
        {
            if (pages[j] == frame)
            {
                found = true;
                if (j > farthest)
                {
                    farthest = j;
                    index = i;
                }
                break;
            }
        }

        if (!found)
        {
            return i;
        }
    }

    return index;
}

void optimalPageReplacement(int pages[], int numPages, int numFrames)
{
    int frames[MAX_FRAMES];
    int pageFaults = 0;

    for (int i = 0; i < numFrames; i++)
    {
        frames[i] = -1;
    }

    for (int i = 0; i < numPages; i++)
    {
        int page = pages[i];
        bool found = false;

        for (int j = 0; j < numFrames; j++)
        {
            if (frames[j] == page)
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            int index = findOptimalPage(pages, numPages, frames, numFrames, i + 1);
            frames[index] = page;
            pageFaults++;
        }

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
    int pages[MAX_PAGES];

    printf("Enter the number of pages: ");
    scanf("%d", &numPages);

    if (numPages <= 0 || numPages > MAX_PAGES)
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

    optimalPageReplacement(pages, numPages, numFrames);

    printf("Name: Samikshya Baniya Chhetri\n");
    printf("Roll no.: 03\n");
    printf("Class : BSc.CSIT, 4th sem\n");
    return 0;
}
