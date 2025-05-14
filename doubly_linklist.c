#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
}*head=NULL;

void insert_at_begin(struct node**,int);
void insert_at_end(struct node**,int);
void delete_at_beg(struct node**);
void delete_at_end(struct node**);
void insert_at_specific(struct node**,int,int);
void delete_at_specific(struct node**,int);
void display(struct node*);
void counter(struct node*);

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
void insert_at_begin(struct node** head_ref, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    if(*head_ref==NULL){
        *head_ref=new_node;
    }
    else{
        new_node->next=*head_ref;
        (*head_ref)->prev = new_node;
        *head_ref = new_node;
}
}
void insert_at_end(struct node** head_ref, int data){
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    if(*head_ref==NULL){
        *head_ref=new_node;
    }
    else{
        struct node* move=*head_ref;
        while(move->next!=NULL){
            move=move->next;
        }
        move->next=new_node;
        new_node->prev=move;
    }
}
void display(struct node* r){
    while(r!=NULL){
        printf("%d->",r->data);
        r=r->next;
    }
    printf("NULL\n");
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
    new_node->prev=NULL;

    if (position <= 1 || *head_ref == NULL) {
        // Insert at the beginning
        new_node->next = *head_ref;
        *head_ref = new_node;
        new_node->prev=NULL;
        return;
    }
    struct node* current = *head_ref;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        // Position is out of bounds
        current = *head_ref;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
        current->prev=current;
    } else {
        // Normal case: insert at the given position
        new_node->next = current->next;
        current->next = new_node;
        current->prev=current;
    }
}
void delete_at_specific(struct node** head_ref,int pos){
    if (*head_ref == NULL) {
        printf("List is empty.\n");
        return;
    }
     struct node* current = *head_ref;
    // Delete the head node
    if (pos == 1) {
        *head_ref = current->next;
        current->prev=NULL;
        free(current);
        return;
    }
    // Traverse to the node just before the one to delete
    for (int i = 1; i < pos - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL || current->next == NULL) {
        printf("Invalid position.\n");
        return;
    }
    struct node* temp = current->next;
    current->next = temp->next;
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












