#include <stdio.h>
#include <locale.h>
#include <math.h>
double Y(double x)
{
	double y;
	y = exp(x) + 5 + cos(0.001 * x);
	return y;
}
double F(double x)
{
	double f;
	if (x >= 1)
	{
		f = x + x;
	}
	if (x<1)
	{
		f = pow(x, 3) + 0.2;
	}
	return f;
}
double V(double x)
{
	double v;
	v = 2 * pow(cos(pow(x, 2)), 3) + pow(sin(pow(x, 3)), 2) - 0.08 * F(x);
	return v;
}
typedef double (*Tfun)(double);
double Y(double);
double F(double);
double V(double);
void i(Tfun f, double xn, double xk, double h)
{
	char u = ' ';
	printf("\n|%2cx%2c|%4cF(x)%5c|",u,u,u,u);
	for (double x = xn; x <= xk; x += h)
	{
		printf("\n|%5.2lf|%13.6lf|", x, f(x));
	}
}
void plot(double x0, double x1, Tfun f)
{
	int SCREENW = 40, SCREENH = 40;//������� ���� ������ � ��������
	char screen[40][40];
	double x, y[40];
	double ymin = 0, ymax = 0;
	double hx, hy;
	int i, j;
	int xz, yz;
	hx = (x1 - x0) / (SCREENW - 1);
	for (i = 0, x = x0; i < SCREENW; ++i, x += hx)
	{
		y[i] = f(x); //������ �������� ������� ��� ������ ����� ���� ������ �������
		if (y[i] < ymin) ymin = y[i];
		if (y[i] > ymax) ymax = y[i];
	}
	hy = (ymax - ymin) / (SCREENH - 1);
	yz = (int)floor(ymax / hy + 0.5);
	xz = (int)floor((0. - x0) / hx + 0.5);
	//���������� ���� � ���������� ������� ����������� ���������
	for (j = 0; j < SCREENH; ++j)
		for (i = 0; i < SCREENW; ++i)
		{
			if (j == yz && i == xz) screen[i][j] = '+';
			else if (j == yz) screen[i][j] = '-';
			else if (i == xz) screen[i][j] = '|';
			else screen[i][j] = ' ';
		}
	//����������� ��������� �������� ������� �� ���� ������
	for (i = 0; i < SCREENW; ++i)
	{
		j = (int)floor((ymax - y[i]) / hy + 0.5);
		screen[i][j] = '*';
	}
	//������ ������� ��������
	for (j = 0; j < SCREENH; ++j)
	{
		for (i = 0; i < SCREENW; ++i)  putchar(screen[i][j]);
		putchar('\n');
	}
}
void main()
{
	setlocale(LC_ALL, "RUS");
	double x, x1, x2, tab;
	char c = '0', sk1, sk2,f;
	while (c != '6')
	{
		puts("\n����� ��������:\n 1.����� �������� ������� Y(x)\n 2.����� �������� ������� F(x)\n 3.��������� �������� ������� Y(x) �� �������� ���������, ������������� ��� �������\n 4.��������� �������� ������� V(x) �� �������� ��������� ������������� ��� �������\n 5.��������� ������, ��������� ������� Y(x) � F(x)\n 6.���������� ������ ");
		scanf("%c", &c);
		switch (c)
		{
		case'1':
			puts("\n������� ���������� x:");
			scanf("%lf", &x);
			printf("\n%lf", Y(x));
			break;
		case'2':
			puts("\n������� ���������� x:");
			scanf("%lf", &x);
			printf("%lf\n", V(x));
			break;
		case'3':
			puts("\n������� ��������:");
			scanf(" %c%lf%lf%c", &sk1 ,&x1, &x2,&sk2);
			puts("\n������� ��� ���������:");
			scanf(" %lf", &tab);
			if (sk1 == '(') x1 += tab;
			if (sk2 == ')') x2 -= tab;
			i(Y, x1, x2, tab);
			break;
		case'4':
			puts("\n������� ��������:");
			scanf(" %c%lf%lf%c", &sk1, &x1, &x2, &sk2);
			puts("\n������� ��� ���������:");
			scanf("%lf", &tab);
			if (sk1 == '(') x1 += tab;
			if (sk2 == ')') x2 -= tab;
			i(V, x1, x2, tab);
			break;
		case'5':
			puts("\n������� ��������:");
			scanf(" %c%lf%lf%c", &sk1, &x1, &x2, &sk2);
			puts("\n������� ��� ���������:");
			scanf(" %lf", &tab);
			puts("����� ������� ����������?");
			scanf(" %c", &f);
			if (f=='y') plot(x1, x2, Y);
			if (f=='v') plot(x1, x2, V);
			break;
		default:
			puts("����������� ������");
			break;
		}
		break;
	}
}