#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
using namespace std;
struct Stack
{
	int top;
	unsigned capacity;
	int* arr;
};

struct Stack* CreateStack(unsigned capacity)
{
	Stack* stack=new Stack;
	stack->capacity=capacity;
	stack->top=-1;
	stack->arr=(int*) malloc(stack->capacity*sizeof(int));
	return stack;
}

int isFull(struct Stack* stack)
{
	return stack->top==stack->capacity-1;	
}

int isEmpty(struct Stack* stack)
{
	return stack->top==-1;
}

int push(struct Stack* stack, int item)
{
	if (isFull(stack))
		return 1;
	stack->arr[++stack->top]=item;
	return 0;
}

int pop(struct Stack* stack)
{
	if(isEmpty(stack))
		return 0;
	return stack->arr[stack->top--];
}

int peek(struct Stack* stack)
{
	if(isEmpty(stack))
		return INT_MIN;
	return stack->arr[stack->top];
}

int main()
{	int x,y;
	cin>>x;
	struct Stack* temp=CreateStack(x);
	char ans='Y';
	int item,flag=0;
	do{
		cout<<"Enter the element to push onto stack: ";
		cin>>item;
		flag=push(temp,item);
		if (flag==1)
		{	struct Stack* temp_stack=CreateStack(x);
			x*=2;
			struct Stack* NewStack=CreateStack(x);
			while (isEmpty(temp)==0)
			{	y=pop(temp);
				push(temp_stack,y);
			}
			while(isEmpty(temp_stack)==0)
			{	y=pop(temp_stack);
				cout<<y<<endl;
				push(NewStack,y);
			}
			free (temp_stack);
			free (temp);
			temp=NewStack;
			push(temp,item);
			cout<<peek(temp)<<endl;			
		}
		cout<<"Press Y to continue: ";
		cin>>ans;
		cout<<peek(temp)<<endl;
	}while(ans=='Y'|| ans=='y');
	cout<<peek(temp);
	return 0;
}
