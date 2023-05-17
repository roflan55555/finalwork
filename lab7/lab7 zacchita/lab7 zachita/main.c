
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char str1[255], str2[255];
	size_t schetchik = 0;

	printf("Введите строку S: ");
	gets(str1);

	printf("Введите строку S1: ");
	gets(str2);

	char *ptr = strstr(str1, str2);
	while(ptr != NULL) {
		schetchik++;
		ptr = strstr(ptr + 1, str2);
	}

	printf("Количество вхождений: %u", schetchik);
	getch();
	getch();
}
