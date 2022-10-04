#include<locale.h>
#include<stdio.h>
#include<math.h>
#define M_PI 3.14159265358979323846
#define c 0.4
float R(float x)
{
	float rad = sin(x * M_PI / 180);
	return rad;
}
float A(float x)
{
	float a = log10(x);
	return a;
}
float B(float x)
{
	float b = A(x) * A(x) + sqrt(x * c);
	return b;
}
float Y(float x)
{
	float y = exp(2 * x) + pow(9.7, B(x));
	return y;
}
void main(void)
{
	setlocale(LC_ALL, "RUS");
	float rad, a, b, x, y;
	int	C, Z, X;
	puts("������� ����� ������");
	scanf("%f", &x);
	rad = R(x);
	printf("%.6f ������=%.6f ��������\n", x, rad);
	a = A(x);
	b = B(x);
	y = Y(x);
	printf("�������� y=%f\n", y);
	Z = (int)a;
	X = (int)b;
	C = (int)y;
	printf("\n ����� ����� �� Z=%d, ����� ����� �� X=%d, ����� ����� �� C=%d\n", Z, X, C);
	if (((Z % 2 == 0) && (X % 2 != 0)) || ((Z % 2 != 0) && (X % 2 == 0)))
	{
		puts("������ ���� �� ����� Z � X ������: 1\n");
	}
	else
	{
		puts("������ ���� �� ����� Z � X ������: 0\n");
	}
	if ((Z % 3 == 0) && (X % 3 == 0) && (C % 3 == 0))
	{
		puts("������ �� ����� Z,X,� ������ ����: 1\n");
	}
	else
	{
		puts("������ �� ����� Z,X,� ������ ����: 0\n");
	}
}