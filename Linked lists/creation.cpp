#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};

struct node*create(node*head,int n){
	struct node *p;
	head=(node*)malloc(sizeof(node));
	printf("Enter first value: ");
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

int main(){
	struct node*head,*p;
	int n;
	printf("Enter the number of nodes: ");
	scanf("%d",&n);
	head=NULL;
	p=create(head,n);
	while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
