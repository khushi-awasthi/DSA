#include<stdio.h>
void insertionSort(int a[],int n){
    // int i,k;
    for(int i=1;i<10;i++){
    int k=a[i];
    int j=i-1;
    while (j>=0 && a[j] > k){
        a[j+1]=a[j];
        j=j-1;
    }
 a[j+1]=k;
}  
}
void display(int A[],int n){
    for(int i=0;i<n;i++){
        printf("%d->",A[i]);
    }
}
int main(){
    int A[]={10,9,8,7,6,5,4,3,2,1};
    insertionSort(A,10);
    display(A,10);    
    }

// #include<stdio.h>
// #include<stdlib.h>
// void insertion_sort(int arr[]){
// 	for(int i = 1; i< 10 ; i++){
// 	    int	key = arr[i];
// 	    int j = i-1;
// 	    while(j >=0 && arr[j] > key){
// 	    	arr[j+1] =arr[j];
// 	    	j = j-1;
	    	
// 		}
// 		arr[j+1] = key;
// 	}
// }

// void display(int arr[]){
// 	for(int i =0 ; i< 10 ;i++){
// 		printf("%d-",arr[i]);
// 	}
// }

// int main(){
// 	int arr[]= {10,9,8,7,6,5,4,3,2,1};
// 	insertion_sort(arr);
// 	display(arr);
	 
	
// }

