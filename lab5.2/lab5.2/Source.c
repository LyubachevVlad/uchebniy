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
	puts("¬ведите число радиан");
	scanf("%f", &x);
	rad = R(x);
	printf("%.6f радиан=%.6f градусов\n", x, rad);
	a = A(x);
	b = B(x);
	y = Y(x);
	printf("«начение y=%f\n", y);
	Z = (int)a;
	X = (int)b;
	C = (int)y;
	printf("\n цела€ часть от Z=%d, цела€ часть от X=%d, цела€ часть от C=%d\n", Z, X, C);
	if (((Z % 2 == 0) && (X % 2 != 0)) || ((Z % 2 != 0) && (X % 2 == 0)))
	{
		puts("только одно из чисел Z и X четное: 1\n");
	}
	else
	{
		puts("только одно из чисел Z и X четное: 0\n");
	}
	if ((Z % 3 == 0) && (X % 3 == 0) && (C % 3 == 0))
	{
		puts("каждое из чисел Z,X,— кратно трем: 1\n");
	}
	else
	{
		puts("каждое из чисел Z,X,— кратно трем: 0\n");
	}
}