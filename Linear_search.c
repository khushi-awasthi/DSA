// #include<stdio.h>
// int main(){
//     int a[5],i,s,f=0;
//     printf("Enter 10 elements");
//     for(i=0;i<5;i++)
//     scanf("%d",&a[i]);
//     printf("Enter the elements which you want to search:");
//     scanf("%d",&s);
//     for(i=0;i<5;i++)
//     if(a[i]==s){
//         printf("elements found=%d",i);
//         f=1;
//         break;
//     }
//     if(f==0)
//     printf("Element not found");
// }
#include<stdio.h>
int linearsearch(int a[],int n,int key);
int main(){
    int a[20],n,key,pos;
    printf("Enter the size of array");
    scanf("%d",&n);
    printf("Enter the elements in array");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the elements which you want to search:");
    scanf("%d",&key);
    pos=linearsearch(a,n,key);
    if(pos!=-1)
        printf("Element found at %d",pos);
    else
        printf("Element not found");
    return 0;

}
int linearsearch(int a[],int n,int key){
    if(n<0)
    return -1;
    if(a[n]==key)
    return n;
    return linearsearch(a,n-1,key);
}