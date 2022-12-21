#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>
typedef double (*Tfun)(double);
struct bil
{
	double x;
	double x1;
	double x2;
	double tab;
	Tfun f;
};
typedef struct bil Bil;
double Y(double x)
{
	double y;
	y = exp(x) + 5 + cos(0.001 * x);
	return y;
}
double V(double x)
{
	double f,v;
	if (x >= 1)
	{
		f = x + x;
	}
	if (x<1)
	{
		f = pow(x, 3) + 0.2;
	}
	v = 2 * pow(cos(pow(x, 2)), 3) + pow(sin(pow(x, 3)), 2) - 0.08 * f;
	return v;
}
double Y(double);
double V(double);
void i(Tfun f, double xn, double xk, double h)
{
	char u = ' ';
	printf("\n|%2cx%3c|%4cF(x)%5c|",u,u,u,u);
	for (double x = xn; x <= xk; x += h)
	{
		printf("\n|%6.2lf|%13.6lf|", x, f(x));
	}
}
void file(Tfun f, double xn, double xk, double h)
{
	FILE* tabl;
	char name[20] = "tabl.txt";
	if ((tabl=fopen(name,"wt"))==NULL)
	{
		printf("Ошибка открытия файла");
		return 0;
	}
	char u = " ";
	fprintf(tabl, "\n |%3cx%4c|%4cF(x)%7c|", u, u, u, u);
	for (double x = xn; x <= xk; x += h)
	{
		fprintf(tabl,"\n | %6.2lf | %13.6lf |", x, f(x));
	}
	fclose(tabl);
}
void plot(double x0, double x1, Tfun f)
{
	int SCREENW = 40, SCREENH = 40;
	char screen[40][40];
	double x, y[40];
	double ymin = 0, ymax = 0;
	double hx, hy;
	int i, j;
	int xz, yz;
	hx = (x1 - x0) / (SCREENW - 1);
	for (i = 0, x = x0; i < SCREENW; ++i, x += hx)
	{
		y[i] = f(x); 
		if (y[i] < ymin) ymin = y[i];
		if (y[i] > ymax) ymax = y[i];
	}
	hy = (ymax - ymin) / (SCREENH - 1);
	yz = (int)floor(ymax / hy + 0.5);
	xz = (int)floor((0. - x0) / hx + 0.5);
	for (j = 0; j < SCREENH; ++j)
		for (i = 0; i < SCREENW; ++i)
		{
			if (j == yz && i == xz) screen[i][j] = '+';
			else if (j == yz) screen[i][j] = '-';
			else if (i == xz) screen[i][j] = '|';
			else screen[i][j] = ' ';
		}
	for (i = 0; i < SCREENW; ++i)
	{
		j = (int)floor((ymax - y[i]) / hy + 0.5);
		screen[i][j] = '*';
	}
	for (j = 0; j < SCREENH; ++j)
	{
		for (i = 0; i < SCREENW; ++i)  putchar(screen[i][j]);
		putchar('\n');
	}
}
void shiftr(int arr[50][50], int s, int shift)
{
	for (int i = 0; i < s; i++)
	{
		int t0 = arr[i][0], t1 = 0;
		for (int j = 0, k = 0; k < s; k++)
		{
			t1 = arr[i][(j + shift) % s];
			arr[i][(j + shift) % s] = t0;
			j = (j + shift) % s;
			t0 = t1;
		}
	}
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}
}
void shiftd(int arr[50][50], int s, int shift)
{
	for (int j = 0; j < s; j++)
	{
		int t0 = arr[0][j], t1 = 0;
		for (int i = 0, k = 0; k < s; k++)
		{
			t1 = arr[(i + shift) % s][(j) % s];
			arr[(i + shift) % s][j] = t0;
			i = (i + shift) % s;
			t0 = t1;
		}
	}
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}
}
void main()
{
	setlocale(LC_ALL, "RUS");
	Bil lib = { 5,-1,1,1,Y };
	char sk1, sk2,f;
	int c=0, marker = 0, marker2 = 0;
	while (c != 6)
	{
		puts("");
		puts("\nКакое действие:\n 1.Найти значение функции Y(x)\n 2.Найти значение функции F(x)\n 3.Вычислить значения функции Y(x) на заданном интервале, полуинтервале или отрезке\n 4.Вычислить значения функции V(x) на заданном интервале полуинтервале или отрезке\n 5.Построить график, выбранной функции Y(x) и F(x)\n 6.Завершение работы ");
		scanf("%d", &c);
		switch (c)
		{
		case 1:
			puts("\nВведите переменную x:");
			scanf("%lf", &lib.x);
			printf("\n%lf", lib.f(lib.x));
			break;
		case 2:
			puts("\nВведите переменную x:");
			scanf("%lf", &lib.x);
			lib.f = V;
			printf("%lf\n", lib.f(lib.x));
			break;
		case 3:
			printf("Выводить значения в консоль-1,выводить значения в файл-2\n");
			scanf("%d", &marker);
			switch (marker)
			{
			case 1:
				puts("\nВведите интервал:");
				scanf(" %c%lf%lf%c", &sk1, &lib.x1, &lib.x2, &sk2);
				puts("\nВведите шаг табуляции:");
				scanf(" %lf", &lib.tab);
				if (sk1 == '(') lib.x1 += lib.tab;
				if (sk2 == ')') lib.x2 -= lib.tab;
				i(lib.f, lib.x1, lib.x2, lib.tab);
				break;
			case 2:
				puts("\nВведите интервал:");
				scanf(" %c%lf%lf%c", &sk1, &lib.x1, &lib.x2, &sk2);
				puts("\nВведите шаг табуляции:");
				scanf(" %lf", &lib.tab);
				if (sk1 == '(') lib.x1 += lib.tab;
				if (sk2 == ')') lib.x2 -= lib.tab;
				file(lib.f, lib.x1, lib.x2, lib.tab);
				break;
			}
			break;
		case 4:
			printf("Выводить значения в консоль-1,выводить значения в файл-2\n");
			scanf("%d", &marker2);
			switch (marker2)
			{
			case 1:
				puts("\nВведите интервал:");
				scanf(" %c%lf%lf%c", &sk1, &lib.x1, &lib.x2, &sk2);
				puts("\nВведите шаг табуляции:");
				scanf(" %lf", &lib.tab);
				if (sk1 == '(') lib.x1 += lib.tab;
				if (sk2 == ')') lib.x2 -= lib.tab;
				i(lib.f, lib.x1, lib.x2, lib.tab);
				break;
			case 2:
				puts("\nВведите интервал:");
				scanf(" %c%lf%lf%c", &sk1, &lib.x1, &lib.x2, &sk2);
				puts("\nВведите шаг табуляции:");
				scanf(" %lf", &lib.tab);
				if (sk1 == '(') lib.x1 += lib.tab;
				if (sk2 == ')') lib.x2 -= lib.tab;
				file(lib.f, lib.x1, lib.x2, lib.tab);
				break;
			}
			break;
		case 5:
			puts("\nВведите интервал:");
			scanf(" %c%lf%lf%c", &sk1, &lib.x1, &lib.x2, &sk2);
			puts("\nВведите шаг табуляции:");
			scanf(" %lf", &lib.tab);
			puts("Какую функцию нарисовать?");
			scanf(" %c", &f);
			if (f=='y') plot(lib.x1, lib.x2, lib.f);
			if (f=='v') plot(lib.x1, lib.x2, lib.f);
			break;
		default:
			puts("Завершение");
			break;
		}
	}
	puts("");
	int arr[50][50],s;
	int flag=0,shift;
	srand(time(NULL));
	printf("Введите размерность:");
	scanf("%d", &s);
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			arr[i][j] = -11 + 1. * (11 - (-11)) * rand() / RAND_MAX;
			printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}
	puts("");
	while (flag != 3)
	{
		printf("\nКакой сдвиг хотите получить?\n");
		printf("1-в право,2-вниз,3-завершение\n");
		scanf("%d", &flag);
		switch (flag)
		{
		case 1:
			printf("Введите желаемый сдвиг\n");
			scanf("%3d", &shift);
			shiftr(arr, s, shift);
			break;
		case 2:
			printf("Введите желаемый сдвиг\n");
			scanf("%3d", &shift);
			shiftd(arr, s, shift);
			break;
		default:
			puts("Завершение");
			break;
		}
	}
}