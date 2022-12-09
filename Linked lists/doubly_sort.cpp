#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node*next,*prev;
};
struct node*create(struct node*head,int n){
	struct node*p,*q;
	head=(node*)malloc(sizeof(node));
	printf("Enter head: ");
	scanf("%d",&head->data);
	p=head;
	p->prev=NULL;
	for(int i=1;i<n;i++){
		p->next=(node*)malloc(sizeof(node));
		q=p;
		p=p->next;
		p->prev=q;
		printf("Enter data: ");
		scanf("%d",&p->data);
		p->next=NULL;
	}
	return head;
}
void print(struct node*p){
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
}
void check(struct node*head){
	struct node*p;
	while(head->next!=NULL){
		head=head->next;
		p=head;
	}
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->prev;
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
  
    /* Checking for empty list */
    if (head == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        p = head; 
  
        while (p->next != q) 
        { 
            if (p->data > p->next->data) 
            { 
                swap(p, p->next); 
                swapped = 1; 
            } 
            p = p->next; 
        } 
        q=p; 
    } 
    while (swapped); 
} 


main(){
	struct node*head;
	head=NULL;
	int n;
	printf("Enter the number of nodes: ");
	scanf("%d",&n);
	head=create(head,n);
	printf("\nList brfore sorting: ");
	print(head);
    printf("\nList after sorting: ");
	bubblesort(head);
	print(head);
	printf("\n\n");
	check(head);
}	

