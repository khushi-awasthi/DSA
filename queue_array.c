#include <stdio.h>
#define MAX_SIZE 5
int f = -1;
int r = -1;
int q[MAX_SIZE];
void insertion(int value)
{
    if (r == MAX_SIZE - 1)
    {
        printf("Overflow");
        return;
    }
    if (f == -1 && r == -1)
    {
        f = r = 0;
        
    }else{
    r++;
    }
    q[r] = value;
}
void delete()
{
    if (f == -1 || f > r)
    {
        printf("Underflow");
    }
    else if (f == r)
    {
        printf("%d", q[f]);
        f = r = -1;
    }
    else
    {
        printf("%d", q[f]);
        f++;
        if (f > r)
        {
            f = r = -1;
        }
    }
}
void display()
{
    if (f == -1 || f > r)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("Display the values\n");
        for (int i = f; i <= r; i++)
        {
            printf("%d\n", q[i]);
        }
    }
    printf("NULL\n");
}
int main()
{
    int value, ch;
    while (1)
    {
        printf("\n1.insertion\n2.deletion\n 3. display\n");
        printf("enter your choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value");
            scanf("%d", &value);
            insertion(value);
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        default:
            printf("Wrong choice");
        }
    }
}