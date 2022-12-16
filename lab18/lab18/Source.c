#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
struct point 
{
	float x;
	float y;
	char name;
};
typedef struct point Point;
struct tm* mytime;
void put_point(Point z);
float dist(Point z, Point w);
float newpointx(Point z, Point w);
float newpointy(Point z, Point w);
void quarter(Point z);
void main() 
{
	setlocale(LC_ALL, "RUS");
	Point b, a, c,z,w,A,B,M1;
	a = (Point){ 1.f,2.f,'A' };
	b.name = 'B'; b.x = 5; b.y = -3;
	c.name = 'C'; c.x = 2; c.y = -1;
	z.name = 'M'; z.x = newpointx(b, c); z.y = newpointy(b, c);
	A.name = 'A'; A.x; A.y;
	B.name = 'B'; B.x; B.y;
	put_point(b);
	put_point(c);
	printf("\n����������= %.2f", dist(b, c));
	put_point(z);
	printf("\n������� ���������� ����� �: ");
	scanf("%f%f", &A.x, &A.y);
	printf("\n������� ���������� ����� B : ");
	scanf("%f%f", &B.x, &B.y);
	printf("\n���������� x ��� ����� ����� M1: %.1f", newpointx(A, B));
	printf("\n���������� y ��� ����� ����� M1: %.1f", newpointy(A, B));
	M1.name = 'M1'; M1.x = newpointx(A, B); M1.y = newpointy(A, B);
	puts("");
	put_point(M1);
	quarter(M1);
	puts("");
	time_t t;
	t = time(NULL);
	mytime = localtime(&t);
	printf("���������� ����� %02d:%02d:%02d \n", mytime->tm_hour, mytime->tm_min, mytime->tm_sec);
	for (int i = 0; i < 80; i++)
	{
		printf("*");
	}
	printf("� ������ ���� ������ %02d:%02d", (mytime->tm_hour) - 8, mytime->tm_min);
	for (int i = 0; i < 80; i++)
	{
		printf("*");
	}
}
void put_point(Point z) 
{
	printf("\npoint %c (%.1f, %.1f)", z.name, z.x, z.y);
}
float dist(Point z, Point w)
{
	float y;
	y = sqrt(pow(z.x - w.x, 2) + pow(z.y - w.y, 2));
	return y;
}
float newpointx(Point z, Point w)
{
	float x;
	x = (z.x + w.x) / 2;
	return x;
}
float newpointy(Point z, Point w)
{
	float y;
	y = (z.y + w.y) / 2;
	return y;
}
void quarter(Point z)
{
	if (z.x > 0 && z.y > 0) printf("\n����� ����� � I ��������");
	else if (z.x < 0 && z.y > 0) printf("\n����� ����� �� II ��������");
	else if (z.x < 0 && z.y < 0) printf("\n����� ����� � III ��������");
	else if (z.x > 0 && z.y < 0) printf("\n����� ����� � IV ��������");
}