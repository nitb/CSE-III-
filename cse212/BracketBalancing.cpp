#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

using namespace std;
struct Stack
{
  int top;
  unsigned capacity;
  char* arr;
};

struct Stack* createStack(unsigned capacity){
  struct Stack* stack=(struct Stack*) malloc(sizeof(Stack));
  stack->capacity=capacity;
  stack->arr=(char*) malloc(stack->capacity*sizeof(char));
  stack->top=-1;
  return stack;
}

int isEmpty(struct Stack* stack){
  return stack->top==-1;
}

int isFull(struct Stack* stack){
  return stack->top==stack->capacity-1;
}

void push(struct Stack* stack, char item){
    if (isFull(stack))
      return;
    stack->arr[++stack->top]=item;
}

char pop(struct Stack* stack){
  if (isEmpty(stack))
    return '$';
  return stack->arr[stack->top--];
}

char peek(struct Stack* stack){
  if (isEmpty(stack))
    return '$';
  return stack->arr[stack->top];
}
int matchIt(struct Stack* stack, char item){
  if ( peek(stack)=='(' && item==')' )
    return 1;
  else if ( peek(stack)=='[' && item==']' )
    return 1;
  else if ( peek(stack) =='{' && item=='}' )
    return 1;
  else
    return 0;
}
int main()
{
  unsigned capacity;
  int i=0,flag=1;
  char str[20];
  cin>>str;
  capacity=strlen(str);
  struct Stack* stack=createStack(capacity);
  for(i=0;i<strlen(str);i++){
    if ( str[i]=='(' || str[i]=='{' || str[i]=='[' )
      push(stack,str[i]);
    else if ( str[i]==')' || str[i]=='}' || str[i]==']' ){
      if (!isEmpty(stack) && matchIt(stack,str[i]) )
        pop(stack);
      else if (isEmpty(stack))
        flag=0;
    }
  }
  if (isEmpty(stack) && flag==1)
    cout<<"Balanced";
  else
    cout<<"Unbalanced";
  return 0;
}
