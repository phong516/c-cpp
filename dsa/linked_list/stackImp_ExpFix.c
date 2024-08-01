#include <stdio.h>
#include <malloc.h>
#include <ctype.h>
#include <string.h>

typedef struct Node
{
  int data;
  struct Node * next;
}Node;

void Push(Node ** head, int data);
int Pop(Node ** head);
int Top(Node * head);
void Print(Node * head);
int isEmpty(Node * head);
void Reverse(Node ** head);
int checkBalacedParathesis(char expression[]);
int CalPostfix(char * expression);
int CalPrefix(char * exp);
void infixToPostfix(char * exp, char * output);
void infixToPrefix(char * exp, char * output);
int getPrec(int operator);
int hasLowerPrec(int src, int des);

int main(void)
{
  /* char expression[] = "100 200 + 2 / 5 * 7 +";
  printf("%d\n", CalPostfix(expression)); */
  /* char expression[] = "+ 9 * 12 6";
  printf("%d\n", CalPrefix(expression)); */
  char infix[] = "((7 + 3) * (4 - 2) / (6 + 1)) - 5";
  char exp[100] = {'\0'};
  // infixToPostfix(infix, exp);
  infixToPrefix(infix, exp);
  printf("%s\n", exp);
  printf("Result: %d\n", CalPrefix(exp));
  return 0;
}

void Push(Node ** head, int data)
{
  Node * new = (Node *)malloc(sizeof(Node));
  new->next = *head;
  new->data = data;
  *head = new;
}

int Pop(Node ** head)
{
  int result = Top(*head);
  Node * top = *head;
  *head = (*head)->next;
  free(top);
  return result;
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


int checkBalacedParathesis(char expression[])
{
  Node * stackTop = NULL;
  char *ptr = expression;
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

int CalPostfix(char * expression)
{
  Node * stack = NULL;
  int p1, p2;
  for (int i = 0; expression[i] != '\0'; i++)
  {
    if (expression[i] == ' ')
    {
    }
    else if (isdigit(expression[i]))
    {
      int num = 0;
      while (isdigit(expression[i]))
      {
        num = num * 10 + (int)(expression[i] - '0');
        i++;
      }
      i--;
      Push(&stack, num);
    }
    else 
    {
      p2 = Pop(&stack);
      p1 = Pop(&stack);
      switch (expression[i])
      {
        case '*':
          Push(&stack, p1 * p2);
          break;

        case '/':
          Push(&stack, p1 / p2);
          break;

        case '+':
          Push(&stack, p1 + p2);
          break;

        case '-':
          Push(&stack, p1 - p2);  
          break;
      }
    }
  }
  return Top(stack);
}

int CalPrefix(char * exp)
{
  Node * stack = NULL;
  int p1 = 0, p2 = 0;
  for (int i = strlen(exp) - 1; i >= 0; i--)
  {
    if (exp[i] == ' ')
    {
    }
    else if (isdigit(exp[i]))
    {
      int num = 0;
      int j = i;
      while (isdigit(exp[--i]));
      i++;
      for (int k = i; k <= j; k++)
      {
        num = num * 10 + (int)(exp[k] - '0'); 
      }
      Push(&stack, num);  
    } 
    else
    {
      p2 = Pop(&stack);
      p1 = Pop(&stack);
      int result = 0;
      switch (exp[i])
      {
        case '*':
          result = p1 * p2;
          break;

        case '/':
          result = p1 / p2;
          break;

        case '+':
          result = p1 + p2;
          break;

        case '-':
          result = p1 - p2;
          break;
      }
        Push(&stack, result);
    }
  }
  return Top(stack);
}

void infixToPostfix(char * exp, char * output)
{
  char res[100] = {'\0'};
  int resIdx = 0;
  Node * operator = NULL;

  for (int expIdx = 0; exp[expIdx] != '\0'; expIdx++)
  {
    char c = exp[expIdx];

    if (c == ' ');

    else if (isdigit(c))
    {
      while (isdigit(exp[expIdx]))
      {
        res[resIdx++] = exp[expIdx++];
      }
      res[resIdx++] = ' ';
      expIdx--;
    }

    else if (c == '(')
    {
      Push(&operator, c);
    }
    
    else if (c == ')')
    {
      while (!isEmpty(operator) && Top(operator) != '(')
      {
        res[resIdx++] = Pop(&operator);
      }
      Pop(&operator);
    }
    else
    {
      while (!isEmpty(operator) && hasLowerPrec(Top(operator), exp[expIdx]))
      {
      res[resIdx++] = (char)Pop(&operator);
      }
      Push(&operator, exp[expIdx]);
    }
  }
  while (!isEmpty(operator))
  {
    res[resIdx++] = Pop(&operator);
  }
  for (int i = 0; res[i] != '\0'; i++)
  {
    output[i] = res[i];
  }

}

void infixToPrefix(char * exp, char * output)
{
  char expReverse[strlen(exp)];
  // reverse exp
  for (int expIdx = 0; expIdx < strlen(exp); expIdx++)
  {
    expReverse[expIdx] = exp[strlen(exp) - 1 - expIdx];
    switch (expReverse[expIdx])
    {
      case '(':
        expReverse[expIdx] = ')';
        break;
      case ')':
        expReverse[expIdx] = '(';
        break;
    }
  }

  // convert to postfix
  char postfix[100] = {'\0'};
  infixToPostfix(expReverse, postfix);

  for (int outputIdx = 0; outputIdx < strlen(postfix); outputIdx++)
  {
    output[outputIdx] = postfix[strlen(postfix) - 1 - outputIdx];
  }

}

int getPrec(int operator)
{
  int prec = 0;
  switch (operator)
  {
    case '+':
    case '-':
      prec = 0;
      break;

    case '*':
    case '/':
      prec = 1;
      break;
    default:
      prec = -1;
  }
  return prec;
}

int hasLowerPrec(int src, int des)
{
  return getPrec(des) <= getPrec(src) ? 1 : 0;
}
