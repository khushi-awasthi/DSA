#include<stdio.h>
#define size 5
int queue[size];
int front=-1,rear=-1;
void insertFront(int value){
    if((front == 0 && rear == size - 1) || (front == rear + 1)){
        printf("Queue is full");
        return ;
    }
    if(front==-1){
        front=rear=0;
    }else if(front==0){
        front = size - 1;
    } else {
        front--;
    }
    queue[front]=value;
    printf("inserted %d",value);
   }
   void insertRear(int value) {
    if ((front == 0 && rear == size - 1) || (front == rear + 1)){
        printf("queue is full.\n");
        return;
    }

    if (front==-1) {
        front = rear = 0;
    } else if (rear == size - 1) {
        rear = 0;
    } else {
        rear++;
    }

    queue[rear] = value;
    printf("Inserted %d at rear.\n", value);
}
void deleteFront() {
    if (front==-1) {
        printf("queue is empty.\n");
        return;
    }

    printf("Deleted %d from front.\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else if (front == size - 1) {
        front = 0;
    } else {
        front++;
    }
}
void deleteRear() {
    if (front==-1) {
        printf("queue is empty.\n");
        return;
    }

    printf("Deleted %d from rear.\n", queue[rear]);

    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = size - 1;
    } else {
        rear--;
    }
}
void display() {
    if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
        printf("queue is empty.\n");
        return;
    }
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % size;
    }
    printf("\n");
}
int main()
{
    int value, ch;
    while (1)
    {
        printf("\n1.insertionfront \n2.insertRear\n 3. display\n 4.deleteFront \n 5.deleteRear\n");
        printf("enter your choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value");
            scanf("%d", &value);
            insertFront(value);
            break;
        case 2:
            printf("Enter the value");
            scanf("%d", &value);
            insertRear(value);
            break;
            
        case 3:
            display();
            break;
        case 4:
            deleteFront();
            break;
        case 5:
            deleteRear();
            break;
        default:
            printf("Wrong choice");
        }
    }
}