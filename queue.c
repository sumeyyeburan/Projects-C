// First In First Out (FIFO)

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;
struct node *temp=NULL;

void enqueue(int value){
	struct node *number=(struct node *)malloc(sizeof(struct node));
	
	if (number == NULL) {
        printf("\nMemory allocation failed!\n");
        return;
    }
	
	number->data=value;
	number->next=NULL;
	
	if(rear==NULL){
		front=rear=number;
	}
	else{
		rear->next=number;
		rear=number;
	}
	printf("\n%d added to the queue\n", value);
}

void dequeue(){
	
	if(front==NULL){
		printf("\nThe queue is empty !\n");
	}
	
	temp=front;
	front=front->next;
	
	if(front==NULL){
		rear=NULL;
	}
	
	printf("\n%d deleted from the queue\n", temp->data);
    free(temp);
}

void  display(){
	if(front==NULL){
		printf("\nThe queue is empty !\n");
	}
	else{
		temp=front;
		printf("\nQueue\n");
		while(temp!=NULL){
			printf("%d\t",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}

int main(){
	int op;
	int num;
	
	do{
		printf("\n===================================\n");
		printf("\n**** THE MENU ****\n\n");
		printf("1-Enqueue\n");
		printf("2-Dequeue\n");
		printf("3-Display\n");
		printf("4-Exit\n");
		printf("\nPlease enter option: ");
		scanf("%d",&op);
		
		switch(op){
			case 1:
				printf("\nPlease enter the number you want to add: ");
				scanf("%d",&num);
				enqueue(num);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("\nExiting...\n");
				exit(0);
			default:
				printf("\nInvalid input!\n");
		}
	}while(1);
	
	return 0;
}
