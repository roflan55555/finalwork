#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <time.h>

typedef struct Node //��� ������ ������ ������������ ������
{
    int speed;
    char name[50];
    struct Price {
        int old;
        int neww;
    } Price;
    int weight;
    struct Node* next;
} Knot; //Knot � �������� ���� ����� ������� Node ��� ���� �����

typedef struct list {//��������� ����� ��������� ������ � ����� ������
    Node* first;
    Node* last;
} List;
List* savve = (List*)malloc(sizeof(List));//��������� ������ ��� ��� ���������

Knot* create(int speed, char name[50], int old, int neww, int weight)// ������� �������� 1-�� �������� ������
{
    // ��������� ������ ��� ������ ������
    Knot* tmp = (Knot*)malloc(sizeof(Knot));
    // ������������ �������� ����
    tmp->speed = speed;
    strcpy(tmp->name, name);
    tmp->Price.old = old;
    tmp->Price.neww = neww;
    tmp->weight = weight;
    // ������������ ��������� �� ��������� ������� �������� NULL
    tmp->next = NULL;
    return(tmp);
}

Knot* pushStart(int speed, char name[50], int old, int neww, int weight, Knot* head)//�������� ������ ���������� ���� � ������������ ��� ������ ������
{
    Knot* tmp = create(speed, name, old, neww, weight);
    tmp->next = head;
    return(tmp);
}

Knot* input(int count) {
    int a, b, c, d;
    char f[50];
    char r;
    printf("������� �������� ������:");
    scanf("%d", &a);
    while (fgetc(stdin) != '\n');
    printf("������� �������� ������:");
    gets_s(f);
    printf("������� ������ ���� ������:");
    scanf("%d", &b);
    printf("������� ����� ���� ������:");
    scanf("%d", &c);
    printf("������� ��� ������:");
    scanf("%d", &d);//���� ���������� � ����
    printf("���� 1 ������ �������\n");
    Knot* head = create(a, f, b, c, d);
    savve->last = head;
    for (int i = 0; i < count; i++) {
        printf("������� �������� ������:");
        scanf("%d", &a);
        while (fgetc(stdin) != '\n');
        printf("������� �������� ������:");
        gets_s(f);
        printf("������� ������ ���� ������:");
        scanf("%d", &b);
        printf("������� ����� ���� ������:");
        scanf("%d", &c);
        printf("������� ��� ������:");
        scanf("%d", &d);//� ��� 2 ���� ����
        printf("���� ������ %d �������\n", (i + 2));
        while (fgetc(stdin) != '\n');
        printf("������� * ����� ��������� ����\n");
        r = getchar();
        const char* g = "*";

        head = pushStart(a, f, b, c, d, head);
        savve->first = head;
        if (r == *g) {
            return(savve->first);
        }
    }

    return(savve->first);
}

void swap(Knot* first, Knot* second) {//������� ���� �������� �������� 2 �����(������� ����� �� ��� ���������) ����
    Knot* temp = (Knot*)malloc(sizeof(Knot));
    temp->speed = first->speed;
    strcpy(temp->name, first->name);
    temp->Price.old = first->Price.old;
    temp->Price.neww = first->Price.neww;
    temp->weight = first->weight;

    first->speed = second->speed;
    strcpy(first->name, second->name);
    first->Price.old = second->Price.old;
    first->Price.neww = second->Price.neww;
    first->weight = second->weight;

    second->speed = temp->speed;
    strcpy(second->name, temp->name);
    second->Price.old = temp->Price.old;
    second->Price.neww = temp->Price.neww;
    second->weight = temp->weight;
    free(temp);
}
void out(Knot* cars) {//����� ������
    while (cars != NULL) {//������ ������ ���� �� ��������� �� �� ��� ���� ����
        printf("%-17s%-16d%-16d%-24d%d\n", cars->name, cars->speed, cars->Price.old, cars->Price.neww, cars->weight);
        cars = cars->next;
    }
}
int main() {

    /*struct car cars[] = {
        250, "bmw m5", {157519, 215553}, 3000,
        260, "audi a8", {182391, 132648}, 2500,
        172, "lada granta", {14044, 2818}, 2000
    };*/
    int deal = 0;
    int count;
    int n, m;
    setlocale(LC_ALL, "Russian");
    scanf("%d", &deal);
    printf("������� ���-�� �����:");
    scanf("%d", &count);
    Knot* bt = input(count - 1);

    if (deal == 1) {
        printf("������� ��� ����� ��������:");
        scanf("%d", &n);
        printf("������� � ��� ����� ��������:");
        scanf("%d", &m);
        Knot* fkhead1 = bt;
        Knot* fkhead2 = bt;
        for (int i = 1; i < n; i++) {
            fkhead1 = fkhead1->next;
        }
        for (int i = 1; i < m; i++) {
            fkhead2 = fkhead2->next;
        }
        swap(fkhead1, fkhead2);
    }
    printf("Name\t\t Speed\t\t\t Price\t\t\t\t Weight\n\n\t\t\t\t old\t\t new\t\n");
    out(bt);
    /*for (int i = 0; i < 3; i++) {
        printf(
            "%-17s%-16d%-16d%-24d%d\n",
            cars[i].name, cars[i].speed, cars[i].Price.old, cars[i].Price.neww, cars[i].weight);
    }*/
    free(savve);//������� �� ����� ������
    getchar();
    getchar();
    return 0;
}
