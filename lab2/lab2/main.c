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

	printf("������� ������: ");
	scanf("%c", &chr);
	fflush(stdin);
	printf("�������� ������: %c, � ���� ����: %d\n\n", chr, chr);

	printf("������� ������: ");
	fgets(str, sizeof(str), stdin);
	printf("�������� ������: %s, ����� ������: %d\n\n", str, strlen(str)-1);

    printf("������� ������������� ����� �����: ");
	scanf("%d", &a);
	printf("������� ������������� ����� �����: ");
	scanf("%d", &b);
	printf("� ���������� ����: a = %+d, b = %+d\n", a, b);
	printf("� ����������������� ����: a = %#x, b = %#x\n", a, b);
	printf("����� � ����� ������� ���� �������� ������ : a = %-10d, b = %-20d\n", a, b);
	printf("����� � �������� ����������� ������� ����: a = %5d, b = %5d\n", a, b);
	printf("����� �� ��������� ����� ������:\t a = %d,\t b = %d\n\n", a, b);

	printf("������� ������������� ����� � ��������� ������: ");
	scanf("%lf", &c);
	printf("������� ������������� ����� � ��������� ������: ");
	scanf("%lf", &d);
	printf("� ���������� �����: a = %.5lf, b = %.5lf\n", c, d);
	printf("� ���������������� �����: a = %.5e, b = %.5e\n\n", c, d);

	printf("������� ����������� ����� �����: ");
	scanf("%u", &e);
	printf("� ���������� �����: %u\n", e);
	printf("� ������������ �����: %o\n", e);
	printf("� ����������������� �����: %x", e);




_getch();
return 0;
}


