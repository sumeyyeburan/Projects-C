#include <stdio.h>

int factorial(int f){
	
	if(f==0 || f==1)
		return 1;
	
	return f*factorial(f-1);
}

int main(void){
	int fac;
	
	again:
	printf("\nFaktoriyelinin hesaplanmasini istediginiz sayiyi giriniz:\n");
	scanf("%d",&fac);
	
	if(fac<0){
		printf("\n%d sayisinin faktoriyeli hesaplanamaz,tekrar deneyiniz!\n\n",fac);
		goto again;
	}
	
	printf("\n%d! = %d\n",fac,factorial(fac));
	
	return 0;
}
