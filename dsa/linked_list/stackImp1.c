#include <stdio.h>
#include <malloc.h>

typedef struct Node
{
  int data;
  struct Node * next;
}Node;

void Push(Node ** head, int data);
void Pop(Node ** head);
int Top(Node * head);
void Print(Node * head);
int isEmpty(Node * head);
void Reverse(Node ** head);

int main(void)
{
  Node * node = NULL;
  Push(&node, 1);
  Push(&node, 2);
  Print(node);
  Pop(&node);
  Print(node);
  Push(&node, 3);
  Top(node);
  Push(&node, 4);
  Push(&node, 5);
  Push(&node, 6);
  Print(node);
  Reverse(&node);
  Print(node);
  return 0;
}

void Push(Node ** head, int data)
{
  Node * new = (Node *)malloc(sizeof(Node));
  new->next = *head;
  new->data = data;
  *head = new;
}

void Pop(Node ** head)
{
  if (isEmpty(*head))
  {
    return;
  }
  Node * top = *head;
  *head = (*head)->next;
  free(top);
}

int Top(Node * head)
{
  if (isEmpty(head))
  {
    return -1;
  }
  return head->data;
}

int isEmpty(Node * head)
{
  if (head == NULL)
  {
    printf("Empty stack\n");
    return 1;
  }
  return 0;
}

void Reverse(Node ** head)
{
  Node * oldTop = *head;
  *head = NULL;
  while (!isEmpty(oldTop))
  {
    Push(head, Top(oldTop));
    Pop(&oldTop);
  }
}

void Print(Node * head)
{
  printf("Stack: ");
  Node * current = head;
  while (current != NULL)
  {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}
