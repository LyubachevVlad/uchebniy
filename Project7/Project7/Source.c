#include <stdio.h>
#include<locale.h>
#define d 2.54
#define f 2.32166
void main(void)
{
	setlocale(LC_ALL, "RUS");
    int k,dym,g,a,b;
	float result,result2,num;
	puts("������� �����\n");
	scanf("%d%f%a",&k,&num,&a);
	printf("�����=%f\n ��������=%f\n ������������=%\n �������=%f\n ������� ���������=%d\n",num+k,k-num,num*k,k/num,k%a);
	puts("������� �����\n");
	scanf("%d",&dym);
	result = d * dym;
	result2 = f * dym;
	printf("%d ������ � ��� %.2f ��\n", dym, result);
	printf("%d ��������� ������ � ��� %.2f �� \n", dym, result2);
	scanf("%d%d", &a, &b);
	puts("-------------");
	puts("|a*b|a+b|a-b|");
	puts("-------------");
	printf("|%d*%d|%d+%d|%d-%d|\n", a, b, a, b, a, b);
	puts("-------------");
	printf("| %d| %d| %d|\n", a * b, a + b, a - b);
	puts("-------------");

}