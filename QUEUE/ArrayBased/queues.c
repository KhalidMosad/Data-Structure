#include<stdio.h>
#include"queues.h"

void CreateQueue(Queue * pq)
{
    pq->front = 0;
    pq->rear= -1 ; 
    pq->size = 0;
}

void Append (QueueEntry e, Queue * pq)
{
   if(pq->rear == MAXQueue-1)
   {
       pq->rear =0 ; 
   }
   else
   {
      pq->rear ++ ;   
   }
// or          pq->rear = (pq->rear + 1 )% MAXQueue

    pq->entry[pq->rear]= e;
    pq->size ++ ;
}
void Serve (QueueEntry* pe, Queue * pq)
{
    *pe = pq->entry[pq->front];
    pq->front = ( pq->front + 1 )% MAXQueue;
    pq->size --;

}
int QueueEmpty(Queue *pq)
{
    return ! pq->size;

}

int QueueFull(Queue *pq)
{
    return (pq->size == MAXQueue); 
}
int QueueSize(Queue * pq)
{
    return pq->size ;
}

void ClearQueue(Queue * pq)
{
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0 ; 

}


void TraverseQueue(Queue*pq, void (*ptf)(QueueEntry))
{
    //while(pq->front != pq->rear+1)
    /*
    for(int pos =pq->front;  pos<= pq->rear ; pos += (( pq->front + 1 )% MAXQueue) )
    {
        (*ptf)(pq->entry[pos]);
        
    }*/

    while(pq->front != pq->rear+1)
    {
        printf("Khalid");
        (*ptf)(pq->entry[pq->front]);
        pq->front= ( pq->front + 1 )% MAXQueue;
        
    }

}