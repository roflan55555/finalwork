#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a,b,c,d,sum1,sum2,sum3,sum4,sum5,x,y,z;

    printf("������� �������� � = ");
    scanf("%d", &a);
    printf("������� �������� b = ");
    scanf("%d", &b);
    printf("������� �������� c = ");
    scanf("%d", &c);
    printf("������� �������� d = ");
    scanf("%d", &d);

    sum1 = (a+b+c);
    sum2 = (a+b+d);
    sum3 = (a+c+d);
    sum4 = (c+b+d);
    sum5 = (sum1<sum2 && sum1<sum3 && sum1<sum4) ? sum1:(sum2<sum1 && sum2<sum3 && sum2<sum4) ? sum2: (sum3<sum2 && sum3<sum1 && sum3<sum4)? sum3:sum4;

    x = (sum5 == sum1) ? a : (sum5 == sum2) ? a : (sum5 == sum3) ? a : c;
    y = (sum5 == sum1) ? b : (sum5 == sum2) ? b : (sum5 == sum3) ? c : b;
    z = (sum5 == sum1) ? c : (sum5 == sum2) ? d : (sum5 == sum3) ? d : d;
    printf("������ ����� � ����������� ������: %d, %d, %d", x, y, z);
    _getch();
    return 0;
}






