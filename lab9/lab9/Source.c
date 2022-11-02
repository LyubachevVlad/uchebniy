#include<stdio.h>
#include<locale.h>
#define ROW 9
#define COL 9
void main()
{
	setlocale(LC_ALL, "RUS");
	
	int row, col,a,k,p=1,z;
	char s;
	printf("\n");
	for (row = 1; row <= ROW; ++row)
	{
		for (col = 1; col <= row; col++)
			printf("%5d", col*row);
		    printf("\n");
	}
	puts("\n");
	for (row = 5; row >= 1; row--)
	{
		for (col = 1; col <= row; col++)
			printf("%5d", row);
		    printf("\n");
	}
	while (1)
	{ 
	char b;
	puts("Введите число");
	scanf("%d", &a);
	while (a > 0)
	{
		k = a % 10;
		if (k != 0) (p *= k);
		a /= 10;
	} 
	printf("%d\n", p);

			printf("Продолжить? (Да - любой сивол, нет - n)\n");
			p = 1;
		scanf("%c", &b);
		if ((b = getchar()) == 'n') break;
	}
	int h = 0, i = 0, j = 0;
	puts("Высота треугольника");
	scanf("%d", &h);
	for (i = 0; i < h; i++, printf("\n"))
	{
		for (j = (h - i) - 1; j > 0; j--)
		{
			printf(" ");
		}
		for (j = (i * 2) + 1; j > 0; j--)
		{
			printf("*");
		}
	}
}