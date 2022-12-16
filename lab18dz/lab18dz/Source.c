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
	printf("������� ������� ����������: ");
	scanf(" %s", a.surname);
	printf("\n������� ��� ����������: ");
	scanf(" %s", a.name);
	printf("\n������� �������� ����������: ");
	scanf(" %s", a.patronymic);
	printf("\n������� ��������� ����������: ");
	scanf(" %s", a.status);
	printf("\n������� �������� ����������: ");
	scanf("%d", &a.wages);
	printf("\n������� ���� �������� ����������: ");
	scanf("%d%d%d", &a.day, &a.month, &a.year);
	puts("");
	printf("������� ������� ����������: ");
	scanf(" %s", b.surname);
	printf("\n������� ��� ����������: ");
	scanf(" %s", b.name);
	printf("\n������� �������� ����������: ");
	scanf(" %s", b.patronymic);
	printf("\n������� ��������� ����������: ");
	scanf(" %s", b.status);
	printf("\n������� �������� ����������: ");
	scanf("%d", &b.wages);
	printf("\n������� ���� �������� ����������: ");
	scanf("%d%d%d", &b.day, &b.month, &b.year);
	puts("");
	printf("������� ������� ����������: ");
	scanf(" %s", c.surname);
	printf("\n������� ��� ����������: ");
	scanf(" %s", c.name);
	printf("\n������� �������� ����������: ");
	scanf(" %s", c.patronymic);
	printf("\n������� ��������� ����������: ");
	scanf(" %s", c.status);
	printf("\n������� �������� ����������: ");
	scanf("%d", &c.wages);
	printf("\n������� ���� �������� ����������: ");
	scanf("%d%d%d", &c.day, &c.month, &c.year);
	puts("");
	printf("������� ������� ����������: ");
	scanf(" %s", d.surname);
	printf("\n������� ��� ����������: ");
	scanf(" %s", d.name);
	printf("\n������� �������� ����������: ");
	scanf(" %s", d.patronymic);
	printf("\n������� ��������� ����������: ");
	scanf(" %s", d.status);
	printf("\n������� �������� ����������: ");
	scanf("%d", &d.wages);
	printf("\n������� ���� �������� ����������: ");
	scanf("%d%d%d", &d.day, &d.month, &d.year);
	puts("");
	printf("������� ������� ����������: ");
	scanf(" %s", e.surname);
	printf("\n������� ��� ����������: ");
	scanf(" %s", e.name);
	printf("\n������� �������� ����������: ");
	scanf(" %s", e.patronymic);
	printf("\n������� ��������� ����������: ");
	scanf(" %s", e.status);
	printf("\n������� �������� ����������: ");
	scanf("%d", &e.wages);
	printf("\n������� ���� �������� ����������: ");
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
	printf("\n ���������: %s %s %s %s ����������� �����: %d, ���� ��������: %d.%d.%d", x.surname, x.name, x.patronymic, x.status, x.wages, x.day, x.month, x.year);
}
void find(E x)
{
	if (x.month==5)
		printf("\n ���������: %s %s %s %s ����������� �����: %d, ���� ��������: %d.%d.%d", x.surname, x.name, x.patronymic, x.status, x.wages, x.day, x.month, x.year);
}
