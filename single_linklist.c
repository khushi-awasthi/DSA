#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head=NULL;
void insert_at_begin(struct node**,int);
void display(struct node*);
void insert_at_end(struct node**, int);
void delete_at_beg(struct node**);
void delete_at_end(struct node**);
void insert_at_specific(struct node**,int,int);
void delete_at_specific(struct node**,int);
void counter(struct node*);



// exit(1);
int main(){
    int ch, value,pos;
    while(1){
        printf("Menu");
        printf("1.insert_at_begin\n 2.display\n 3.exit\n 4.insert_at_end\n 5.delete_at_beg\n 6.delete_at_end\n 7.insert_at_specific\n 8.delete_at_specific\n 9.count\n ");
        printf("Enter your choice");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("enter the data");
                scanf("%d",&value);
                insert_at_begin(&head,value);
                break;
            case 2:
                display(head);
                break;
            case 3:
                exit(1);
                break;
            case 4:
                printf("Enter the data");
                scanf("%d",&value);
                insert_at_end(&head,value);
                break;
            case 5:
                delete_at_beg(&head);
                break;
            case 6:
                delete_at_end(&head);
                break;
            case 7:
                printf("Enter the data");
                scanf("%d",&value);
                printf("Enter the position");
                scanf("%d",&pos);
                insert_at_specific(&head,value,pos);
                break;
            case 8:
                printf("Enter the position");
                scanf("%d",&pos);
                delete_at_specific(&head,pos);
                break;
            case 9:
                counter(head);
                break;
            default:
            printf("Wrong choice");
        }
    }
    return 0;

}
void insert_at_begin(struct node**head_ref,int new_data){
    
    // Allocate memory for new node
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    // Assign the data to the next node
    new_node->data=new_data;
    // set the next to new node
    new_node->next=*head_ref;
    // move the head to point to point the new node
    *head_ref=new_node;
//     if (*head_ref == NULL)
//     printf("List was empty. Inserting first node.\n");
// else{
//     printf("Inserting node at the beginning of non-empty list.\n");
// }
}
void display(struct node* r){
    while(r!=NULL){
        printf("%d->",r->data);
        r=r->next;
    }
    printf("NULL\n");

}
void insert_at_end(struct node** head_ref,int new_data){
    // create a new node
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    // 
    new_node->data=new_data;
    new_node->next=NULL;
    // check the ll null
    if(*head_ref==NULL){
        printf("List was empty");
        *head_ref=new_node;
        return;
    }
    else{
        printf("Insert the node at the end");
        struct node* move=*head_ref;
        while(move->next!=NULL){
            move=move->next;
        }
        move->next=new_node;
    }
}
void delete_at_beg(struct node** head_ref){
    if(*head_ref==NULL){
        printf("List is empty");
        return;
    }
    else{
        struct node* move=*head_ref;
        *head_ref=(*head_ref)->next;
        printf("node deleted");
        free(move);   
    }
}
void delete_at_end(struct node**head_ref){
    if(*head_ref==NULL){
        printf("List is empty");
        return;
    }
    else if((*head_ref)->next==NULL){
        printf("deleted node with value:%d\n",(*head_ref)->data);
        free(*head_ref);
        *head_ref=NULL;
        return;


    }
    else{
        struct node* move=*head_ref;
        struct node* p;
        while(move->next!=NULL){
            p=move;
            move=move->next;
        }
        p->next=NULL;
        printf("%d",move->data);
        free(move);
    }
}

void insert_at_specific(struct node** head_ref, int new_data, int position) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (position <= 1 || *head_ref == NULL) {
        // Insert at the beginning
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }

    struct node* current = *head_ref;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        // Position is out of bounds
        printf("Invalid position. Inserting at the end.\n");
        current = *head_ref;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    } else {
        // Normal case: insert at the given position
        new_node->next = current->next;
        current->next = new_node;
    }
}


// void insert_at_specific(struct node** head_ref,int new_data,int position){
//     struct node* new_node=(struct node*)malloc(sizeof(struct node));
//     new_node->data=new_data;
//     new_node->next=NULL;
//     // if positon is 0
//     if(position<=0){
//         new_node->data=new_data;
//         new_node->next=*head_ref;
//         *head_ref=new_node;

//     }
//     struct node* current=*head_ref;
//     for(int i=0; i<position-1&&current!=NULL; i++){
//         current=current->next;
//     }
//     // if position is greater than length
//     if(current==NULL){
//         printf("Invalid position.inserting at the end");
//         current=*head_ref;
//         while(current->next!=NULL){
//             current=current->next;
//         }
//         current->next=new_node;
//     }
// }
// void delete_at_specific(struct node** head_ref,int position){
//     if(position<=0){
//         printf("List is empty");
//     }
//     struct node* current=*head_ref;
//     for(int i=0; i<position-1&&current!=NULL; i++){
//         current=current->next;
//      }
//      free(current);
// }

// void delete_at_specific(struct node** head_ref, int position) {
//     if (*head_ref == NULL) {
//         printf("List is empty.\n");
//         return;
//     }
//     struct node* current = *head_ref;
//     if (position == 0) {
//         *head_ref = current->next; // Move the head to the next node
//         free(current); // Free the old head
//         printf("Node at position %d deleted.\n", position);
//         return;
//     }
//     // Traverse to the node just before the one to be deleted
//     for (int i = 0; i < position - 1 && current != NULL; i++) {
//         current = current->next;
//     }
//     if (current == NULL || current->next == NULL) {
//         printf("Invalid position.\n");
//         return;
//     }
//     struct node* temp = current->next;
//     current->next = current->next->next; // Skip the node to delete
//     free(temp); // Free the node
//     printf("Node at position %d deleted.\n", position);
// }


void delete_at_specific(struct node** head_ref, int position) {
    if (*head_ref == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (position <= 0) {
        printf("Invalid position.\n");
        return;
    }

    struct node* current = *head_ref;

    // Delete the head node
    if (position == 1) {
        *head_ref = current->next;
        printf("Node at position %d with value %d deleted.\n", position, current->data);
        free(current);
        return;
    }

    // Traverse to the node just before the one to delete
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL || current->next == NULL) {
        printf("Invalid position.\n");
        return;
    }

    struct node* temp = current->next;
    current->next = temp->next;
    printf("Node at position %d with value %d deleted.\n", position, temp->data);
    free(temp);
}

void counter(struct node* head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    printf("Count: %d\n", count);

}