#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int options;

void gameInfo();
void startGame();

int main(){

    // Rastgele sayý üreticisini zaman ile baþlat
    srand(time(NULL));

    printf("\n**** SAYI TAHMINI OYUNUNA HOS GELDINIZ ! ****\n\n\n");
    printf("Oyun hakkinda bilgi almak icin 1'e\nOyuna baslamak icin 2'ye \ntiklayiniz: ");
    scanf("%d", &options);

    switch (options) {
        case 1:
            gameInfo();
            break;
        case 2:
            startGame();
            break;
        default:
            printf("Gecersiz secim. Programdan cikiliyor.\n");
            break;
    }

    return 0;
}

void gameInfo() {
    printf("\n----------------------------------------------------------\n");
    printf("\nOyunumuz bir sayi tahmini oyunudur.\nRandom bir sekilde sayi belirlenir ve siz o sayiyi tahmin etmeye calisirsiniz.\n");
    printf("Deneme hakkiniz 5'tur.\nSayilar 0 ve 100 arasinda belirlenir.\nSayi hakkinda size ipuclarý da verilecektir.\nIyi eglenceler dilerim :)");
    printf("\n\nOyuna baslamak istiyorsaniz 2'ye, istemiyorsaniz 0'a \ntiklayiniz: ");
    scanf("%d", &options);

    if (options != 2) {
        printf("\n---- Oyundan cikis yapiliyor... ----\n\n");
        exit(0); // Programý sonlandýr
    } else {
        startGame();
    }
}

void startGame() {
    int guess_number, random_number;
    int RIGHT = 5;

    random_number = rand() % 101;

    printf("\n----------------------------------------------------------\n");
    printf("\n~~~~ Oyun Basliyor... ~~~~\n\n");

    do {
        printf("\nTahmininizi giriniz: ");
        scanf("%d", &guess_number);

        // Doðru tahmin
        if (guess_number == random_number) {
            printf("\nOyunu kazandiniz, TEBRIKLER!!\n");
            printf("\n---- Oyundan cikis yapiliyor... ----\n\n");
            return;
        }
        // Tahmin büyükse
        else if (guess_number > random_number) {
            printf("\nTahmininiz random sayidan buyuktur. Daha kucuk bir sayi giriniz.");
        }
        // Tahmin küçükse
        else {
            printf("\nTahmininiz random sayidan kucuktur. Daha buyuk bir sayi giriniz.");
        }

        RIGHT--;
        printf("\nKalan deneme hakkiniz: %d\n", RIGHT);

    } while (RIGHT > 0);

    printf("\n\nDeneme hakkiniz bitmistir.\n\nRandom sayi: %d\nOyunu kaybettiniz :(\n", random_number);
    printf("\n---- Oyundan cikis yapiliyor... ----\n\n");
}

