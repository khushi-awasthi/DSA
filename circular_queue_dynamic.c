// #include<stdio.h>
// #include<stdlib.h>
// struct node{
//     int data;
//     struct node * next;
//     struct node * rear;
// };

// void enqueue(struct node **front, struct node **rear, int value);
// void dequeue(struct node **front, struct node **rear);
// void display(struct node *front);

// void enqueue(struct node **f, struct node **r,int new_data ){
//     struct node* new_node=(struct node*) malloc (sizeof(struct node));
//     new_node->data=new_data;
//     if(*f==NULL){
//          new_node->next=new_data;
//          r=new_node;
         
//     }
//     else{
//         if((*head_ref)->next==*head_ref)//one node
//         {
//             (*head_ref)->next=new_node;
//             new_node->next=*head_ref;
//             *head_ref=new_node;
//         }else{
//             struct node* move=*head_ref;
//             while(move->next!=*head_ref){
//                 move=move->next;
//         }
//         move->next=new_node;
//         new_node->next=*head_ref;
//         *head_ref=new_node;
//     }
//     }
// }
   

    


// int main(){
//     int ch,value;
//     while(1){
//         printf("1.enqueue\n 2.dequeue\n 3.display\n");
//         printf("Enter your choice");
//         scanf("%d",&ch);
//         switch(ch){
//             case 1:
//                 printf("Enter the value");
//                 scanf("%d",&value);
//                 enqueue(&value);
//                 break;
//         }
//     }
// }





#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Enqueue operation
void enqueue(Node** rear,Node** front, int value) {
   struct Node* newNode = (struct Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next=*front;

    if (*rear == NULL) {
        newNode->next = newNode;
        *rear = newNode;
    } else {
        newNode->next = (*rear)->next;
        (*rear)->next = newNode;
        *rear = newNode;
    }

    printf("Enqueued: %d\n", value);
}

// Dequeue operation
void dequeue(Node** rear) {
    if (*rear == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    Node* front = (*rear)->next;
    if (front == *rear) {
        printf("Dequeued: %d\n", front->data);
        free(front);
        *rear = NULL;
    } else {
        (*rear)->next = front->next;
        printf("Dequeued: %d\n", front->data);
        free(front);
    }
}

// Display queue
void display(Node* rear) {
    if (rear == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    Node* temp = rear->next;
    printf("Queue: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != rear->next);
    printf("\n");
}

// Main menu
int main() {
    Node* rear = NULL;
    Node* front = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&rear,&front, value);
                break;
            case 2:
                dequeue(&rear);
                break;
            case 3:
                display(rear);
                break;
            case 4:
                while (rear != NULL) {
                    dequeue(&rear);  
                }
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
