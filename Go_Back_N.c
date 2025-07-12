#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int total_fr, window_sz, base = 0;
    srand(time(NULL));
    printf("Enter Total no of frames: ");
    scanf("%d", &total_fr);
    printf("Enter Window Size : ");
    scanf("%d", &window_sz);
    while (base < total_fr)
    {
        int end = (base + window_sz > total_fr) ? total_fr : base + window_sz;
        printf("Sending frames");
        for (int i = base; i < end; i++)
            printf("[%d]", i);
        int ack = base + rand() % (end - base);
        printf("\n Ack received up to frame %d\n", ack);
        if (ack + 1 == end)
        {
            base = end;
            printf("All frames ack. \n");
        }
        else
        {
            base = ack + 1;
            printf("Timeout/Error!...Resending from %d \n",base);
        }
    }
    printf("All frames are sent and acknowledged succesfully.\n");
    return 0;
}