#include <stdio.h>
#include <malloc.h>

typedef struct Queue
{
  int rearIdx;
  int capacity;
  int * data;
}Queue;

Queue * createQueue(int capacity);
void enqueue(Queue * queue, int data);
void dequeue(Queue * queue);
int front(Queue * queue);
int isEmpty(Queue * queue);
void print(Queue * queue);

int main(void)
{
  Queue * queue = createQueue(5); 
  enqueue(queue, 10);
  enqueue(queue, 11);
  enqueue(queue, 12);
  enqueue(queue, 13);
  enqueue(queue, 14);
  dequeue(queue);
  enqueue(queue, 16);
  print(queue);
  return 0;
}


Queue * createQueue(int capacity)
{
  Queue * newQueue = (Queue *)malloc(sizeof(Queue));
  newQueue->rearIdx = -1;
  newQueue->data = (int *)malloc(sizeof(int) * capacity);
  newQueue->capacity = capacity;
  return newQueue;
}

void enqueue(Queue * queue, int data)
{
  if (queue->rearIdx == queue->capacity - 1)
  {
    printf("Overflow!\n");
    return;
  }
  queue->data[++queue->rearIdx] = data;
}
void dequeue(Queue * queue)
{
  if (isEmpty(queue))
  {
    return;
  }
  for (int queueIdx = 0; queueIdx < queue->rearIdx; queueIdx++)
  {
    queue->data[queueIdx] = queue->data[queueIdx + 1];
  }
  queue->rearIdx--;
}

int front(Queue * queue)
{
  if (isEmpty(queue))
  {
    return 0xDEAD;
  }
  return queue->data[queue->rearIdx];
}
int isEmpty(Queue * queue)
{
  return (queue->rearIdx == -1) ? 1 : 0;
}

void print(Queue * queue)
{
  if (isEmpty(queue))
  {
    printf("Queue is empty\n");
    return;
  }
  printf("Queue: ");
  for (int queueSize = 0; queueSize <= queue->rearIdx; queueSize++)
  {
    printf("%d ", queue->data[queueSize]);
  }
  printf("\n");
}
