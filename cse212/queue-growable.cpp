#include<iostream>
#include<stdlib.h>
using namespace std;
class queue
{
  int front, rear, size;
  unsigned capacity;
  int *arr;
public:
  queue(unsigned capacity);
  int isFull();
  int isEmpty();
  void enqueue(int item);
  int delete()
}

queue::queue(unsigned capacity)
{
  int size;
  front = rear = -1;
  this->capacity = capacity;
  rear = capacity-1;
  arr = (int*) malloc(capacity*sizeof(int));
}

int queue::isFull()
{
  return (size == capacity-1);
}

int queue::isEmpty()
{
  return (size == 0);
}

void queue::enqueue(int item)
{
  if (isFull())
    return;
  rear =(rear + 1) % capacity;
  arr[rear] = item;
  size++;
}

int queue::delete()
{ int item;
  if (isEmpty())
    return INT_MIN;
  front = ((front + 1) % capacity);
  item = arr[front];
  size--;
  return item;
}
