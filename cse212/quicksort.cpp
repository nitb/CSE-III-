#include <iostream>
#include<string.h>
using namespace std;

void mySwap(int& num1, int& num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void myQsort(int myArray[], int min, int max){
    int pivot = myArray[(min + max) / 2];

    int left = min, right = max;

    while (left < right) {
        while (myArray[left] < pivot) {
            left++;
        }
        while (myArray[right] > pivot) {
            right--;
        }

        if (left <= right) {
            mySwap(myArray[left], myArray[right]);
            left++;
            right--;
        }
    }

    if (min < right) {
        myQsort(myArray, min, right);
    }
    if (left < max) {
        myQsort(myArray, left, max);
    }
}

int main()
{
    int myArray[] = {1, 12, -5, 260, 7, 14, 3, 7, 2};
    int min = 0;
    int max = sizeof(myArray) / sizeof(int);
    cout<<"Array before Quicksort: ";
    for (int i=0; i<9;i++){
      cout<<" "<<myArray[i];
    }
    myQsort(myArray, min, max-1);
    cout<<"\nAfter Quicksort: ";
    for (int i = 0; i < max; i++) {
        cout<<myArray[i]<<" ";
    }

    return 0;
}
