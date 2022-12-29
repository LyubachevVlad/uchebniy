#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>
#include <malloc.h>
#define PI 3.14159265358979323846
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
double Y(double x);
double V(double x);
void i(Tfun f, double xn, double xk, double h);
void file(Tfun f, double xn, double xk, double h);
void plot(double x0, double x1, Tfun f);
int* shiftr(int** arr, int s, int shift);
int* shiftd(int** arr, int s, int shift);
void main()
{
	setlocale(LC_ALL, "RUS");
	Bil lib = { 5,-1,1,1,Y };
	char sk1, sk2, f;
	int c = 0, marker = 0, marker2 = 0,c1 = 0,c2 = 0,c3 = 0;
	while (c != 3)
	{
		puts("");
		printf("          |----------------Меню----------------|\n");
		printf("          |       С чем желаете работать?      |\n");
		printf("          |             1.Функции              |\n");
		printf("	  |         2.Двумерный массив         |\n");
		printf("          |             3.Завершить            |\n");
		printf("          |------------------------------------|\n");
		scanf("%d", &c);
		switch (c)
		{
		case 1:
			printf("          |--------------------Меню функций-------------------|\n");
			printf("          |            1.Вычислить значение функции           |\n");
			printf("	  |     2.Вычислить значение функции на интервале     |\n");
			printf("          |---------------------------------------------------|\n");
			scanf("%d", &c1);
			switch (c1)
			{
			case 1:
				puts("          |         Введите переменную x:       |");
				scanf("%lf", &lib.x);
				printf("          |--------Выберете функцию которую хотите посчитать-------|\n");
				printf("          |       1.Функция Y(x)=e^x+5+cos(0,001x)                 |\n");
				printf("          |       2.Функция V(x)=2cos^3(x^2)+sin^2(x^3)-0,08f(x)   |\n");
				printf("          |--------------------------------------------------------|\n");
				scanf("%d", &c2);
				switch (c2)
				{
				case 1:
					printf("\n%lf", lib.f(lib.x));
					break;
				case 2:
					lib.f = V;
					printf("%lf\n", lib.f(lib.x));
					break;
				}
				break;
			case 2:
				printf("          |------------------------------------|\n");
				printf("          |        !!!Пример: [-36 0)!!!       |\n");
				printf("          |------------------------------------|\n");
				puts("\nВведите интервал:");
				scanf(" %c%lf%lf%c", &sk1, &lib.x1, &lib.x2, &sk2);
				puts("\nВведите шаг табуляции:");
				scanf(" %lf", &lib.tab);
				printf("          |----------Таблицы и графики---------|\n");
				printf("          |      1.Вывести таблицу значений    |\n");
				printf("          |      2.Построить график функции    |\n");
				printf("          |------------------------------------|\n");
				scanf("%d", &c3);
				switch (c3)
				{
				case 1:
					printf("          |----------Консоль или файл----------|\n");
					printf("          |    1.Выводить значения в консоль   |\n");
					printf("          |     2.Выводить значения в файл     |\n");
					printf("          |------------------------------------|\n");
					scanf("%d", &marker2);
					printf("          |-------------------------Функция-------------------------|\n");
					printf("          |              Какую функцию протабулировать?             |\n");
					printf("          |             1.Функция Y(x)=e^x+5+cos(0,001x)            |\n");
					printf("          |       2.Функция V(x)=2cos^3(x^2)+sin^2(x^3)-0,08f(x)    |\n");
					printf("          |---------------------------------------------------------|\n");
					scanf("%d", &marker);
					switch (marker)
					{
					case 1:
						switch (marker2)
						{
						case 1:
							if (sk1 == '(') lib.x1 += lib.tab;
							if (sk2 == ')') lib.x2 -= lib.tab;
							i(lib.f, lib.x1, lib.x2, lib.tab);
							break;
						case 2:
							if (sk1 == '(') lib.x1 += lib.tab;
							if (sk2 == ')') lib.x2 -= lib.tab;
							file(lib.f, lib.x1, lib.x2, lib.tab);
							break;
						}
						break;
					case 2:
						switch (marker2)
						{
						case 1:
							if (sk1 == '(') lib.x1 += lib.tab;
							if (sk2 == ')') lib.x2 -= lib.tab;
							lib.f = V;
							i(lib.f, lib.x1, lib.x2, lib.tab);
							break;
						case 2:
							if (sk1 == '(') lib.x1 += lib.tab;
							if (sk2 == ')') lib.x2 -= lib.tab;
							lib.f = V;
							file(lib.f, lib.x1, lib.x2, lib.tab);
							break;
						}
						break;
					}
					break;
				case 2:
					puts("");
					printf("          |------------------Функция------------------|\n");
					printf("          |  Какой график функции построить y или v?  |\n");
					printf("          |-------------------------------------------|\n");
					scanf(" %c", &f);
					if (f == 'y')
					{
						lib.f = Y;
						plot(lib.x1, lib.x2, lib.f);
					}
					if (f == 'v')
					{
						lib.f = V;
						plot(lib.x1, lib.x2, lib.f);
					}
					break;
				}
			default:
				break;
			}
			break;
		case 2:
			puts("");
			int s;
			int flag = 0, shift;
			int** arr;
			srand(time(NULL));
			printf("          |         Введите размерность:       |\n");
			scanf("%d", &s);
			arr = (int**)malloc(s * sizeof(int*));
			for (int i = 0; i < s; i++)
			{
				arr[i] = (int*)malloc(s * sizeof(int));
				for (int j = 0; j < s; j++)
				{
					arr[i][j] = -10 + 1 * (10 - (-10)) * rand() / RAND_MAX;
					printf("%3d ", arr[i][j]);
				}
				printf("\n");
			}
			puts("");
			while (flag != 3)
			{
				printf("          |----------------Сдвиг----------------|\n");
				printf("          |              1.В право              |\n");
				printf("          |               2.Вниз                |\n");
				printf("          |-------------------------------------|\n");
				scanf("%d", &flag);
				switch (flag)
				{
				case 1:
					printf("          |       Введите желаемый сдвиг:       |\n");
					scanf("%3d", &shift);
					shiftr(arr, s, shift);
					for (int i = 0; i < s; i++)
					{
						for (int j = 0; j < s; j++)
						{
							printf("%3d ", arr[i][j]);
						}
						printf("\n");
						free(arr[i]);
					}
					free(arr);
					break;
				case 2:
					printf("          |       Введите желаемый сдвиг:       |\n");
					scanf("%3d", &shift);
					shiftd(arr, s, shift);
					for (int i = 0; i < s; i++)
					{
						for (int j = 0; j < s; j++)
						{
							printf("%3d ", arr[i][j]);
						}
						printf("\n");
						free(arr[i]);
					}
					free(arr);
					break;
				default:
					break;
				}
				break;
			}
			break;
		}
	}
}
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
	int SCREENW = 120, SCREENH = 20;
	char screen[120][20];
	double x, y[120];
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
int* shiftr(int** arr, int s, int shift)
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
	return arr;
}
int* shiftd(int** arr, int s, int shift)
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
	return arr;
}