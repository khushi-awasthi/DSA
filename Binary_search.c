// #include<Stdio.h>
// int main(){
//     int a[5],i,j,s,l,h,m,f=0;
//     printf("Enter 5 elements");
//     for(i=0;i<4;i++)
//     scanf("%d",&a[i]);
//     printf("Enter the element which you want to search:");
//     scanf("%d",&s);
//     l=0;
//     h=4;
//     while(l<=h){
//         m=(l+h)/2;
//         if(a[m]==s){
//             printf("no.found:%d",m);
//             f=1;
//             break;
//         }
//         else if(a[m]<s)
//             l=m+1;
//         else
//             h=m-1;
//     }
//     if(f==0)
//     printf("no. not found");
//     }
#include<stdio.h>
int Binarysearch(int a[],int l,int h,int s){
    if (l <= h) 
{
        int m=(l+h)/2;
    if(a[m]==s)
        return m;
    if(a[m]>s)
        return Binarysearch(a,l,m-1,s);
    return Binarysearch(a,m+1,h,s);
    }
    return -1;
}

int main(){
    int a[]={1,2,3,4,5};
    int s=5;
    int n = sizeof(a) / sizeof(a[0]);  

    int pos=Binarysearch(a,0,n-1,s);
    if(pos==-1){
        printf("Element not found");

    }
    else {
        printf("Element found at:%d",pos);
    }
    return 0;
}
