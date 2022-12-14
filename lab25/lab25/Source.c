#include<locale.h>
#include<stdio.h>
#include<stdlib.h>
int rand10(int mmax);
double rand_double(double dmin, double dmax);
int* randmassiv(int n, int mmax);
double* randlfmassiv(int n, double dm);
int* rand20(int n, int mmax);
int gistagram(int* c, int l);
void main()

{
	setlocale(LC_ALL, "RUS");
	int k = 0, kub1 = 0, kub2 = 0, kub3 = 0, kub4 = 0;
	srand(time(NULL));
	int m = 1 + rand() % 10;
	printf("Попробуйте угадать число:");
	scanf("%d", &k);
	if (m == k)
	{
		printf("Поздравляем вы угадали число!!!\n");
	}
	else
	{
		printf("Вы не угадали,загаданное число %d\n", m);
	}
	printf("КОСТИ\n");
	printf("Бросает перый игрок\n");
	srand(time(NULL));
	kub1 = 1 + rand() % 6;
	kub2 = 1 + rand() % 6;
	printf("Бросает второй игрок\n");
	kub3 = 1 + rand() % 6;
	kub4 = 1 + rand() % 6;
	if ((kub1 + kub2) == (kub3 + kub4))
	{
		printf("результат превого игрока=%d,а результат второго=%d\n", kub1 + kub2, kub3 + kub4);
		printf("Ничья!!!");
	}
	else if ((kub1 + kub2) > (kub3 + kub4))
	{
		printf("результат превого игрока=%d,а результат второго=%d\n", kub1 + kub2, kub3 + kub4);
		printf("Поздравляем игорка номер один!!!");
	}
	else
	{
		printf("результат превого игрока=%d,а результат второго=%d\n", kub1 + kub2, kub3 + kub4);
		printf("Поздравляем игрока номер два!!!");
	}
	int mmax;
	printf("\nВведите максимальное число в рандоме: ");
	scanf("%d", &mmax);
	printf("\nРандомное целое число: %d", rand10(mmax));
	double dmin, dmax;
	printf("\nВведите интервал из вещественных чисел: ");
	scanf("%lf%lf", &dmin, &dmax);
	printf("\nРандомное вещественное число: %lf", rand_double(dmin, dmax));
	int size;
	double dm;
	printf("\nВведите размер для рандомного массива: ");
	scanf("%d", &size);
	randmassiv(size, mmax);
	printf("\nВведите размер для рандомного массива: ");
	scanf("%d", &size);
	printf("\nВведите масимальное вещественное число в рандоме: ");
	scanf("%lf", &dm);
	randlfmassiv(size, dm);
	int Size, mx;
	puts("\n\n\nВведите длину массива рандомных чисел: ");
	scanf("%d", &Size);
	puts("\nВведите максимальное рандомное число: ");
	scanf("%d", &mx);
	int* cou;
	cou = (int*)calloc(mx, sizeof(int));
	int* randomA = rand20(Size, mx);

	for (int i = 0; i < Size; i++)
	{
		cou[randomA[i]]++;
	}
	for (int i = 0; i < mx; i++)
	{
		printf("\ncounter[%d] = %d", i, cou[i]);
	}
	for (int i = 0; i < Size; i++)
	{
		printf("\nrandomA[%d] = %d", i, randomA[i]);
	}
	puts("\n\n\n");
	gistagram(cou, mx);
}
int rand10(int mmax)
{
	int A = 1;
	int ch = A + rand() % (mmax - A);
	return ch;
}
double rand_double(double dmin, double dmax)
{
	double ch = dmin + 1. * (dmax - dmin) * rand() / RAND_MAX;
	return ch;
}
int* randmassiv(int n, int mmax)
{
	int A[100];
	for (int i = 0; i < n; i++)
	{
		A[i] = 1 + rand() % (mmax - 1);
	}
	for (int i = 0; i < n; i++)
	{
		printf("\nA[%d] = %d", i, A[i]);
	}
	return 0;
}
double* randlfmassiv(int n, double dm)
{
	double A[100];
	for (int i = 0; i < n; i++)
	{
		A[i] = (-1 * dm) + 1.f * (dm - (-1 * dm)) * rand() / RAND_MAX;
	}
	for (int i = 0; i < n; i++)
	{
		printf("\nA[%d] = %lf", i, A[i]);
	}
	return 0;
}
int* rand20(int n, int mmax) 
{
	int* res = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) 
	{
		res[i] = 1 + rand() % (mmax - 1);
	}
	return res;
}
int gistagram(int* c, int l) 
{
	int mx = -10000000;
	for (int i = 0; i < l; i++) 
	{
		if (c[i] > mx) 
		{
			mx = c[i];
		}
	}
	for (int i = mx; i > 0; i--) 
	{
		for (int j = 0; j < l; j++) 
		{
			if ((c[j] == i) || (c[j] > i)) 
			{
				printf("***");
			}
			else 
			{
				printf("   ");
			}
		}
		printf("\n");
	}
	return 0;
}
