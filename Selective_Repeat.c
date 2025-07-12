#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int tf, ws, ack = 0, i = 0;
    srand(time(NULL));
    printf("Enter Total no of Frames: ");
    scanf("%d", &tf);
    printf("Enter Window Size: ");
    scanf("%d", &ws);

    while (i < tf)
    {
        for (int j = 0; j < ws && i + j < tf; j++)
        {
            if (!(ack & (1 << (i + j))))
            {
                printf("Sending frame [%d].....", i + j);
                if (rand() % 2)
                {
                    printf("Received \n");
                    ack |= (1 << (i + j));
                }
                else
                {
                    printf("Lost (Resending)\n");
                }
            }
        }
        while (ack & (1 << i))
            i++;
    }
    printf("All frames are sent & Acknowledged.");
    return 0;
}