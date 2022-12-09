#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node*prev;
	struct node*next;
};

struct node*create(struct node*head,int n){
	struct node *p,*q;
	head = (node*)malloc(sizeof(node));
	printf("Enter data: ");
	scanf("%d",&head->data);
	p=head;
	p->prev=NULL;
	for(int i=1;i<n;i++){
		q=p;
		p->next=(node*)malloc(sizeof(node));
		p=p->next;
		p->prev=q;
		printf("Enter data: ");
	    scanf("%d",&p->data);
	    p->next=NULL;
	}
	return head;
}
void display(struct node*q){
	while(q!=NULL){
		printf("%d ",q->data);
		q=q->next;
	}
}
void check(struct node*p){
	struct node*q;
	while(p->next!=NULL){
		p=p->next;
		q=p;
	}
	while(q!=NULL){
		printf("%d ",q->data);
		q=q->prev;
	}
}

int main(){
	struct node*head,*p;
	int n;
	printf("Enter the number of nodes: ");
	scanf("%d",&n);
	head=NULL;
	head=create(head,n);
	printf("Created List: ");
	display(head);
	printf("\nPrinted usin prev link: ");
	check(head);
}
