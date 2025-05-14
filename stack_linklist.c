#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*top=NULL;
void push(struct node**,int);
void pop(struct node**);
void display(struct node*);
int main(){
    int ch,value;
    while(1){
        
        printf("1.push\n 2.display\n3.pop\n");
        printf("Enter the choice");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the value:");
                scanf("%d",&value);
                push(&top,value);
                break;
            case 2:
                display(top);
                break;
            case 3:
                pop(&top);
                break;

            default:
                printf("wrong choice");

        }
    }
}
void push(struct node** top_ref,int new_data){
    struct node* new_node=(struct node*) malloc(sizeof(struct node));
    new_node->data=new_data;
    new_node->next=*top_ref;
    *top_ref=new_node;
}
void pop(struct node** top_ref){
    if(top==NULL){
        printf("Underflow");
    }
    else{
        struct node* move=*top_ref;
        *top_ref=(*top_ref)->next;
        printf("node deleted");
        free(move);
    }
}
void display(struct node* r){
    while(r!=NULL){
        printf("%d->",r->data);
        r=r->next;
    }
    printf("NULL\n");

}
