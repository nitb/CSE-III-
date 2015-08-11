#include<iostream>

#define SIZE 20
class queue
{
  int a[SIZE];
  int front;
  int rear;
public:
  queue();
  ~queue();
  void insert(int i);
  int remove();
  int isempty();
  int isfull();
};

queue::queue()
{
  front=rear=0;
}

queue::~queue()
{
  delete []a;
}

void queue::insert(int i)
{
  if (isfull())
  {
    //Message.
    return;
  }
  a[rear] = i;
  rear++;
}

int queue::remove()
{
  if (isempty())
  {
    //Messsage.
    return 1;
  }
  return (a[front++]);
}

int queue::isempty()
{
  if (front == rear)
    return 1;
  else
    return 0;
}

int queue::isfull()
{
  if (rear == SIZE)
    return 1;
  else
    return 0;
}
