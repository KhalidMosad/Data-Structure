
typedef int QueueEntry; 
#define MAXQueue  100

typedef struct queue
{
   int front;
   int rear;
   int size;
   QueueEntry entry[MAXQueue];
   
}Queue;

void CreateQueue(Queue * pq);
void Append (QueueEntry e, Queue * pq);
void Serve (QueueEntry* pe, Queue * pq);
int QueueEmpty(Queue *pq);
int QueueFull(Queue *pq);
int QueueSize(Queue * pq);
void ClearQueue(Queue * pq);
void TraverseQueue(Queue*pq, void (*ptf)(QueueEntry));