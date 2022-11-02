#include<locale.h>
#include<stdio.h>
void main(void)
{
	setlocale(LC_ALL, "RUS");
	int x,y;
	puts("Введите двузначное число\n");
	scanf("%d",&x);
	y = x % 10;
	if ((y == 1) || (y == 2) || (y == 3) || (y == 5) || (y == 7))
	{
		puts("Число является простым");
	}
	else
	{
		puts("Число не являестся простым");
	}
}