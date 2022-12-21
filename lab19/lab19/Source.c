#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<io.h>
#include<math.h>
typedef struct 
{
	char surname[20];
	char name[20];
	char patronymic[20];
	char status[20];
	int wages;
	int day;
	int month;
	int year;
}E;
float F(float x)
{
	float k = pow(x, 3) - 4 * pow(x, 2) + 2;
	return k;
}
int writefile(int size)
{
	E a;
	FILE* empl;
	char name[20] = "employee.txt";
	empl = fopen(name, "w");
	if ((empl = fopen(name, "wt")) == NULL)
	{
		printf("Ошибка открытия файла для записи");
		return 0;
	}
	for (int i = 0; i < size; i++)
	{
	printf("Введите фамилию сотрудника: ");
	scanf(" %s", a.surname);
	fprintf(empl, "%s\t", a.surname);
	printf("\nВведите имя сотрудника: ");
	scanf(" %s", a.name);
	fprintf(empl, "%s\t", a.name);
	printf("\nВведите отчество сотрудника: ");
	scanf(" %s", a.patronymic);
	fprintf(empl, "%s\t", a.patronymic);
	printf("\nВведите должность сотрудника: ");
	scanf(" %s", a.status);
	fprintf(empl, "%s\t", a.status);
	printf("\nВведите зарплату сотрудника: ");
	scanf("%d", &a.wages);
	fprintf(empl, "%d\t", a.wages);
	printf("\nВведите день рождения сотрудника: ");
	scanf("%d%d%d", &a.day, &a.month, &a.year);
	fprintf(empl, "%d%d%d\t", a.day, a.month, a.year);
	if ((empl = fopen(name, "wt")) == NULL)
	{
		printf("Ошибка отрытия файла для записи");
		return 0;
	}
	fprintf(empl, "Сотрудник: %s %s %s %s заработнрая плата : %d, дата рождения : %d.%d.%d\n", a.surname, a.name, a.patronymic, a.status, a.wages, a.day, a.month, a.year);
	fclose(empl);
	}
}
typedef struct employee Employee;
void main()
{
	setlocale(LC_ALL, "RUS");
	int c=0;
	char fname[20] = "number.txt";
	FILE* out;
	out = fopen("numder.txt", "wt");
	puts("Создание файла");
	if ((out = fopen(fname, "wt")) == NULL)
	{
		printf("Ошибка отрытия файла для записи");
		return 0;
	}
	fprintf(out, "%f\n", 123.123123123);
	fprintf(out, "%f\n",12.56);
	fclose(out);
	char fn[20] = "temp.txt";
	char fnam[25] = "empolyee.txt";
	FILE* tab; 
	FILE* emp;
	emp = fopen("employee.txt", "w");
	float y, x, l=1;
	printf("Вывод результатов в number - 1\n");
	printf("Вывод результатов в temp - 2\n");
	scanf("%d", &c);
	switch(c)
	{ 
	case 1:
		out = fopen("numder.txt", "a");
		if ((out = fopen(fname, "a")) == NULL)
		{
			printf("Ошибка отрытия файла для записи");
			return 0;
		}
		fprintf(out, "%s\n", "y=x^3-4*x^2+2");
		for (float x = 1; x <= 3; x += l)
		{
			y = F(x);
			fprintf(out, "%s\n", "-------------");
			fprintf(out, "|%.3f|%.3f|\n", x, y);
			fprintf(out, "%s\n", "-------------");
		}
		fclose(out);
		break;
	case 2:
		tab = fopen("temp.txt", "w");
		if ((tab = fopen(fn, "wt")) == NULL)
		{
			printf("Ошибка отрытия файла для записи");
			return 0;
		}
		fprintf(tab, "%s\n", "y=x^3-4*x^2+2");
		for (float x = 1; x <= 3; x += l)
		{
			y = F(x);
			fprintf(tab, "%s\n", "-------------");
			fprintf(tab, "|%.3f|%.3f|\n", x, y);
			fprintf(tab, "%s\n", "-------------");
		}
		fclose(tab);
		break;
	}
	writefile(1);
}