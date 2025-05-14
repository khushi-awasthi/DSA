#include<stdio.h>
#define MAX 100;
int set [100];
int size=0;
int contains(int value){
    for(int i=0;i<size;i++){
        if(set[i]==value)
        return 1;
    }
    return 0;
}
void insert(int value){
    if(!contains(value)){
        set[size++]=value;
        printf("Inserted %d\n",value);
    }else{
        printf("Duplicate elements");
    }
}
void removeElements(int value){
    int found=0;
    for(int i=0;i<size;i++){
        if(set[i]==value){
            found=i;
        }
            for(int j=0;j<size;j++){
                set[j]=set[j+1];
            
            size--;
            printf("Remove elements%d\n",value);
            break;
        }
    }
    if(!found){
        printf("elements not found");
    }
}
void display(){
    printf("Set elements");
    for(int i=0;i<size;i++)
    printf("%d",set[i]);
    printf("\n");
}
int main(){
    insert (10);
    insert(20);
    display();
    removeElements(10);
    display();
}
