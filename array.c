#include <stdio.h>
#include <stdlib.h>

void ascending(int array[],int size);
void descending(int array[],int size);
void swap(int *x,int *y);

int main(){
	int array[20],size,i,choice;
	
	printf("\nPlease enter size of the array: ");
	scanf("%d",&size);
	
	if(size<=0 || size>20){
		printf("\nInvalid input!\n");
		exit(0);
	}
	
	printf("\nPlease enter elements of the array...\n");
	for(i=0;i<size;i++){
		printf("[%d]: ",i);
		scanf("%d",&array[i]);
	}
	
	printf("\nArray in original order\n");
	for(i=0;i<size;i++){
		printf("%d\t",array[i]);
	}
	
	printf("\n\nEnter 1 to sort in ascending order, 2 to sort in descending order: ");
	scanf("%d",&choice);
	
	if (choice != 1 && choice != 2) {
    	printf("\nInvalid input!\n");
    	exit(0);
	}
	
	if(choice==1){
		ascending(array,size);
	}
	else{
		descending(array,size);
	}
	
	printf("\nOrdered array\n");
	for(i=0;i<size;i++){
		printf("%d\t",array[i]);
	}
	printf("\n");
	return 0;
}

void ascending(int array[],int size){
	int i,j;
	
	for(i=0;i<size-1;i++){
		for(j=0;j<size-i-1;j++){
			if(array[j]>array[j+1]){
				swap(&array[j],&array[j+1]);
			}
		}
	}
}

void descending(int array[],int size){
	int i,j;
	
	for(i=0;i<size-1;i++){
		for(j=0;j<size-i-1;j++){
			if(array[j]<array[j+1]){
				swap(&array[j],&array[j+1]);
			}
		}
	}
}

void swap(int *x,int *y){
	int temp;
	
	temp=*x;
	*x=*y;
	*y=temp;
}

