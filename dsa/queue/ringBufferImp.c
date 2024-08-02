#include <stdio.h>
#include <malloc.h>

typedef struct Queue
{
  int frontIdx;
  int rearIdx;
  int capacity;
  int * data;
}Queue;

Queue * createQueue(int capacity);
void enqueue(Queue * queue, int data);
void dequeue(Queue * queue);
int front(Queue * queue);
int isEmpty(Queue * queue);
int isFull(Queue * queue);
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
  enqueue(queue, 15);
  dequeue(queue);
  enqueue(queue, 16);
  print(queue);
  return 0;
}


Queue * createQueue(int capacity)
{
  Queue * newQueue = (Queue *)malloc(sizeof(Queue));
  newQueue->frontIdx = -1;
  newQueue->rearIdx = -1;
  newQueue->data = (int *)malloc(sizeof(int) * capacity);
  newQueue->capacity = capacity;
  return newQueue;
}

void enqueue(Queue * queue, int data)
{
  if (isFull(queue))
  {
    printf("Overflow!\n");
    return;
  }
  if (isEmpty(queue))
  {
    queue->frontIdx = 0;
  }
  if (queue->rearIdx == queue->capacity - 1)
  {
    queue->rearIdx = 0;
    queue->data[queue->rearIdx] = data;
  }
  else
  {
    queue->data[++queue->rearIdx] = data;
  }
}
void dequeue(Queue * queue)
{
  if (isEmpty(queue))
  {
    return;
  }
  if (queue->frontIdx == queue->rearIdx)
  {
    queue->frontIdx = -1;
    queue->rearIdx = -1;
  }
  if (queue->frontIdx == queue->capacity - 1)
  {
    queue->frontIdx = 0;
  }
  queue->frontIdx++;
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
  return (queue->rearIdx == -1 && queue->frontIdx == -1) ? 1 : 0;
}

int isFull(Queue * queue)
{
  if (queue->frontIdx - queue->rearIdx == 1)
  {
    return 1;
  }
  return (queue->rearIdx - queue->frontIdx == queue->capacity - 1) ? 1 : 0;
}

void print(Queue * queue)
{
  if (isEmpty(queue))
  {
    printf("Queue is empty\n");
    return;
  }
  printf("Queue: ");
  if (queue->rearIdx >= queue->frontIdx)
  {
    for (int queueSize = queue->frontIdx; queueSize <= queue->rearIdx; queueSize++)
    {
      printf("%d ", queue->data[queueSize]);
    }
  }
  else
  {
    for (int queueIdx0 = queue->frontIdx; queueIdx0 < queue->capacity; queueIdx0++)
    {
      printf("%d ", queue->data[queueIdx0]);
    }
    for (int queueIdx1 = 0; queueIdx1 <= queue->rearIdx; queueIdx1++)
    {
      printf("%d ", queue->data[queueIdx1]);
    }
  }
  printf("\n");
}
