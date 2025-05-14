#include <iostream>
using namespace std;
int main(){
    int num[]={5,10,23,78,45,-2};
    int size=6;
    int smallest = INT16_MAX;
    int largest = INT16_MIN;
    for(int i=0;i<size;i++){
        // if(num[i] < smallest){
        //     smallest =num[i];

        // }
        smallest=min(num[i],smallest);
        largest=max(num[i],largest);
    }
    cout << "smallest=" << smallest <<endl;
    cout << "largest=" << largest <<endl;
    return 0;
}