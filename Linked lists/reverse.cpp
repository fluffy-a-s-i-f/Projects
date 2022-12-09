#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node*next;
};

node*create(struct node*head,int n){
	struct node *p;
	head=(node*)malloc(sizeof(node));
	printf("Enter head: ");
	scanf("%d",&head->data);
	p=head;
	for(int i=1;i<n;i++){
	    p->next=(node*)malloc(sizeof(node));
		p=p->next;
		printf("Enter Data: ");
		scanf("%d",&p->data);
		p->next=NULL;
	}
	return head;
}
void display(struct node*p){
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
}
node*reverse(struct node*head){
	struct node* r=NULL;
	struct node* p=head;
	struct node* q;
	while(p!=NULL){
		q = p->next;
		p->next = r;
		r=p;
		p=q;
	}
	return r;
}
int main(){
	struct node*head,*p;
	int n;
	printf("Enter No. of nodes: ");
	scanf("%d",&n);
	head=NULL;
	head = create(head,n);
	printf("Before reversing: ");
	display(head);
	printf("\n");
	printf("After reversing: ");
	head = reverse(head);
	display(head);
}
