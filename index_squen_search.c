#include<stdio.h>

void indexSequentialSearch(int arr[],int n,int k){
    int gn=3;
    int elements[gn],indices[gn],i,set=0;
    int j=0,ind=0,start,end;
    for(i=0;i<n;i+=3){
        elements[ind]=arr[i];
        indices[ind]=i;
        ind++;
    }
    if(k<elements[0]){
        printf("Not found");
        exit(0);
    }else{
        for(i=1;i<=ind;i++)
        if(k<=elements[i]){
            start=indices[i-1];
            end=indices[i];
            set=1;
            break;
        }
    }
    if(set==0){
        start=indices[gn-1];
        end=gn;
    }
    for(i=start;i<=end;i++){
        if(k==arr[i]){
            j=1;
            break;
        }
    }
    if(j==1)
        printf("Found index at %d",i);
    else
        printf("Not found");
}
int main(){
    int a[]={10,11,12,13,14,15,16,17,18};
    // int result;
    indexSequentialSearch(a,9,16);

}