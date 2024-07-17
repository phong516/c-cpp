#include <stdio.h>
#include <malloc.h>

typedef struct Node
{
  int data;
  struct Node * link;
}Node;


Node * head = NULL;

Node * createNode(int data)
{
  Node * newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->link = NULL;
  return newNode;
}

void insertBeginningNode(Node ** nodeHead, int data)
{
  Node * newNode = createNode(data);
  newNode->link = *nodeHead;
  *nodeHead = newNode;

}

void insertEndNode(Node * nodeHead, int data)
{
  Node * newNode = createNode(data);
  Node * current = nodeHead;
  while (current != NULL)
  {
    if (current->link == NULL)
    {
      break;
    }
    current = current->link;
  }
  current->link = newNode;
}

void insertMiddleNode(Node ** nodeHead, int data, int index)
{
  Node * newNode = createNode(data);
  Node * current = *nodeHead;
  if (index == 0)
  {
    newNode->link = *nodeHead;
    *nodeHead = newNode;
    return;
  }
  for (int i = 0; i < index - 1 && current != NULL; i++)
  {
    if (current->link == NULL)
    {
      break;
    }
    current = current->link;
  }
  newNode->link = current->link;
  current->link = newNode;
}

void deleteNode(Node ** head, int index)
{
  Node * current = *head;
  if (index == 0)
  {
   *head = (*head)->link;
    free(current);
    return;
  }
  for (int i = 0; i < index - 1 && current->link != NULL; i++)
  {
    current = current->link;
  }
  Node * deletedNode = current->link;
  current->link = deletedNode->link;
  free(deletedNode);
}

void reverseLinkedList(Node ** head)
{
  Node * next = *head;
  Node * current = *head;
  Node * prev = NULL;
  while (next != NULL)
  {
    current = next;
    next = current->link; 
    current->link = prev;
    prev = current;
  }
  *head = current;
  
}

void reverseLinkedListRecursion(Node * node)
{
  if (node->link == NULL)
  {
    head = node;
    return;
  }
  reverseLinkedListRecursion(node->link);
  (node->link)->link = node;
  node->link = NULL;
}

void printLinkedList(Node * head)
{
  Node * current = head;
  while (current != NULL)
  {
    printf("%d -> ", current->data);
    current = current->link;
  }
  printf("NULL\n");
}

void printLinkedListRecursion(Node * node)
{
 if (node == NULL)
  {
    return;
  }

  printf("%d ", node->data);
  printLinkedListRecursion(node->link);
  
}

void printLinkedListRecursionReverse(Node * node)
{
  if (node == NULL)
  {
    return;
  }

  printLinkedListRecursionReverse(node->link);
  printf("%d ", node->data);
}

int main()
{
  insertBeginningNode(&head, 5);
  insertBeginningNode(&head, 4);
  insertBeginningNode(&head, 3);
  insertBeginningNode(&head, 2);
  insertBeginningNode(&head, 1);
  reverseLinkedListRecursion(head);
  printLinkedList(head);
  return 0;
}
