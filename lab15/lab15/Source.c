#include<locale.h>
#include<stdio.h>
#include<stdlib.h>
void main()
{
	setlocale(LC_ALL, "RUS");
	float arr[50][50], a, b,min=5;
	int i, j, s, s1,k,o,kol=0,kol2=0,max=-11,x,y,sum=0,n=0;
	srand(time(NULL));
	printf("Введите количество строк:");
	scanf("%d", &s);
	printf("Введите количество столбцов:");
	scanf("%d", &s1);
	printf("В какой строке найти минимум? ");
	scanf("%d", &k);
	for (i = 1; i < s + 1; i++)
	{
		a = (float)i;
		for (j = 1; j < s1 + 1; j++)
		{
			b = (float)j;
			arr[i][j] = a / b;
			printf("%.2f ", arr[i][j]);
			if (i == k && arr[i][j] < min)
			{
				min = arr[i][j];
			}
		}
		printf("\n");
	}
	printf("\n%.2f\n", arr[1][1]);
	printf("Минимум=%.2f", min);
	puts("");
	int mas[7][7];
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			mas[i][j] = -11 + 1. * (11 - (-11)) * rand() / RAND_MAX;
			printf("%3d ", mas[i][j]);
		}
		printf("\n");
	}
	puts("");
	int kup[7][7];
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			kup[i][j] = mas[j][i];
			printf("%3d ", kup[i][j]);
			if (j == 1 && kup[i][j] < -5)
			{
				kol++;
			}
			if (kup[i][j] == kup[i][j+1])
			{
				kol2++;
			}
		}
		printf("\n");
	}
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (kup[i][j] == kup[i][j + 1])
			{
				kol2++;
			}
			if (kup[i][j] >= max)
			{
				max = kup[i][j];
				x = i;
				y = j;
			}
		}
	}
	printf("\nКоличество элементов меньше -5 = %d", kol);
	printf("\nКоличество пар одиноковых элементов в одной сторке = %d", kol2);
	printf("\nКоординаты максимального элемента = (%d;%d)", x, y);
	puts("");
	int zp[12][20];
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				zp[i][j] = 16000 + 1. * (50000 - 16000) * rand() / RAND_MAX;
				printf("%3d ", zp[i][j]);
				sum += zp[i][j];
				
			}
			n++;
			printf("\nСотрудник %d заработал за год %d", n, sum);
			printf("\n");
		    sum = 0;
		}
		
}