#include<stdio.h>
#include<math.h>
#include<locale.h>
void main()
{
	setlocale(LC_ALL, "RUS");
	float a = 0, b = 0, c = 0, okr = 0, okrmod = 0,x=0,z=0,y=0;
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
	printf("���������� ����������� ������� � ���������=%f\n", fabs(((okr - (a / b))/(a/b))*100));
	printf("���������� ����������� ����� � ���������=%f\n", fabs(((okrmod - sqrt(c))/sqrt(c))*100));
	(fabs(((okr - (a / b)) / (a / b)) * 100)) < fabs(((okrmod - sqrt(c)) / sqrt(c)) * 100) ? printf("������� ������\n") : printf("������ ������\n");
	printf("������� ����� ��� �������� �����������:");
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
