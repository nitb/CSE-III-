#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
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

void push(struct Stack* stack, int item)
{
	if (isFull(stack))
		return;
	stack->arr[++stack->top]=item;
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
{
	struct Stack* stack=CreateStack(100);
	push(stack,10);
	push(stack,20);
	push(stack,30);
	printf("%d",pop(stack));
	printf("%d",peek(stack));
	return 0;

}
