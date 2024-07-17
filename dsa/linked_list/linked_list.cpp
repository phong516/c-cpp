#include <iostream>

typedef struct Node
{
  int data;
  struct Node * next;

  Node(int data, Node * next)
  {
    this->data = data;
    this->next = next;
  }

}Node;

void insertBeginningNode(Node ** head, int data)
{
  Node * newNode = new Node(data, *head);
  *head = newNode;
}

void insertNode(Node ** head, int data, int index)
{
  Node * newNode = new Node(data, *head);
  if (index == 0)
  {
    *head = newNode;
    return;
  }
  Node * current = *head;
  for (int i = 0; i < index - 1 && current->next != NULL; i++)
  {
    current = current->next;
  }
  newNode->next = current->next;
  current->next = newNode;

}

void deleteNode(Node ** head, int index)
{
  if (index == 0)
  {
    Node * deletedNode = *head;
    *head = deletedNode->next;
    free(deletedNode);
    return;
  }

  Node * current = *head;
  for (int i = 0; i < index - 1 && current->next != NULL; i++)
    {
      current = current->next;
    }
  Node * deletedNode = current->next;
  current->next = deletedNode->next;
  free(deletedNode);
}

void reverseNode(Node ** head)
{
  Node * prev = NULL;
  Node * current = *head;
  Node * next = *head;

  while (next != NULL)
  {
    current = next;
    next = current->next;
    current->next = prev;
    prev = current;
  }
  *head = current;
}

void printLinkedList(Node * head)
{
  Node * current = head;
  while (current != NULL)
  {
    std::cout << current->data << " -> ";
    current = current->next; 
  }
  std::cout << "NULL" << std::endl;
}

int main()
{
  Node * head = NULL;
  insertBeginningNode(&head, 10);
  insertBeginningNode(&head, 20);
  insertNode(&head, 30, 1);
  insertNode(&head, 40, 0);
  insertNode(&head, 50, 2);
  insertNode(&head, 60, 3);
  deleteNode(&head, 0);
  deleteNode(&head, 0);
  deleteNode(&head, 0);
  deleteNode(&head, 0);
  deleteNode(&head, 0);
  reverseNode(&head);
  printLinkedList(head);

  return 0;
}
