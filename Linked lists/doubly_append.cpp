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
	printf("Enter head: ");
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
struct node* append_start(struct node*head){
	struct node*p;
	p=(node*)malloc(sizeof(node));
	p->next=NULL;
	printf("\nEnter number to be append at start:");
	scanf("%d",&p->data);
	p->next=head;
	p->prev=NULL;
	head->prev=p;
	head=p;
	return head;
}
struct node*append_end(struct node*head){
	struct node*p,*q,*r;
	q=head;
	p=(node*)malloc(sizeof(node));
	p->next=NULL;
	printf("\nEnter number to be append at end:");
	scanf("%d",&p->data);
	while(q->next!=NULL){
		q=q->next;
		r=q;
	}
	r->next=p;
	p->prev=r;
	return head;
}

int main(){
	struct node*head,*p;
	int n,choice;
	printf("Enter the number of nodes: ");
	scanf("%d",&n);
	head=NULL;
	head=create(head,n);
	printf("Created List: ");
	display(head);
	head=append_end(head);
	head=append_start(head);
	printf("\nList after append: ");
	display(head);
	printf("\nPrinted usin prev link: ");
	check(head);
}
