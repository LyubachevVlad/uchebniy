#include<stdio.h>
#include<math.h>
#include<locale.h>
void main()
{
	setlocale(LC_ALL, "RUS");
	float a = 0, b = 0, c = 0, okr = 0, okrmod = 0,x=0,z=0,y=0;
	printf("Введите числа: ");
	scanf("%f", &a);
	scanf("%f", &b);
	printf("Посчитанное занчение=%f\n", a / b);
	printf("Округленное значение=%.2f\n", a / b);
	printf("Введите число, которое должно быть под корнем: ");
	scanf("%f", &c);
	printf("Посчитанное значение=%f\n", sqrt(c));
	printf("Округленное значение=%.2f\n", sqrt(c));
	printf("Введите округленное значение деления: ");
	scanf("%f", &okr);
	printf("Введите округленное значение корня: ");
	scanf("%f", &okrmod);
	printf("Абсолютная погрешность деления=%f\n", fabs(okr - (a / b)));
	printf("Абсолютная погрешность корня=%f\n", fabs(okrmod - sqrt(c)));
	printf("Абсолютная погрешность деления в процентах=%f\n", fabs(((okr - (a / b))/(a/b))*100));
	printf("Абсолютная погрешность корня в процентах=%f\n", fabs(((okrmod - sqrt(c))/sqrt(c))*100));
	(fabs(((okr - (a / b)) / (a / b)) * 100)) < fabs(((okrmod - sqrt(c)) / sqrt(c)) * 100) ? printf("Деление точнее\n") : printf("Корень точнее\n");
	printf("Введите число для подсчета погрешности:");
	scanf("%f", &x);

	float y = x;
	int z = 0;
	for (int i = 0;i < 100;i++)
	{
		if (y < 1)
		{
			y *= 10;
			z += 1;
		}
		else break;
	}
	float  = round(x*pow(10,z)/(pow(10,z)))
}
