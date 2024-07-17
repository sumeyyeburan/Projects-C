// Last In First Out (LIFO) 

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *top=NULL;

void push(int value){
	struct node *number=(struct node *)malloc(sizeof(struct node));
	if (number == NULL) {
        printf("\nMemory allocation failed !\n");
        return;
    }
    
	number->data=value;
	
	if(top==NULL){
		number->next=NULL;
	}
	else{
		number->next=top;
	}
	top=number;
}

void pop(){
	if(top==NULL){
		printf("\nThe stack is empty !\n");
	}
	else{
		printf("\n %d deleted !\n",top->data);
		struct node *temp=top;
		top=top->next;
		free(temp);
	}
}

void show_top(){
	if(top==NULL){
		printf("\nThe stack is empty !\n");
	}
	else{
		printf("\nThe top eleman is %d. \n",top->data);
	}
}

void display(){
	if(top==NULL){
		printf("\nThe stack is empty !\n");
	}
	else{
		struct node *temp=top;
		
		printf("\nStack\n");
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
		printf("1-Push\n");
		printf("2-Pop\n");
		printf("3-Show top\n");
		printf("4-Display\n");
		printf("5-Exit\n");
		printf("\nPlease enter option: ");
		scanf("%d",&op);
		
		switch(op){
			case 1:
				printf("\nPlease enter the number you want to add: ");
				scanf("%d",&num);
				push(num);
				break;
			case 2:
				pop();
				break;
			case 3:
				show_top();
				break;
			case 4:
				display();
				break;
			case 5:
				printf("\nExiting...\n");
				exit(0);
			default:
				printf("\nInvalid input!\n");
		}
		
	}while(1);
	
	return 0;
}


