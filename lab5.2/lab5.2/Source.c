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
float T(float p, float l, float i)
{
	float t = ((2 * cos(p - M_PI / 6)) / (0.5 + pow(sin(l), 2))) * (1 + (pow(i, 2) /(3 - pow(i, 2) / 5)));
	return t;
}
void main(void)
{
	setlocale(LC_ALL, "RUS");
	float rad, a, b, x, y,p,l,i,k;
	int	C, Z, X,m,n;
	p = 14.26;
	l = -1.22;
	i = 3.5 * pow(10, -2);
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
	n = (((Z % 2 == 0) && (X % 2 != 0)) || ((Z % 2 != 0) && (X % 2 == 0)));
	printf("%d\n",n);
	m = ((Z % 3 == 0) && (X % 3 == 0) && (C % 3 == 0));
	printf("%d\n", m);
	k = T(p, l, i);
	printf("%f", k);
}