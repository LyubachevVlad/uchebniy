#include<stdio.h>
#include<locale.h>
#include<math.h>
#define M_PI 3.14159265358979323846
double fa(double x)
{
	double y;
	if (x <= 3)
	{
		y = pow(x, 2) - 3 * x + 9;
	}
	else
	{
		y = 1 / (pow(x, 3) + 3);
	}
	return y;
}
double fb(double x)
{
	double y;
	y = x * exp(sin(pow(x, 2)));
	return y;
}
double sin_n(double p)
{
	double s;
	p = p * M_PI / 180;
	s = sin(p);
	return s;
}
double fac(int k)
{
	int f=1;
	for (int i = 1; i <= k; i++)
	{
		f *= i;
	}
	return f;
}
double sin_n2(double p, int N)
{
	double u = 0;
	p = p * M_PI / 180;
	for (int k = 1; k <= N; k++)
	{
		u +=(pow(-1,( k - 1)) * (pow(p, 2 * k - 1) / fac(2 * k - 1)));
	}
	return u;
}
double sin_eps(double z, double eps)
{
	double l = 0;
	int j = 1;
	z = z * M_PI / 180;
	while (fabs(l) > eps);
	{
		l += (pow(-1, (j - 1)) * (pow(z, 2 * j - 1) / fac(2 * j - 1)));
		j++;
	}
	return l;
}
double cosin(double y, double n)
{
	double cos = 0;
	y = y * M_PI / 180;
	for (int q = 0; q <= n; q++)
	{
		cos += (pow(-1, q) * pow(y, (2 * q))) / (fac(2 * q));
	}
	return cos;
}
void main()
{
	setlocale(LC_ALL, "RUS");
	double x, p, u,z,eps=0.001,y;
	int N = 7,n = 7;
	printf("¬ведите х и градусы\n");
	scanf("%lf%lf%lf%lf", &x, &p,&z,&y);
	printf("fa(x)=%lf , fb(x)=%lf\n ", fa(x), fb(x));
	printf("произведение=%lf,разность квадратов=%lf,удвоенна€ сумма=%lf\n", fa(x) * fb(x), pow(fa(x), 2) - pow(fb(x), 2), 2 * (fa(x) + fb(x)));
	printf("синус=%lf", sin_n(p));
	printf("\nсинус=%lf", sin_n2(p, N));
	printf("\nсинус с повышенной точностью=%lf", sin_eps(z, eps));
	printf("\nкосинус=%lf", cosin(y, n));
}