#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a,b,c,d,sum1,sum2,sum3,sum4,x,y,z;

    printf("¬ведите значение а = ");
    scanf("%d", &a);
    printf("¬ведите значение b = ");
    scanf("%d", &b);
    printf("¬ведите значение c = ");
    scanf("%d", &c);
    printf("¬ведите значение d = ");
    scanf("%d", &d);

    sum1 = (a+b+c);
    sum2 = (a+b+d);
    sum3 = (a+c+d);
    sum4 = (c+b+d);

    if (sum1<sum2 && sum1<sum3 && sum1<sum4) {x=a; y=b; z=c;}
    if (sum2<sum1 && sum2<sum3 && sum2<sum4) {x=a; y=b; z=d;}
    if (sum3<sum2 && sum3<sum1 && sum3<sum4) {x=a; y=c; z=d;}
    if (sum4<sum2 && sum4<sum3 && sum4<sum1) {x=c; y=b; z=d;}

    printf("“ройка чисел с минимальной суммой: %d, %d, %d", x, y, z);
    _getch();
    return 0;
}






