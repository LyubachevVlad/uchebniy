#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
void main()
{
	//������� 1
	setlocale(LC_ALL, "RUS");
	float a = 0, b = 0, c = 0, okr = 0, okrmod = 0, x = 0, z = 0, y = 0;
	printf("������� �����: ");
	scanf("%f", &a);
	scanf("%f", &b);
	printf("����������� ��������=%f\n", a / b);
	printf("����������� ��������=%.2f\n", a / b);
	printf("������� �����, ������� ������ ���� ��� ������: ");
	scanf("%f", &c);
	printf("����������� ��������=%f\n", sqrt(c));
	printf("����������� ��������=%.2f\n", sqrt(c));
	printf("������� ����������� �������� �������: ");
	scanf("%f", &okr);
	printf("������� ����������� �������� �����: ");
	scanf("%f", &okrmod);
	printf("���������� ����������� �������=%f\n", fabs(okr - (a / b)));
	printf("���������� ����������� �����=%f\n", fabs(okrmod - sqrt(c)));
	printf("���������� ����������� ������� � ���������=%f\n", fabs(((okr - (a / b)) / (a / b)) * 100));
	printf("���������� ����������� ����� � ���������=%f\n", fabs(((okrmod - sqrt(c)) / sqrt(c)) * 100));
	(fabs(((okr - (a / b)) / (a / b)) * 100)) < fabs(((okrmod - sqrt(c)) / sqrt(c)) * 100) ? printf("������� ������\n") : printf("������ ������\n");
	//������� 2
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
	printf("����� � ������� �������: %lf\n", sum);
	printf("���������� �����������: %lf\n", sum*sigma);
    //������� 3
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
	printf("���������� ����������� �����: %lf\n", abspog);
	printf("������������� ����������� �����: %lf(� ���������)\n", (abspog / number) * 100);
}