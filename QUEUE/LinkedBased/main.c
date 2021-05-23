#include<stdio.h>
#include<stdlib.h>
#include"queues.h"

void Display(QueueEntry e)
{
    printf("e is: %d \n",e);
}

void main()
{
    Queue q;
    QueueEntry  e;
    int size;
    CreateQueue(&q);

    for (int i=0; i<5; i++)
    {
        scanf("%d",&e);
        if (!QueueFull(&q))
            Append(e, &q);
    }
    TraverseQueue(&q, &Display);
}


