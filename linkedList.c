#include <stdio.h>
#include <stdlib.h>  //bellek ayýrma fonk için

void insertBeg();
void insertEnd();
void deleteBeg();
void deleteEnd();
void display();

struct node{
	int data;
	struct node *next;
};

struct node *first=NULL;
struct node *last=NULL;

int main(){
	int op;
	
	do{
		printf("\n\n------------------------------------------\n");
		printf("\n**** MENU *****\n");
		printf("\n1-Insert data beginning\n");
		printf("2-Insert data end\n");
		printf("3-Delete data beginning\n");
		printf("4-Delete data end\n");
		printf("5-Display\n");
		printf("6-Exit\n");
		
		printf("\nPlease enter your option: ");
		scanf("%d",&op);
		
		switch(op){
			case 1:
				insertBeg();
				break;
			case 2:
				insertEnd();
				break;
			case 3:
				deleteBeg();
				break;
			case 4:
				deleteEnd();
				break;
			case 5:
				display();
				break;
			case 6:
				printf("\nExiting...\n");
				exit(0);
			default:
				printf("\nInvalid input!\n");	
		}
			
	}while(op<=6 && op>0);
	
	return 0;
} 

void insertBeg(){
	struct node *newNode=(struct node *)malloc(sizeof(struct node));
	
	int number;
	printf("\nPlease enter value: ");
	scanf("%d",&number);
	
	newNode->data=number;
	
	if(first==NULL){
		newNode->next=NULL;
		first=last=newNode;
		printf("\nNode created !\n");
	} else{
		newNode->next=first;
		first=newNode;
		printf("\nNew node added !\n");
	}
}

void insertEnd(){
	struct node *newNode=(struct node *)malloc(sizeof(struct node));
	
	int number;
	printf("\nPlease enter value: ");
	scanf("%d",&number);
	
	newNode->data=number;
	
	if(first==NULL){
		newNode->next=NULL;
		first=last=newNode;
		printf("\nNode added !\n");
	} else{
		newNode->next=NULL;
		last->next=newNode;
		last=newNode;
		printf("\nNew node added !\n");
	}
}

void deleteBeg(){
	if(first==NULL){
		printf("\nList is empty\n");
	}
	else{
		struct node *temp=first;
		first=first->next;
		free(temp);
		printf("\nNode deleted  from the beginning !\n");
	}
}

void deleteEnd(){
	if(first==NULL){
		printf("\nList is empty !\n");
	}
	else if(first->next==NULL){
		first=last=NULL;
		free(first);
		free(last);
		printf("\nDeleted a single node of the list !\n");
	}
	else{
		struct node *current=first;
		struct node *temp=last;
		
		while(current->next!=last){
			current=current->next;
		}
		
		free(temp);
		last=current;
		last->next=NULL;
		printf("\Node deleted from the last !\n");
	}
}

void display(){
	if(first==NULL){
		printf("\nList is empty !\n");
	}
	else{
		struct node *temp=first;
		
		printf("\nNodes\n");
		while(temp!=NULL){
			printf("%d\t",temp->data);
			temp=temp->next;
		}
	}
}

