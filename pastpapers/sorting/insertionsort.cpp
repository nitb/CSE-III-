#include<iostream>
#define MAX 100
int main(){
  int arr[MAX], n, k;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  /*Insertion Sort*/
  for (int i = 1; i < n; i++){
    k = arr[i];
    for (int j = i-1; j >= 0 && k < arr[j]; j++)
      arr[j+1] = arr[j];
    arr[j+1] = k;
  }
  //Array is now sorted.
  for(int i = 0; i < n; i++)
    cout << arr[i];
  return 0;
}
