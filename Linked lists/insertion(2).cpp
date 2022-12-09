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
void display(struct node*p){
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
void insert(struct node*head){
	struct node*p,*q,*r;
	int loc;
	p=(node*)malloc(sizeof(node));
	printf("\nEnter the position node to be inserted: ");
	scanf("%d",&loc);
	printf("Enter data to be inserted: ");
	scanf("%d",&p->data);
	q=head;
	if(loc==1){
		p->prev=NULL;
		p->next=q;
		q->prev=p;
		head=p;
	}
	else{
		for(int i=1;i<loc;i++){
		if(q!=NULL){
			q=q->next;
		}
		else{
			printf("Overflow");
			break;	
		}
	    }
	    p->next=q->next;
	    p->prev=q->prev;
	    q->prev=p;	      
	}
	printf("List after insertion: ");
	display(head);
}
int main(){
	struct node*head,*p;
	int n;
	printf("Enter the number of nodes: ");
	scanf("%d",&n);
	head=NULL;
	head=create(head,n);
	printf("List before insertion: ");
	display(head);
	insert(head);
}
