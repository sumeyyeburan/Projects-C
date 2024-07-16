#include <stdio.h>
#include <stdlib.h> // exit fonksiyonu için gerekli

void armstrong_number();
void fibonacci_number();
void polindrome_number();
void info();

int main(){
	int op;
	 // sonsuz dongu
	while(1){
		
		printf("\n-----------------------------------------------------\n");
		printf("\n1.Armstrong Sayi\n2.Fibonacci Dizisi\n3.Polindrom Sayi\n4.Bilgi\n5.Cikis\n\nYapmak istediginiz islemin numarasini giriniz: ");
		scanf("%d",&op);
		
		switch(op){
			case 1:
				armstrong_number();
				break;
			case 2:
				fibonacci_number();
				break;
			case 3:
				polindrome_number();
				break;
			case 4:
				info();
				break;
			case 5:
				printf("\nProgramdan cikiliyor...\n");
				exit(0);
				break; //teknik olarak  gerekli deðil.Okunabilirlik açýsýndan eklenmiþtir.
			default:
				printf("\nGecersiz secim. Lutfen tekrar deneyin.\n\n");
		}	
	}
	return 0;
}

void armstrong_number(){
	printf("\n\n**** Armstrong Sayi Bulma Programi ****\n");
	printf("=======================================\n\n");
	
	int number,temp,digit=0,remainder,result=0;
	int i;
	
	printf("Lutfen bir sayi giriniz: ");
	scanf("%d",&number);
	
	temp=number; // asil sayiyi kaybetmemek icin
	// sayinin basamak sayisini bulma
	while(temp!=0){
		temp=temp/10;
		digit++;
	}
	
	temp=number;
	while(temp!=0){
		remainder=temp%10;
		int sum=1;
		for(i=0;i<digit;i++){
			sum=sum*remainder;
		}
		result=result+sum;
		temp=temp/10;
	}
	
	if(result==number){
		printf("\n%d sayisi bir Armstrong sayidir.\n\n",number);
	}
	else{
		printf("\n%d sayisi bir Armstrong sayidir degildir.\n\n",number);
	}
	
}

void fibonacci_number(){
	printf("\n\n**** Fibonacci Dizisi ****\n");
	printf("=======================================\n\n");
	
	int choice;
	int number,i,f1=1,f2=1,f3=0;
	
	printf("Oncelikle yapmak istediginiz islemi seciniz...\n\n1-Girdigim siraya kadar Fibonacci dizisinin siralanmasi\n2-Girdigim siradaki Fibonacci sayisi nedir?\n\nSeciminiz: ");
	scanf("%d",&choice);
	
	if(choice==1){
		printf("\nLutfen bir sayi giriniz: ");
		scanf("%d",&number);
		
		printf("\n%d\t%d\t",f1,f2);
		for(i=0;i<number-2;i++){
			f3=f1+f2;
			printf("%d\t",f3);
			f1=f2;
			f2=f3;
		}
	}
	else if(choice==2){
		printf("\nLutfen bir sayi giriniz: ");
		scanf("%d",&number);
		
		for(i=0;i<number-2;i++){
			f3=f1+f2;
			f1=f2;
			f2=f3;
		}
		
		if(number==1 || number==2){
			f3=1;
		}
		
		printf("\n%d. siradaki Fibonacci sayisi: %d",number,f3);
	}
	else{
		printf("\nGecersiz sayi girisi yaptiniz!\n");
	}
	printf("\n");
}

void polindrome_number(){
	printf("\n\n**** Polindrom Sayi Bulma Programi ****\n");
	printf("=======================================\n\n");
	
	int number,reversedNumber=0,remainder,temp;
	
	printf("Lutfen bir sayi giriniz: ");
	scanf("%d",&number);
	
	temp=number;
	while(temp!=0){
		remainder=temp%10;
		reversedNumber=reversedNumber*10+remainder;
		temp=temp/10;
	}
	
	if(reversedNumber==number){
		printf("\n%d sayisi bir Polindrom sayidir.\n\n",number);
	}
	else{
		printf("\n%d sayisi bir Polindrom sayidir degildir.\n\n",number);
	}
}

void info(){
	printf("\n\n**** Bilgilendirme Metni ****\n");
	printf("=======================================\n\n");
	
	printf("1.Armstrong Sayi\n  n basamakli bir sayinin her bir basamaginin n'inci kuvvetlerinin toplaminin, sayinin kendisine esit oldugu sayidir.\n Ornek: 153 -> 1^3+5^3+3^3=153\n");
	printf("\n2.Fibonacci Dizisi\n  Her bir sayinin kendisinden once gelen iki sayinin toplamiyla elde edildigi bir sayi dizisidir.1 ve 1 ile baslayip    devam eder.\n");
	printf("\n3.Polindrom Sayi\n  Tersten okundugunda da ayni olan sayilardir.\n Ornek: 121 -> 121\n");
}
