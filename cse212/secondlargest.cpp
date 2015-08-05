#include <iostream>
using namespace std;

int secondLargest(int a[], int size) {
int currentMax = a[0];
int secondMax=0;
for( int i = 0; i< size; i++) {
    if (a[i] > secondMax)
        secondMax = a[i];

    if (a[i] > currentMax){
        secondMax=currentMax;
        currentMax=a[i];
    }
}

return secondMax;
}
int main () {


int a[10]={1,2,3,4,5,6,7,8,9,10};
for (int i=0; i<10;i++)
{
  cout<<a[i]<<" ";
}

cout << "\nThe second largest of the array is :" << secondLargest(a,10) << endl;

return 0;
}
