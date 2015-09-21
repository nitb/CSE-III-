#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

struct node{
	int data;
	struct node* next;
};


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
	while (p != NULL)
		p = p->next;
	p->next = temp;
	temp->next = NULL;	
}

void insertpos(struct node **head,int data){
	struct node *tmp, *temp;
	tmp = *head;
	temp = (struct node*) malloc(sizeof(struct node));
	temp->data = data;
	while ((tmp->data < data) && (tmp->next != NULL)){
		tmp = tmp->next;
	}
	if (tmp->next == NULL){
		temp->next == NULL;
		tmp->next = temp;
		return;
	}
	temp->next = tmp->next;
	tmp->next = temp;	
}

void print(struct node *head){
	struct node *tmp; 
	tmp = head;
	while (tmp != NULL){
		printf("%d: ",tmp->data);
		tmp = tmp->next;
	}
}

//int binarysearch(struct node *head){



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
	print(head);
//	int key;
//	cin >> key;
//	binarysearch(head,key);
}
