
#include<bits/stdc++.h>

using namespace std;
int removeDuplicates(int arr[], int n) {
  set < int > set;//set of ingegers named set(set automatically store unique values in sorted order)
  for (int i = 0; i < n; i++) {
    set.insert(arr[i]);
  }
  int k = set.size();//store the number of unique elements in k
  int j = 0;
  for (int x: set) //Loops through all unique elements in the set and copies them back into the array starting from index 0.
  {
    arr[j++] = x;
  }
  return k;//return new size after removing duplicates
}
int main() {
  int arr[] = {1,1,2,2,2,3,3,6,8,8};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k = removeDuplicates(arr, n);
  cout << "The array after removing duplicate elements is " << endl;
  for (int i = 0; i < k; i++) {
    cout << arr[i] << " ";
  }
}

