#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <time.h>

typedef struct Node //тип данных €чейка односв€зного списка
{
    int speed;
    char name[50];
    struct Price {
        int old;
        int neww;
    } Price;
    int weight;
    struct Node* next;
} Knot; //Knot в переводе узел можно назвать Node так тоже можно

typedef struct list {//структура чтобы запомнить начало и конец списка
    Node* first;
    Node* last;
} List;
List* savve = (List*)malloc(sizeof(List));//выделение пам€ти под эту структуру

Knot* create(int speed, char name[50], int old, int neww, int weight)// функци€ создани€ 1-го элемента списка
{
    // ¬ыделение пам€ти под корень списка
    Knot* tmp = (Knot*)malloc(sizeof(Knot));
    // ѕрисваивание значений узлу
    tmp->speed = speed;
    strcpy(tmp->name, name);
    tmp->Price.old = old;
    tmp->Price.neww = neww;
    tmp->weight = weight;
    // ѕрисваивание указателю на следующий элемент значени€ NULL
    tmp->next = NULL;
    return(tmp);
}

Knot* pushStart(int speed, char name[50], int old, int neww, int weight, Knot* head)//создание любого следующего узла и присваивание ему головы списка
{
    Knot* tmp = create(speed, name, old, neww, weight);
    tmp->next = head;
    return(tmp);
}

Knot* input(int count) {
    int a, b, c, d;
    char f[50];
    char r;
    printf("¬ведите скорость машины:");
    scanf("%d", &a);
    while (fgetc(stdin) != '\n');
    printf("¬ведите название машины:");
    gets_s(f);
    printf("¬ведите старую цену машины:");
    scanf("%d", &b);
    printf("¬ведите новую цену машины:");
    scanf("%d", &c);
    printf("¬ведите вес машины:");
    scanf("%d", &d);//¬вод переменных с руки
    printf("¬вод 1 строки окончен\n");
    Knot* head = create(a, f, b, c, d);
    savve->last = head;
    for (int i = 0; i < count; i++) {
        printf("¬ведите скорость машины:");
        scanf("%d", &a);
        while (fgetc(stdin) != '\n');
        printf("¬ведите название машины:");
        gets_s(f);
        printf("¬ведите старую цену машины:");
        scanf("%d", &b);
        printf("¬ведите новую цену машины:");
        scanf("%d", &c);
        printf("¬ведите вес машины:");
        scanf("%d", &d);//и еще 2 раза ввод
        printf("¬вод строки %d окончен\n", (i + 2));
        while (fgetc(stdin) != '\n');
        printf("¬ведите * чтобы закончить ввод\n");
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

void swap(Knot* first, Knot* second) {//‘ункци€ чтоб помен€ть значени€ 2 ЋёЅџ’(главное имень на них указатели) узла
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
void out(Knot* cars) {//вывод данных
    while (cars != NULL) {//мотаем список пока не наткнемс€ на то что узел пуст
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
    printf("¬ведите кол-во машин:");
    scanf("%d", &count);
    Knot* bt = input(count - 1);

    if (deal == 1) {
        printf("¬ведите что нужно помен€ть:");
        scanf("%d", &n);
        printf("¬ведите с чем нужно помен€ть:");
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
    free(savve);//очищаем за собой пам€ть
    getchar();
    getchar();
    return 0;
}
