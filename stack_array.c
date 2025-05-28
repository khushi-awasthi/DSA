#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
int top = -1;

int stack[MAX_SIZE];
void push(int data)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Overflow");
    }
    else
    {
        printf("data insert%d",data);
    }
    stack[top++] = data;
}
void pop()
{
    if (top == -1)
    {
        printf("Underflow");
    }
    else
    {
        printf("%d", stack[top]);
        
    }
    top--;
}
void display()
{
    if (top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Stack elments:\n");
        for (int i = 0; i <= top; i++)
        {
            printf("%d\n", stack[i]);
        }
    }
}
int main()
{
    int value, ch;
    while (1)
    {
        printf("1.push\n 2.pop\n 3.display\n 4.exit\n");
        printf("Enter youe choice");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("enter the vlue");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("Wrong choice");
        }
    }
}