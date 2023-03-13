#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
void main()
{
	//Задание 1
	setlocale(LC_ALL, "RUS");
	float a = 0, b = 0, c = 0, okr = 0, okrmod = 0, x = 0, z = 0, y = 0;
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
	printf("Абсолютная погрешность деления в процентах=%f\n", fabs(((okr - (a / b)) / (a / b)) * 100));
	printf("Абсолютная погрешность корня в процентах=%f\n", fabs(((okrmod - sqrt(c)) / sqrt(c)) * 100));
	(fabs(((okr - (a / b)) / (a / b)) * 100)) < fabs(((okrmod - sqrt(c)) / sqrt(c)) * 100) ? printf("Деление точнее\n") : printf("Корень точнее\n");
	//Задание 2
	double p = 0.85638;
	double k = 10;
	double f, g, h, j, sigma = 0.0022, sum = 0;
	for (int i = 0; i < 5; i++)
	{
		f = p * k;
		g = (int)f;
		h = g / k;
		p = p - h;
		k *= 10;
		if (h > sigma)
		{
			sum += h;
		}
	}
	printf("Число с верными знаками: %lf\n", sum);
	printf("Абсолютная погрешность: %lf\n", sum*sigma);
    //Задание 3
	double number;
	double abspog;
	char str[16] = "231,57";
	number = atof(str);
	int flag = 0;
	int counter = 0;
	for (int i = 0; i < strlen(str); i++) 
	{
		if (str[i] == ',') flag = 1;
		if (flag) 
		{
			counter++;
		}
		printf("%c\n", str[i]);
	}
	printf("%d\n", counter);
	abspog = (1. / 2) * pow(10, (-1 * counter) + 1);
	printf("Абсолютная погрешность равна: %lf\n", abspog);
	printf("Относительная погрешность равна: %lf(в процентах)\n", (abspog / number) * 100);
}