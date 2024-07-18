#include <malloc.h>
#include <stdio.h>
typedef struct Node
{
  int data;
  struct Node * next;
  struct Node * prev;
}Node;

Node * create(int data)
{
  Node * new = (Node *)malloc(sizeof(Node));
  new->data = data;
  new->next = NULL;
  new->prev = NULL;
  return new;
}

void insert(Node ** head, int pos, int data)
{
  Node * new = create(data);
  if (*head == NULL)
  {
   *head = new;
    return;
  }
  if (pos == 0)
  {
    (*head)->prev = new;
    new->next = *head;
    *head = new;
    return;
  }
  Node * current = *head;
  for (int i = 0; i < pos - 1 && current->next != NULL; i++)
  {
    current = current->next;
  }
  new->next = current->next;
  new->prev = current;
  if (current->next != NULL)
  {
    (current->next)->prev = new;
  }
  current->next = new;

}

void delete(Node ** head, int pos)
{
  Node * current = *head;
  // delete first node
  if (pos == 0)
  {
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(current);
    return;
  }

  // delete any node
  // if pos exceed len of list, delete the last

  // move the current to the pos
  for (int i = 0; i < pos; i++)
  {
    if (current->next == NULL)
    {
      break;
    }
    current = current->next;
  }

  // delete node
  if (current->next != NULL)
  {
    (current->prev)->next = current->next;
    (current->next)->prev = current->prev;
  }
  else
  {
    (current->prev)->next = NULL;
  }
  free(current);
}

void reverse(Node ** head)
{
  Node * current = *head;
  while (current != NULL)
  {
    Node * temp = current->next;
    current->next = current->prev;
    current->prev = temp;
    if (current->prev != NULL)
    {
      current = current->prev;
    }
    else
    {
      break;
    }
  }
  *head = current;
}

Node * reverseRecursion(Node * node)
{
  Node * tmp = node->next;
  node->next = node->prev;
  node->prev = tmp;
  if (node->prev == NULL)
  {
    return node;
  }
  return reverseRecursion(node->prev);

}

void print(Node * head)
{
  Node * current = head;
  while (current != NULL)
  {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

void printRecursion(Node * node)
{
  printf("%d ", node->data);
  if (node->next == NULL)
  {
    printf("\n");
    return;
  }
  printRecursion(node->next);
}

void printRecursionReverse(Node * node)
{
  if (node == NULL)
  {
    return;
  }
  printRecursionReverse(node->next);
  printf("%d ", node->data);
  if (node->prev == NULL)
  {
    printf("\n");
  }
}

int main()
{
  Node * node = NULL;
  insert(&node, 0, 1);
  insert(&node, 1, 2);
  insert(&node, 2, 3);
  insert(&node, 3, 4);
  print(node);
  reverse(&node);
  print(node);
  node = reverseRecursion(node);
  print(node);
  printRecursion(node);
  printRecursionReverse(node);
  return 0;
}
