#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <windows.h>

typedef struct moto{
	char name[50];
	unsigned int year,razgon;
	struct price{
		unsigned int by, noviy;
	} price;
} moto;



int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int y;


	moto arr[5];

	printf("Введите значения через пробел:");
	for(size_t i = 0; i < 5; i++)
		scanf("%s %u %u %u %u", arr[i].name, &arr[i].year, &arr[i].price.by, &arr[i].price.noviy, &arr[i].razgon);

	printf("\n\n--------------------------------------------------------------------------------");
	printf("|                    |             |            Цена                |          |");
	printf("|      Название      | Год выпуска |--------------------------------|  0-100   |");
	printf("|                    |             |      б.у    |      новый       |          |");
	printf("--------------------------------------------------------------------------------");

	for(size_t i = 0; i < 5; i++)
		printf("| %-18s | %-11u | %-14u | %-13u | %-8u |", arr[i].name, arr[i].year, arr[i].price.by, arr[i].price.noviy, arr[i].razgon);

	printf("--------------------------------------------------------------------------------");

	moto temp = arr[4];
	arr[4] = arr[0];
	arr[0] = temp;

	printf("\n\n--------------------------------------------------------------------------------");
	printf("|                    |             |            Цена                |          |");
	printf("|      Название      | Год выпуска |--------------------------------|  0-100   |");
	printf("|                    |             |      б.у    |      новый       |          |");
	printf("--------------------------------------------------------------------------------");


	for(size_t i = 0; i < 5; i++)
		printf("| %-18s | %-11u | %-14u | %-13u | %-8u |", arr[i].name, arr[i].year, arr[i].price.by, arr[i].price.noviy, arr[i].razgon);

	printf("--------------------------------------------------------------------------------");
	for(size_t i = 0; i < 5; i++)
        y = sizeof(moto);
        printf("%d", y);

	_getch();
	_getch();
}
