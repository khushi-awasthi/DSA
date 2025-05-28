#include<stdio.h>
void bubbleSort(int a[])
{
    int temp,flag;
    for(int i=0;i<5;i++){
        for(int j=0;j<5-1-i;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
    }
}
void printArray(int arr[])
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[]={12,5,19,29,36};
    bubbleSort(arr);
    printf("Sorted array:");
    printArray(arr);
    return 0;
}