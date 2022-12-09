#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};
struct node*create(node*head,int n);
void insert(struct node*head);
void print(struct node *p);
node *deletion(node*head,int loc);

int main(){
	struct node*head,*p;
	int n,loc;
	printf("Enter the number of nodes: ");
	scanf("%d",&n);
	head=NULL;
	head=create(head,n);
	p=head;
	printf("Before insertion: ");
	print(head);
	
	insert(p);
	
	 
}

struct node*create(node*head,int n){
	struct node *p;
	head=(node*)malloc(sizeof(node));
	printf("Enter data:");
	scanf("%d",&head->data);
	p=head;
	for(int i=1;i<n;i++){
		p->next = (node*)malloc(sizeof(node));
		p=p->next;
		printf("Enter data:");
		scanf("%d",&p->data);
		p->next=NULL;
	}
	return head;
}
void print(struct node *p){

	 while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
void insert(struct node*head){
	struct node *p,*q;
	int loc;
	p=(node*)malloc(sizeof(node));
	printf("\nEnter the location where number is inserted: ");
	scanf("%d",&loc);
	printf("Enter the number to be inserted: ");
	scanf("%d",&p->data);
	p->next=NULL;
	q=head;
	if(loc==1){
		p->next=q;
		head=p;
	}
	else{
	for(int i=1;i<loc-1;i++){
		if(q!=NULL){
			q=q->next;
		}
		else{
			printf("Overflow");
			
		}
		
	}
	p->next = q->next;
	q->next = p;
	}	
	print(head);
	
}



