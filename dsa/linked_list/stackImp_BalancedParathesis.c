#include <stdio.h>
#include <malloc.h>

typedef struct Node
{
  char data;
  struct Node * next;
}Node;

void Push(Node ** head, char data);
void Pop(Node ** head);
char Top(Node * head);
void Print(Node * head);
char isEmpty(Node * head);
void Reverse(Node ** head);
int checkBalacedParathesis(char string[]);

int main(void)
{
  char string[] = "[[({})]";
  checkBalacedParathesis(string);
  return 0;
}

void Push(Node ** head, char data)
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

char Top(Node * head)
{
  if (isEmpty(head))
  {
    return -1;
  }
  return head->data;
}

char isEmpty(Node * head)
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
    printf("%c ", current->data);
    current = current->next;
  }
  printf("\n");
}


int checkBalacedParathesis(char string[])
{
  Node * stackTop = NULL;
  char *ptr = string;
  while (*ptr != '\0')
  {
    if (
        (*ptr == '}' && Top(stackTop) == '{') || 
        (*ptr == ']' && Top(stackTop) == '[') ||
        (*ptr == ')' && Top(stackTop) == '(')
      ) 
    {
      Pop(&stackTop);
    }
    else
    {
      Push(&stackTop, *ptr);
    }
    ptr++;
  }
  if (isEmpty(stackTop))
  {
    printf("Balanced Parathesis\n");
    return 1;
  }
  else
  {
    while (stackTop != NULL)
    {
      Pop(&stackTop);
    }
    printf("Imbalanced Parathesis\n");
    return 0;
  }
}
