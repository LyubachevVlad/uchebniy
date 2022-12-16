#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

struct employee
{
	char surname[20];
	char name[20];
	char patronymic[20];
	char status[20];
	int wages;
	int day;
	int month;
	int year;
};
typedef struct employee E;
void data(E x);
void find(E x);
void main()
{
	setlocale(LC_ALL, "RUS");
	E a, b, c, d, e;
	printf("¬ведите фамилию сотрудника: ");
	scanf(" %s", a.surname);
	printf("\n¬ведите им€ сотрудника: ");
	scanf(" %s", a.name);
	printf("\n¬ведите отчество сотрудника: ");
	scanf(" %s", a.patronymic);
	printf("\n¬ведите должность сотрудника: ");
	scanf(" %s", a.status);
	printf("\n¬ведите зарплату сотрудника: ");
	scanf("%d", &a.wages);
	printf("\n¬ведите день рождени€ сотрудника: ");
	scanf("%d%d%d", &a.day, &a.month, &a.year);
	puts("");
	printf("¬ведите фамилию сотрудника: ");
	scanf(" %s", b.surname);
	printf("\n¬ведите им€ сотрудника: ");
	scanf(" %s", b.name);
	printf("\n¬ведите отчество сотрудника: ");
	scanf(" %s", b.patronymic);
	printf("\n¬ведите должность сотрудника: ");
	scanf(" %s", b.status);
	printf("\n¬ведите зарплату сотрудника: ");
	scanf("%d", &b.wages);
	printf("\n¬ведите день рождени€ сотрудника: ");
	scanf("%d%d%d", &b.day, &b.month, &b.year);
	puts("");
	printf("¬ведите фамилию сотрудника: ");
	scanf(" %s", c.surname);
	printf("\n¬ведите им€ сотрудника: ");
	scanf(" %s", c.name);
	printf("\n¬ведите отчество сотрудника: ");
	scanf(" %s", c.patronymic);
	printf("\n¬ведите должность сотрудника: ");
	scanf(" %s", c.status);
	printf("\n¬ведите зарплату сотрудника: ");
	scanf("%d", &c.wages);
	printf("\n¬ведите день рождени€ сотрудника: ");
	scanf("%d%d%d", &c.day, &c.month, &c.year);
	puts("");
	printf("¬ведите фамилию сотрудника: ");
	scanf(" %s", d.surname);
	printf("\n¬ведите им€ сотрудника: ");
	scanf(" %s", d.name);
	printf("\n¬ведите отчество сотрудника: ");
	scanf(" %s", d.patronymic);
	printf("\n¬ведите должность сотрудника: ");
	scanf(" %s", d.status);
	printf("\n¬ведите зарплату сотрудника: ");
	scanf("%d", &d.wages);
	printf("\n¬ведите день рождени€ сотрудника: ");
	scanf("%d%d%d", &d.day, &d.month, &d.year);
	puts("");
	printf("¬ведите фамилию сотрудника: ");
	scanf(" %s", e.surname);
	printf("\n¬ведите им€ сотрудника: ");
	scanf(" %s", e.name);
	printf("\n¬ведите отчество сотрудника: ");
	scanf(" %s", e.patronymic);
	printf("\n¬ведите должность сотрудника: ");
	scanf(" %s", e.status);
	printf("\n¬ведите зарплату сотрудника: ");
	scanf("%d", &e.wages);
	printf("\n¬ведите день рождени€ сотрудника: ");
	scanf("%d%d%d", &e.day, &e.month, &e.year);
	data(a);
	data(b);
	data(c);
	data(d);
	data(e);
	puts("");
	find(a);
	find(b);
	find(c);
	find(d);
	find(e);
}
void data(E x)
{
	printf("\n —отрудник: %s %s %s %s заработнра€ плата: %d, дата рождени€: %d.%d.%d", x.surname, x.name, x.patronymic, x.status, x.wages, x.day, x.month, x.year);
}
void find(E x)
{
	if (x.month==5)
		printf("\n —отрудник: %s %s %s %s заработнра€ плата: %d, дата рождени€: %d.%d.%d", x.surname, x.name, x.patronymic, x.status, x.wages, x.day, x.month, x.year);
}
