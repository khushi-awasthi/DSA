#include<stdio.h>
#include<stdlib.h>
struct node{
    int coeff;
    int exp;
    struct node* next;
};
struct node* createNode(int coeff,int exp){
    struct node* newNode=(struct node*) malloc(sizeof(struct node));
    newNode->coeff=coeff;
    newNode->exp=exp;
    newNode->next=NULL;
    return newNode;
}

void insertTerm(struct node** poly,int coeff,int exp){
    struct node* temp= *poly;
    struct node* newNode=createNode(coeff,exp);
    if(*poly==NULL){
        *poly=newNode;
    }else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}
// function to add polynomial
struct node* addPolynomials(struct node* poly1,struct node* poly2){
    struct node* result=NULL;
    struct node** tail=&result;
    while(poly1 != NULL && poly2 != NULL){
        if(poly1->exp==poly2->exp){
            insertTerm(tail,poly1->coeff + poly2->coeff,poly1->exp);
            poly1=poly1->next;
            poly2=poly2->next;
        }else if(poly1->exp > poly2->exp){
            insertTerm(tail,poly1->coeff,poly1->exp);
            poly1=poly1->next;
        }else{
            insertTerm(tail,poly2->coeff,poly2->exp);
            poly2=poly2->next;
        }
        tail=&((*tail)->next);
    }
    // if any of poly having remaining term
    while(poly1 != NULL){
        insertTerm(tail,poly1->coeff,poly1->exp);
        poly1=poly1->next;
        tail=&((*tail)->next);
    }
    while(poly2 != NULL){
        insertTerm(tail,poly2->coeff,poly2->exp);
        poly2=poly2->next;
        tail=&((*tail)->next);
    }
    return result;
}

struct node* subPolynomials(struct node* poly1,struct node* poly2){
    struct node* result=NULL;
    struct node** tail=&result;
    while(poly1 != NULL && poly2 != NULL){
        if(poly1->exp==poly2->exp){
            insertTerm(tail,poly1->coeff - poly2->coeff,poly1->exp);
            poly1=poly1->next;
            poly2=poly2->next;
        }else if(poly1->exp > poly2->exp){
            insertTerm(tail,poly1->coeff,poly1->exp);
            poly1=poly1->next;
        }else{
            insertTerm(tail,-poly2->coeff,poly2->exp);
            poly2=poly2->next;
        }
        tail=&((*tail)->next);
    }
    // if any of poly having remaining term
    while(poly1 != NULL){
        insertTerm(tail,poly1->coeff,poly1->exp);
        poly1=poly1->next;
        tail=&((*tail)->next);
    }
    while(poly2 != NULL){
        insertTerm(tail,poly2->coeff,poly2->exp);
        poly2=poly2->next;
        tail=&((*tail)->next);
    }
    return result;
}

void displayPolynomial(struct node* poly){
    if(poly==NULL){
        printf("0\n");
        return;
    }
    while(poly != NULL){
        printf("%dx^%d",poly->coeff,poly->exp);
        if(poly->next!=NULL){
            printf("+");
        }
        poly=poly->next;
    }
    printf("\n");
}
int main(){
    struct node* poly1=NULL;
    struct node* poly2=NULL;
    
    // insert term in first poly
    insertTerm(&poly1,5,2);
    insertTerm(&poly1,4,1);
    insertTerm(&poly1,2,0);
    // insert term in second poly
    insertTerm(&poly2,-3,3);
    insertTerm(&poly2,2,1);
    insertTerm(&poly2,1,0);
    printf("First Polynomial:");
    displayPolynomial(poly1);
    printf("Second Polynomial:");
    displayPolynomial(poly2);
    struct node* sum= addPolynomials(poly1,poly2);
    printf("Sum of polynomials:");
    displayPolynomial(sum);
    struct node* sub= subPolynomials(poly1,poly2);
    printf("Subtraction of polynomials:");
    displayPolynomial(sub);
    return 0;
}
