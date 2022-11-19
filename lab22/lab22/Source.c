#include<stdio.h>
#include<locale.h>
#include<math.h>
double fun_Y(double x)
{
	double y;
	if (x > 0)
	{
		y = log(fabs(sqrt(pow(x, 3))));
	}
	return y;
}
double fun_V(double x)
{
	double v;
	if (x > 1)
	{
		v = sqrt(tan(pow(x, 2) - 1));
	}
	if (0 <= x && x <= 1)
	{
		v = -2 * x;
	}
	if (x < 0)
	{
		v = exp(cos(x));
	}
	return v;
}
double fun_S(double x)
{
	double s = ((x - 1) / (x + 1)) + (1 / 3) * pow(((x - 1) / (x + 1)), 3) + (1 / 5) * pow(((x - 1) / (x + 1)), 5) + (1 / 7) * pow(((x - 1) / (x + 1)), 7);
	return s;
}
typedef double (*Tfun) (double);
double y(double);
double v(double);
double s(double);
void result(Tfun f, double xn, double xk, double h)
{
	for (double x = xn; x <= xk; x += h)
		printf("x=%5.10f,y=%8.10f\n", x, f(x));
}
void plot(double x0, double x1, Tfun f)
{
    int SCREENW = 60, SCREENH = 40;//размеры пол€ вывода в символах
    char screen[60][40];
    double x, y[60];
    double ymin = 0, ymax = 0;
    double hx, hy;
    int i, j;
    int xz, yz;
    hx = (x1 - x0) / (SCREENW - 1);
    for (i = 0, x = x0; i < SCREENW; ++i, x += hx)
    {
        y[i] = f(x); //расчет значений функции дл€ каждой точки пол€ вывода графика
        if (y[i] < ymin) ymin = y[i];
        if (y[i] > ymax) ymax = y[i];
    }
    hy = (ymax - ymin) / (SCREENH - 1);
    yz = (int)floor(ymax / hy + 0.5);
    xz = (int)floor((0. - x0) / hx + 0.5);
    //построение осей и заполнение массива отображени€ пробелами
    for (j = 0; j < SCREENH; ++j)
        for (i = 0; i < SCREENW; ++i)
        {
            if (j == yz && i == xz) screen[i][j] = '+';
            else if (j == yz) screen[i][j] = '-';
            else if (i == xz) screen[i][j] = '|';
            else screen[i][j] = ' ';
        }
    //определение положени€ значени€ функции на поле вывода
    for (i = 0; i < SCREENW; ++i)
    {
        j = (int)floor((ymax - y[i]) / hy + 0.5);
        screen[i][j] = '*';
    }
    //печать массива символов
    for (j = 0; j < SCREENH; ++j)
    {
        for (i = 0; i < SCREENW; ++i)  putchar(screen[i][j]);
        putchar('\n');
    }
}
void main()
{
	setlocale(LC_ALL, "RUS");
	double x1, x2, shag;
	printf("¬ведите интервал:");
	scanf("%lf%lf", &x1, &x2);
	printf("¬ведите шаг:");
	scanf("%lf", &shag);
	printf("Y(x)\n");
	result(fun_Y, x1, x2, shag);
	printf("V(x)\n");
	result(fun_V, x1, x2, shag);
	printf("S(x)\n");
	result(fun_S, x1, x2, shag);
    plot(x1, x2, fun_S);
}