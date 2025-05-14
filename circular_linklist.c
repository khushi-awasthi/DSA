#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
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
    int ch,value,pos;
    while(1){
    printf("1.insert_at_begin\n 2.insert_at_end\n 3.display\n 4.exit\n 5.delete_at_beg\n 6. delete_at_end\n 7.insert_at_specific\n");
    printf("Enter your choice");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            printf("Enter the data");
            scanf("%d",&value);
            insert_at_begin(&head,value);
            break;
        case 2:
            printf("Enter the data");
            scanf("%d",&value);
            insert_at_end(&head,value);
            break;
        case 3:
            display(head);
            break;
        case 4:
            exit(1);
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
            printf("enter the position");
            scanf("%d",&pos);
            delete_at_specific(&head,pos);
            break;
        case 9:
            counter(head);
            break;
        default:
            printf("Wrong choice!");

    }
}
}
void insert_at_begin(struct node** head_ref,int new_data){
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=new_data;
    // new_node->next=NULL;

    if(*head_ref==NULL){
         new_node->next=new_node;
         *head_ref=new_node;
    }
    else{
        if((*head_ref)->next==*head_ref)//one node
        {
            (*head_ref)->next=new_node;
            new_node->next=*head_ref;
            *head_ref=new_node;
        }else{
            struct node* move=*head_ref;
            while(move->next!=*head_ref){
                move=move->next;
        }
        move->next=new_node;
        new_node->next=*head_ref;
        *head_ref=new_node;
    }
    }
}
void insert_at_end(struct node** head_ref,int new_data){
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=new_data;
    // new_node->next = NULL;
    if(*head_ref==NULL){
        new_node->next=new_node;
        *head_ref=new_node;
        return;
    }
    
        struct node* move=*head_ref;
        while(move->next != *head_ref){
            move=move->next;
        }
        move->next=new_node;
        new_node->next = *head_ref;
    }

    

void display(struct node* head){
    struct node* r=head;
    if(head==NULL){
        printf("List is empty");
        return;
    }

    do{
        printf("%d->",r->data);
        r=r->next;
    }while(r!=head);
    printf("NULL\n");

}

void delete_at_beg(struct node** head_ref){
    if(*head_ref==NULL){
        printf("List is empty");
        return;
    }
    
        struct node* move=*head_ref;
        if((*head_ref)->next==*head_ref){
            free(*head_ref);
            *head_ref=NULL;
        }
        else{
            struct node* last=*head_ref;
            while(last->next!=*head_ref){
                last=last->next;
            }
            last->next=(*head_ref)->next;//last node point  to new node
            *head_ref=(*head_ref)->next;
            free(move);
        }
}

void delete_at_end(struct node** head_ref){
    if(*head_ref==NULL){
        printf("List is empty");
        return;
    }
    // struct node* move=*head_ref;
        if((*head_ref)->next==*head_ref){
            free(*head_ref);
            *head_ref=NULL;
            return;
        }
        
            struct node* second_last=*head_ref;
            while(second_last->next->next!=*head_ref){
                second_last=second_last->next;
            }
            struct node* last=second_last->next;
            second_last->next=*head_ref;
            free(last);

}
// void insert_at_specific(struct node** head_ref, int new_data,int pos){
//     struct node* new_node=(struct node*)malloc(sizeof(struct node));
    

//     if(pos<=0){
//         if(*head_ref==NULL){
//             new_node->data=new_data;
//             new_node->next=*head_ref;
//             *head_ref=new_node;
//         }
            
//             if(pos<=1){
//                 struct node* move=*head_ref;
//                 move->next=new_node;
//                 new_node->next=*head_ref;
//                 *head_ref=new_node;

//             }
//             struct node* move=*head_ref;
//             for(int i=1;i<pos-1;i++){
//                 move=move->next;

//             }
//             if(move->next==*head_ref){
//                 struct node* move=*head_ref;
//                 while(move->next!=*head_ref){
//                 move=move->next;
//             }
//             move->next=new_node;
//             }
//             new_node->next=move->next;
//             move->next=new_node;

//             }
            
//         }
        
    



void insert_at_specific(struct node** head_ref, int new_data, int pos) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;

    // Case 1: Empty list
    if (*head_ref == NULL) {
        new_node->next = new_node;  // Point to itself (circular)
        *head_ref = new_node;
        return;
    }
    // Case 2: Insert at head
    if (pos <= 0 || pos == 1) {
        struct node* temp = *head_ref;
    // Traverse to the last node
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = new_node;
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }
    // Case 3: Insert at specific position
    struct node* temp = *head_ref;
    for (int i = 1; i < pos - 1 && temp->next != *head_ref; i++) {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}
void delete_at_specific(struct node** head_ref,int pos){
    if(*head_ref == NULL || pos <= 0){
        printf("List is empty");
        return;
    }
    struct node* move=*head_ref;
    // only one node
    if(move->next == move && pos == 1){
        free(move);
        *head_ref = NULL;
        return;
    }
    if(pos==1){
        struct node* last = *head_ref;
        while (last->next != *head_ref) {
            last = last->next;
        }
        last->next = (*head_ref)->next;
        move = *head_ref;
        *head_ref = (*head_ref)->next;
        free(move);
        return; 
    }
    for(int i=1; i<pos-1 && move->next != *head_ref; i++){
        move=move->next;
        if (move->next == *head_ref) {
            printf("Position out of range\n");
            return;
        }
    }
    struct node* del = move->next;
    move->next = del->next;
    free(del);
    }
    void counter(struct node* head) {
        int count = 0;
        struct node* temp = head;
    
        if (head == NULL) {
            printf("Count: 0\n");
            return;
        }
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
    
        printf("Count: %d\n", count);
    }
    
     