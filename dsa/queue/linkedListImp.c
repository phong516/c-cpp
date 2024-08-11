#include <stdio.h>
#include <malloc.h>

typedef struct Node
{
  int data;
  struct Node * nextNode;
}Node;

typedef struct Queue
{
  Node * front;
  Node * rear;
}Queue;

int isEmpty(Queue queue);
void enQueue(Queue * queue, int data);
void deQueue(Queue * queue);
void print(Queue queue);

int main(void)
{
  Queue queue = {NULL};
  enQueue(&queue, 1);
  enQueue(&queue, 2);
  enQueue(&queue, 3);
  print(queue);
  deQueue(&queue);
  print(queue);
  enQueue(&queue, 3);
  print(queue);
  deQueue(&queue);
  deQueue(&queue);
  print(queue);
  deQueue(&queue);
  print(queue);
  return 0;
}

int isEmpty(Queue queue)
{
  return (queue.front == NULL) ? 1 : 0;
}

void enQueue(Queue * queue, int data)
{
  Node * newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->nextNode = NULL;

  if (isEmpty(*queue))
  {
    queue->front = newNode;
    queue->rear = newNode;
    return;
  }
  queue->rear->nextNode = newNode;
  queue->rear = newNode;
}

void deQueue(Queue * queue)
{
  if (isEmpty(*queue))
  {
    return;
  }
  Node * deleted = queue->front;
  queue->front = queue->front->nextNode;
  free(deleted);
}

void print(Queue queue)
{
  Node * current = queue.front;
  printf("Queue: ");
  while (current != NULL)
  {
    printf("%d ", current->data);
    current = current->nextNode;
  }
  printf("\n");
}
