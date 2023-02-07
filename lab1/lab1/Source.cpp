#include <iostream>
#include <cmath>
#include <valarray>
#define E 0.001
using  namespace std;
double fun1(double a, double b)
{
	double c;
	c = pow(sin(a + pow(b, 3)), 2) * (sqrt(exp((pow(a, 2) - 9, 4))) / (pow(a + b, 3)));
	return (c);
}
double fun2()
{
	double x=0,z=0,sum=0,zold=0;
	if ((zold - z) != E)
	{
		for (int n = 1; n <= 1000; n++)
		{
			for (x = -0, 95; x <= 0, 95; x + 0, 05)
			{
				z = pow(-1, n - 1) * pow(x, n - 1);
				zold = pow(-1, n - 2) * pow((x - 0, 05), n - 2);
				sum += z;
			}
		}
	}
	else
	{
		return sum;
	}
}
int main()
{
	setlocale(LC_ALL, "RUS");
	double a, b, c;
	cout << "¬ведите любые числа, дл€ счЄта алгебраического выражени€(через пробел) и нажмите Enter:";
	cin >> a >> b;
	std::cout<<("%dl",fun1(a, b));
	puts("");
	std::cout<<("%dl", fun2());
}
