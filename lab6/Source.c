#include<stdio.h>
#include<locale.h>
#include<math.h>
void main(void)
{
	setlocale(LC_ALL, "RUS");
	int year, x, s;
	float F,n,m;
	puts("������� ���");
	scanf("%d", &year);
	if (((year % 4 == 0) || (year % 400 == 0)) && (year % 100 != 0))
	{
		printf("%d - ����������\n", year);
	}
	else
	{
		printf("%d - �� ����������\n", year);
	}
	puts("������� x");
	scanf("%d", &x);
	(x <= 7) ? printf("%f\n", F = 3 * x - 9) : printf("%f\n", F = 1 / (pow(x, 2) - 4));
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if ((a>b)&&((a && b) > c))
	{
		printf("%d", s = a * 100 + b * 10 + c);
	}
	else
	if ((a > c)&&((a&&c) > b))
	{
		printf("%d", s = a * 100 + c * 10 + b);
	}
	else
	if ((b > a)&&((b&&a) > c))
	{
		printf("%d", s = b * 100 + a * 10 + c);
	}
	else
	if ((b > c)&&((b&&c) > a))
	{
		printf("%d", s = b * 100 + c * 10 + a);
	}
	else
	if ((c > a)&&((a&&c) > b))
	{
		printf("%d", s = c * 100 + a * 10 + b);
	}
	else
	if ((c > b)&&((c&&b) > a))
	{
		printf("%d", s = c * 100 + b * 10 + a);
	}
}
