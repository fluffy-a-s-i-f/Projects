#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node*prev;
	struct node*next;
};
struct node*create(struct node*head,int n);
void display(struct node*q);
struct node* merge(struct node*head,struct node*head2);
void check(struct node*p);
void swap(struct node *a, struct node *b);
void bubblesort(struct node *head);
int main(){
	struct node*head,*head2;
	int n,m;
	printf("Enter the number of nodes for list 1: ");
	scanf("%d",&n);
	head=NULL;
	head=create(head,n);
	printf("\nEnter the number of nodes for list 2: ");
	scanf("%d",&m);
	head2=NULL;
	head2=create(head2,m);
	printf("\nList 1: ");
	display(head);
	printf("\nList 2: ");
	display(head2);
	printf("\n");
	bubblesort(head);
	printf("\nSorted List 1: ");
	display(head);
	bubblesort(head2);
	printf("\nSorted List 2: ");
	display(head2);
	head=merge(head,head2);
	printf("\n");
	printf("\nMerged list is:");
	display(head);
	bubblesort(head);
	printf("\nSorted Merged list: ");
	display(head);
	printf("\n");
	printf("\nPrinted using prev link:");
	check(head);	
}
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
struct node* merge(struct node*head,struct node*head2){
	struct node*p,*q,*r;
	p=head;
	q=head2;
	while(p->next!=NULL){
		p=p->next;
		r=p;
	}
	q->prev=r;
	r->next=q;
	return head;	
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
void swap(struct node *a, struct node *b) 
{ 
    int temp = a->data; 
    a->data = b->data; 
    b->data = temp; 
} 
void bubblesort(struct node *head) 
{ 
    int swapped, i; 
    struct node *p; 
    struct node *q = NULL; 
    if (head == NULL) 
        return; 
    do
    { 
        swapped = 0; 
        p = head; 
        while (p->next != q) { 
            if (p->data > p->next->data) { 
                swap(p, p->next); 
                swapped = 1; 
            } 
            p = p->next; 
        } 
        q=p; 
    } 
    while (swapped); 
} 

