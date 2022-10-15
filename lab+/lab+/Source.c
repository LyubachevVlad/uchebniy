#include<locale.h>
#include<stdio.h>
void main(void)
{
	setlocale(LC_ALL, "RUS");
	int x, y;
	puts("Введите координаты");
	scanf("%d%d", &x, &y);
	if (((x <= 2) && (y <= 4) && (y >= -3) && (x >= 0)) || ((x >= -2) && (y <= 2) && (y >= -3) && (x <= 0)) || ((x <= 5) && (y <= 0) && (y >= -3) && (x >= 2)) || ((x >= -2) && (x <= 0) && (y >= -3) && (y <= 4)) || ((x >= -4) && (x <= -2) && (y >= -3) && (y <= 0)))
	{
		puts("Попадает");
	}
	else
	{
		puts("Не попадает");
	}
}