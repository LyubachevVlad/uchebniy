#include <locale.h>
#include <stdio.h>
void main(void)
{
	setlocale(LC_ALL, "RUS");
	char c;
	int i,b=3,a=11,x,k;
	float f,y;
	double w,z;
	scanf("%c%d%f%lf",&c,&i,&f,&w);
	printf("%c,%d,%.2f,%g\n", c, i, f, w);
	printf("����� ����� ������������� ����� %d\n",(int)f);
	printf("������� ����� ������������� ����� %.2lf\n", f - (int)f);
	printf("��� ��������� ������� %d\n",(int)c);
	printf("���������� ����� ��������������� 1/i %f\n", (float)1/i);
	x = a / b;
	y = a / b;
	z = a / b;
	printf("%d,%f,%lf\n", x, y, z);
	printf("%f,%lf\n",(float)a/b,(double)a/b);
	scanf("%d\n",&k);
	printf("������ ����� - ��� %d\n, ��������� ����� - ��� %d\n, ����� ���� - ��� %d", k / 100, k % 10, (k / 100) + (k % 10) + ((k % 100) / 10));
}