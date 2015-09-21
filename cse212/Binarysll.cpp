#include<iostream>
#include<cstdio>

using namespace std;

typedef struct {
	int data;
	struct node* next;
}node;


void insertbeg(struct node **head, int data){
	struct node *temp;
	temp = (struct node*) malloc(sizeof(struct node));
	temp->data = data;
	temp->next = start;
	start = temp;
}

void insertend(struct node **head,int data){
	struct node *temp, *p;
	temp = (struct node*) malloc(sizeof(struct node));
	temp->data = data;
	p = start;
	while (p != NULL)
		p = p->next;
	temp->next = p;	
}

int binarysearch(struct node *head){

}

int main(){
	struct node *head;
	head = NULL;
	int n, data;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> data;
		insertclever(struct node **head, data);
	}
	int key;
	cin >> key;
	binarysearch(head,key);
}
