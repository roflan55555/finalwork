#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

int main() {
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	char chr;
	char str[50];
	int a, b;
	double c, d;
	unsigned int e;

	printf("Введите символ: ");
	scanf("%c", &chr);
	fflush(stdin);
	printf("Введённый символ: %c, В виде кода: %d\n\n", chr, chr);

	printf("Введите строку: ");
	fgets(str, sizeof(str), stdin);
	printf("Введённая строка: %s, длина строки: %d\n\n", str, strlen(str)-1);

    printf("Введите положительное целое число: ");
	scanf("%d", &a);
	printf("Введите отрицательное целое число: ");
	scanf("%d", &b);
	printf("В десятичном виде: a = %+d, b = %+d\n", a, b);
	printf("В шестнадцатеричном виде: a = %#x, b = %#x\n", a, b);
	printf("Вывод с левой позиции поля заданной ширины : a = %-10d, b = %-20d\n", a, b);
	printf("Вывод с заданной минимальной шириной поля: a = %5d, b = %5d\n", a, b);
	printf("Вывод со смещением числа вправо:\t a = %d,\t b = %d\n\n", a, b);

	printf("Введите положительное число с плавающей точкой: ");
	scanf("%lf", &c);
	printf("Введите отрицательное число с плавающей точкой: ");
	scanf("%lf", &d);
	printf("В десятичной форме: a = %.5lf, b = %.5lf\n", c, d);
	printf("В экспоненциальной форме: a = %.5e, b = %.5e\n\n", c, d);

	printf("Введите беззнаковое целое число: ");
	scanf("%u", &e);
	printf("В десятичной форме: %u\n", e);
	printf("В восьмеричной форме: %o\n", e);
	printf("В шестнадцатеричной форме: %x", e);




_getch();
return 0;
}


