#include <stdio.h>
#include <string.h>

#define USERNAME "student"
#define PASSWORD "1234"
#define MAX_TRIES 5

int main(void){
	char username[30],password[15];
	int again,lesson[10],lesson_number;
	int tries=MAX_TRIES;
	double result,notes[10];
	int i;
	
	while(tries>0){
	
		printf("Kullanici adinizi giriniz:");
		scanf("%29s",username);
		printf("Sifrenizi giriniz:");
		scanf("%14s",password);
	
		if(strcmp(username,USERNAME)==0 && strcmp(password,PASSWORD)==0){
			printf("\nGiris basarili. Hos geldiniz, %s\n",username);
			
			cont:
			printf("\n\nKac ders hesabi yapacaksiniz?: ");
			scanf("%d",&lesson_number);
			
			if(lesson_number<=0 || lesson_number>10){
				printf("\nGecerli bir sayi giriniz (0<x<=10) :");
				goto cont;
			}
			printf("\n");
			for(i=0;i<lesson_number;i++){
				printf("Dersin IDsini giriniz: ");
				scanf("%d",&lesson[i]);
			}
			printf("\n------------------------------------\n");
			for(i=0;i<lesson_number;i++){
				if(i%2==0){
					printf("lesson[%d]: %d\t",i,lesson[i]);
				}
				else{
					printf("lesson[%d]: %d\n",i,lesson[i]);
				}
			}
			
			printf("\n\nYukarida listelenmis index numalarina gore derslerin notlarini giriniz...\n\n");
			
			for(i=0;i<lesson_number;i++){
				printf("notes[%d]: ",i);
				scanf("%lf",&notes[i]);
				
				result=result+notes[i];
			}
			
			result=result/lesson_number;
			
			printf("\nOrtalamaniz: %.2lf\n",result);
			
			
			printf("\n\nOrtalama hesabi yapildi.Programdan cikis yapiliyor!\n\n");
			
			break;
		}
		
		else{
			printf("\nKullanici adi veya sifreniz yanlis,tekrar denemek istiyorsaniz 1'e basiniz.\n");
			scanf("%d",&again);
		
			if(again==1){
				tries--;
				printf("\nKalan hakkiniz: %d\n\n\n",tries);
			}
			else{
				printf("\nGiris denemesi iptal edildi...\n");
				break;
			}
		}
	}
	
	if (tries == 0) {
        printf("\nGiris hakkiniz tükendi. Programdan cikiliyor.\n");
    }
    
    return 0;
}

