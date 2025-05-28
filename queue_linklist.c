// #include <stdio.h>
// #include <stdlib.h>
// struct node
// {
//     int data;
//     struct node *next;
// };
// struct node *front = NULL, *rear = NULL;
// void enqueue(int);
// void dequeue();
// void display();
// int main()
// {
//     int ch, value;
//     while (1)
//     {
//         printf("1.Enqueue\n 2.Dequeue\n 3.Display\n");
//         printf("Enter the choice:");
//         scanf("%d", &ch);
//         switch (ch)
//         {
//         case 1:
//             printf("Enter the value");
//             scanf("%d", &value);
//             enqueue(value);
//             break;
//         case 2:
//             dequeue();
//             break;
//         case 3:
//             display();
//             break;
//         default:
//             printf("Wrong choice\n");
//         }
//     }
// }
// void enqueue(int value){
//     struct node * new_node=(struct node*) malloc(sizeof(struct node));
//     new_node->data=value;
//     new_node->next=NULL;
//     if(rear==NULL){
//         front=rear=new_node;
//     }else{
//         rear->next=new_node;
//         rear=new_node;
//     }

// }
// void dequeue() {
//     if (front == NULL) {
//         printf("Underflow\n");
//     } else {
//         struct node *temp = front;
//         front = front->next;
//         if (front == NULL)
//             rear = NULL;
//         printf("Dequeued: %d\n", temp->data);
//         free(temp);
//     }
// }

// void display() {
//     if (front == NULL) {
//         printf("Queue is empty\n");
//         return;
//     }
//     struct node *temp = front;
//     while (temp != NULL) {
//         printf("%d -> ", temp->data);
//         temp = temp->next;
//     }
//     printf("NULL\n");
// }

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void enqueue(struct node **front, struct node **rear, int value);
void dequeue(struct node **front, struct node **rear);
void display(struct node *front);

int main() {
    int ch, value;
    struct node *front = NULL, *rear = NULL;

    while (1) {
        printf("1. Enqueue\n2. Display\n3. Dequeue\n");
        printf("Enter the choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &value);
                enqueue(&front, &rear, value);
                break;
            case 2:
                display(front);
                break;
            case 3:
                dequeue(&front, &rear);
                break;
            default:
                printf("Wrong choice\n");
        }
    }
}

void enqueue(struct node **front, struct node **rear, int value) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;

    if (*rear == NULL) {
        // Queue is empty
        *front = *rear = new_node;
    } else {
        (*rear)->next = new_node;
        *rear = new_node;
    }
}

void dequeue(struct node **front, struct node **rear) {
    if (*front == NULL) {
        printf("Underflow\n");
    } else {
        struct node *temp = *front;
        printf("Dequeued: %d\n", temp->data);
        *front = (*front)->next;
        if (*front == NULL) {
            // Queue became empty
            *rear = NULL;
        }
        free(temp);
    }
}

void display(struct node *front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    while (front != NULL) {
        printf("%d -> ", front->data);
        front = front->next;
    }
    printf("NULL\n");
}
