#include <stdio.h>
#include<locale.h>
#define d 2.54
#define f 2.32166
void main(void)
{
	setlocale(LC_ALL, "RUS");
    int k,dym,g,a,b;
	float result,result2,num;
	puts("введите число\n");
	scanf("%d%f%a",&k,&num,&a);
	printf("сумма=%f\n разность=%f\n произведение=%\n частное=%f\n остаток отделени€=%d\n",num+k,k-num,num*k,k/num,k%a);
	puts("введите число\n");
	scanf("%d",&dym);
	result = d * dym;
	result2 = f * dym;
	printf("%d дюймов Ц это %.2f см\n", dym, result);
	printf("%d испанских дюймов Ц это %.2f см \n", dym, result2);
	scanf("%d%d", &a, &b);
	puts("-------------");
	puts("|a*b|a+b|a-b|");
	puts("-------------");
	printf("|%d*%d|%d+%d|%d-%d|\n", a, b, a, b, a, b);
	puts("-------------");
	printf("| %d| %d| %d|\n", a * b, a + b, a - b);
	puts("-------------");

}