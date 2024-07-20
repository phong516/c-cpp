#include <stdio.h>
#include <malloc.h>
typedef struct Node
{
  int data;
  struct Node * next;
}Node;

Node * top = NULL;

void Push(int data)
{
  Node * new = (Node *)malloc(sizeof(Node));
  new->next = top;
  new->data = data;
  top = new;
}

void Pop(void)
{
  if (top == NULL)
  {
    return;
  }
  Node * deletedNode = top;
  top = top->next;
  free(deletedNode);
}

void Print(void)
{
  printf("Stack: ");
  Node * current = top;
  while (current != NULL)
  {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main(void)
{
  Push(1);
  Push(2);
  Push(3);
  Print();
  Pop();
  Print();
  
  return 0;
}
