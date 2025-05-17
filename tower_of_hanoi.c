#include<stdio.h>
int towerofhanoi(int n,char s,char d,char aux){
    int count=0;
    if(n==0){
        return 0;
    }
    else{
        count+=towerofhanoi(n-1,s,aux,d);
        
        printf("Move disk %dfrom %c to %c\n",n,s,d);
        count=count+1;
        
        count+=towerofhanoi(n-1,aux,d,s);
        // count=count+1;
        
    }
    return count;
}
int main(){
    int n=3;
    char s='A';
    char d='B';
    char aux='C';
    int k=towerofhanoi(n,s,d,aux);
    printf("%d",k);
    return 0;
}
