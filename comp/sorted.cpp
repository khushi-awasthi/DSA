
#include <bits/stdc++.h>

using namespace std;

bool isSorted(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[i])
        return false;
    }
  }

  return true;
}

int main() {

  int arr[] = {1, 2, 3, 4, 5}, n = 5;
  bool ans = isSorted(arr, n);
  if (ans) cout << "True" << endl;
  else cout << "False" << endl;
  return 0;
}


// optimal---------------->

// #include<bits/stdc++.h>

// using namespace std;

// bool isSorted(int arr[], int n) {
//   for (int i = 1; i < n; i++) {
//     if (arr[i] < arr[i - 1])//compare each element if anyone is smaller than previous one then array is not sorted
//       return false;
//   }

//   return true;
// }

// int main() {

//   int arr[] = {1, 2, 3, 4, 5}, n = 5;

//   printf("%s", isSorted(arr, n) ? "True" : "False");

// }

