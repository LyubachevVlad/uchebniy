#include <iostream>
#include <cmath>
#include <valarray>
#define E 0.001
using  namespace std;
double fun1(double a, double b)
{
	double c;
	c = pow(sin(a + pow(b, 3)), 2) * sqrt((exp(pow(a, 2) - 9.4)) / (pow(a + b,3)));
	return (c);
}
double fun2(double x)
{
	double z = 1,sum = 1;
	int n = 1;
	for (int i = 0; i < n; i++,n++)
	{
		if ((z > 0 ? z : -z) > E)
		{
			z *= -x;
			sum += z;
		}
		else 
		{
            return sum;
		}
	}
}
int main()
{
	setlocale(LC_ALL, "RUS");
	double a, b, c, x;
	std::cout << "¬ведите два числа и нажмите Enter:";
	std::cin >> a >> b;
	std::cout << ("%dl", fun1(a, b));
	puts("");
	std::cout << "x = ";
	std::cin >> x;
	std::cout << "sum = ";
	std::cout << ("%dl", fun2(x));
}
