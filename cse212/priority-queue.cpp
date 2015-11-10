#include<iostream>
#include<stdio.h>
#include<stdlib.h>
struct node{
  int priority;
  int info;
  struct node* link;
}*front = NULL;

int isEmpty(){
  if (front == NULL)
    return 1;
  else
    return 0;
}

void insert(int item, int item_priority){
  struct node *tmp, *p;
  tmp = (struct node*) malloc(sizeof(struct node));
  if (tmp == NULL){
    printf("Memory not avialable\n");
    return;
  }
  tmp->info = item;
  tmp->priority = item_priority;
  if (isEmpty() || item_priority < front->priority){
    tmp->link = front;
    front = tmp;
  }
  else{
    p = front;
    while (p->link != NULL && p->link->priority <= item_priority)
      p = p->link;
    tmp->link = p->link;
    p->link = tmp;
  }
}

int del(){
  struct node *tmp;
  int item;
  if (isEmpty()){
    printf("Queue Underflow");
    exit(0);
  }
  else{
    tmp = front;
    item = tmp->info;
    front = front->link;
    free(tmp);
  }
  return item;
}

void display(){
  struct node *ptr;
  ptr = front;
  if (isEmpty())
    printf("Queue is empty");
  else{
    printf("Queue is :\n");
    printf("Priority Item\n");
    while (ptr != NULL){
      printf("%5d %5d\n",ptr->priority,ptr->info);
      ptr = ptr->link;
    }
  }
}

int main(){
  return 0;
}
