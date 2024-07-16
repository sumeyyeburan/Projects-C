#include <stdio.h>
#include <math.h>

void add(double x, double y) {
	printf("\n%.2lf + %.2lf = %.2lf\n\n", x, y, x + y);
}

void sub(double x, double y) {
	printf("\n%.2lf - %.2lf = %.2lf\n\n", x, y, x - y);
}

void mult(double x, double y) {
	printf("\n%.2lf * %.2lf = %.2lf\n\n", x, y, x * y);
}

void div(double x, double y) {
	if (y == 0)
		printf("\nGecersiz islem, sifira bolunemez hatasi!\n\n");
	else
		printf("\n%.2lf / %.2lf = %.2lf\n\n", x, y, x / y);
}

void power(double x, double y) {
	printf("\n%.2lf ^ %.2lf = %.2lf\n\n", x, y, pow(x, y));
}

void mod(double x, double y) {
	if (y == 0)
		printf("\nGecersiz islem, sifira bolunemez hatasi!\n\n");
	else {
		double result = fmod(x, y);
		printf("\n%.2lf %% %.2lf = %.2lf\n\n", x, y, result);
	}
}

int main(void) {
	int choice;
	double num1, num2;

	printf("\n****** HESAPLAMAYA HAZIRIM ! *******\n");
	printf("\n\n\n");
	printf("Oncelikle yapmak istediginiz islemi seciniz...\n");
	while (1) {  //sonsuz d?ng?

		printf("\n1. Toplama\n");
		printf("2. Cikarma\n");
		printf("3. Carpma\n");
		printf("4. Bolme\n");
		printf("5. Us Alma\n");
		printf("6. Mod Alma\n");
		printf("7. Cikis\n");
		printf("\nSeciminiz: ");
		scanf("%d", &choice);

		if (choice == 7) {
			printf("\n\n****** HESAP MAKINESI SONLANDI ! ******\n\n");
			break;
		}
		if (choice < 1 || choice>7) {
			printf("\n\nGecersiz secim, tekrar deneyiniz!\n");
			continue;
		}

		printf("\nIslemini yapmak istediginiz sayilari giriniz...\n");
		printf("Sayi-1: ");
		scanf("%lf", &num1);
		printf("Sayi-2: ");
		scanf("%lf", &num2);

		switch (choice) {
		case 1:
			add(num1, num2);
			break;
		case 2:
			sub(num1, num2);
			break;
		case 3:
			mult(num1, num2);
			break;
		case 4:
			div(num1, num2);
			break;
		case 5:
			power(num1, num2);
			break;
		case 6:
			mod(num1, num2);
			break;
		}
	}
	return 0;
}
