#include <stdio.h>
#include <locale.h>
void main(void)
{
	int N, K,n,k,m;
	N = 10;
	K = 30;
	n = 3;
	setlocale(LC_ALL, "RUS");
	printf("%20s \n ", "Это текст");
	printf("\t ", "Это текст");
	printf("%10.5f\n ", 12.234657);
	printf("Остаток от деления %d на %d равен %d\n ", 5, 2, 5 % 2);
	printf("Остаток от деления %d на %d равен %d\n ", 7, 5, 7 % 5);
	printf("Умножение %d на %d равно %d\n",2000,4, 2000*4);
	printf("%g разделить %e равно %f\n ", 5., 2., 5. / 2);
	printf("Сейчас %d часов %d минут 00 секунд\n",N,K);
	printf("Идет %d минута суток\n",N+K);
	printf("До полуночи осталось %d часов и %d минут\n",K,N);
	printf("С 8.00 прошло %d секунд\n",N*K);
	printf("Текущий час  = %d/24 суток  и текущая минута = %d/60 часа\n",N,K);
	printf("\n");
	printf("%d\n",n);
	printf("333\n");
	printf("+%7.5f\n",n/333.);
	
}