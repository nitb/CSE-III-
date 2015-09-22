#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
struct node{
	int data;
	struct node* next;
};
void print(struct node*);
void insertbeg(struct node **head, int data){
	struct node *temp;
	temp = (struct node* ) malloc(sizeof(struct node));
	temp->data = data;
	temp->next = *head;
	*head = temp;
}
void insertend(struct node **head,int data){
	struct node *temp, *p;
	temp = (struct node*) malloc(sizeof(struct node));
	temp->data = data;
	p = *head;
	while (p->next != NULL)
		p = p->next;
	p->next = temp;
	temp->next = NULL;	
}
void insertpos(struct node **head,int data){
	struct node *tmp, *temp;
	tmp = *head;
	int flag = 0;
	temp = (struct node*) malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	if (tmp->data > data){
		insertbeg(&*head,data);
		print(*head);
		return;
	}
	while ((tmp->next != NULL) && (tmp->next->data < data)) 
	{	tmp = tmp->next;
		flag++;
	}
	if (flag >= 0 && tmp->next != NULL){	
		temp->next = tmp->next;
		tmp->next = temp;
		print(*head);
		return;
	}
	else{
		if (tmp->data < data){
			insertend(&*head,data);
			print(*head);
		}
	}
}

void print(struct node *head){
	struct node *tmp; 
	tmp = head;
	while (tmp != NULL){
		printf("%d: ",tmp->data);
		tmp = tmp->next;
	}
}
int main(){
	struct node *head;
	head = NULL;
	int n, data, counter = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		counter++;
		cin >> data;
		if (counter == 1)
			insertbeg(&head, data);
		else
			insertpos(&head, data);
	}
	return 0;
}
