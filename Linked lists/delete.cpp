#include<stdio.h>
#include<stdlib.h>


struct node{
	int data;
	struct node* next;
};
struct node*create(node*head,int n);
void print(struct node *p);
node *deletion(node*head,int loc);


int main(){
	struct node*head,*p;
	int n,loc;
	printf("Enter the number of nodes: ");
	scanf("%d",&n);
	head=NULL;
	head=create(head,n);
	printf("Enter the location where number is deleted: ");
	scanf("%d",&loc);
	head=deletion(head,loc);
	p=head;
	print(p);
	 
}
struct node*create(node*head,int n){
	struct node *p;
	head=(node*)malloc(sizeof(node));
	printf("Enter data: ");
	scanf("%d",&head->data);
	p=head;
	for(int i=1;i<n;i++){
		p->next = (node*)malloc(sizeof(node));
		p=p->next;
		printf("Enter data: ");
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
node *deletion(node*head,int loc){
	struct node *p,*q;
	q=head;
	if(loc==1){
		p=head;
		head=head->next;
		free(p);
		return (head);
	}
	for(int i=1;i<loc-1;i++){
		if(q!=NULL){
			q=q->next;
		}
		else{
			printf("Underflow");
		}
	}
	p=q->next;
	q->next=p->next;
	free(p);
	return (head);
}



