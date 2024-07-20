#include <stdio.h>

#define ARRAY_SIZE 100
int array[ARRAY_SIZE];
int top = -1;

int Push(int data)
{
  if (top == ARRAY_SIZE - 1)
  {
    printf("Stack Overflow %d!!!", top);
    return 0;
  }
  array[++top] = data;
  printf("Pushed %d to index %d\n", data, top);
  return 1; 
}

int Pop(void)
{
  if (top == -1)
  {
    printf("Array is empty, can not pop\n");
    return 0;
  }
  printf("Popped index %d\n", top);
  array[top--] = 0;
  return 1;
}

int Top(void)
{
  printf("Top of the array is %d\n", top);
  return array[top];
}

int isEmpty(void)
{
  if (top == -1)
  {
    printf("Array is empty\n");
    return 1;
  }
  printf("Array is not empty\n");
  return 0;
}

int Print(void)
{
  if (top == -1)
  {
    printf("Nothing to print\n");
    return 0;
  }
  printf("Stack: ");
  for (int i = 0; i <= top; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");

  return 1;
}

int main()
{
  Push(1);
  Push(2);
  Push(3);
  Top();
  Pop();
  isEmpty();
  Print();
  return 0;
}
