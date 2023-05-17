#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <stdio.h>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	double y1, x, y2, tmp;

	printf("¬ведите значение y1 = ");
	scanf_s("%lf", &y1);
	printf("¬ведите x = ");
	scanf_s("%lf", &x);
    do{
        y2 = 0.5*(y1 + x/y1 - 1) ;
        tmp = y1;
        y1 = y2;
}while ((fabs(pow(y2, 2) - pow(y1,2))) >= 2.7182818284);

printf("y = %lf", y2);
_getch();
}
