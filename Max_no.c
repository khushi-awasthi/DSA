// #include<stdio.h>
// int main(){
//     int a[10],i,max;
//     printf("Enter elements");
//     for(i=0;i<10;i++)
//     scanf("%d",&a[i]);
//     max=a[0];
//     for(i=0;i<10;i++)
//     if(a[i]>=max)
//     max=a[i];
//     printf("\nmaximum number= %d",max); 
// }

#include <stdio.h>

int max(int a, int b)
{
    return a>b?a:b ;
}

int findMaxRec(int A[], int n)
{
    if (n == 1)
        return A[0];
    return max(A[n-1], findMaxRec(A, n-1));
}
int main()
{
    int arr[] = {10,99,67,45,88};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Largest in given array is %d", findMaxRec(arr, n));
    return 0;
}