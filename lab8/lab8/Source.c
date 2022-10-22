#include<locale.h>
#include<stdio.h>
#include<math.h>
float F(float x)
{
	float k = pow(x, 3) - 4 * pow(x, 2) + 2;
	return k;
}
void main()
{
	setlocale(LC_ALL, "RUS");
	/*int a, c;
	char b;
	printf("¬ведите симаол и его количество:");
	scanf("%c%d",&b,&a);
	c = a++;
	for (int start = 1; start <= a; start++) 
	{ 
		printf("%c", b);
		putchar('!');
	}
	for (int start = c; start <= c; start++)
	{
		putchar('+');
	}
	puts("");
	for (int start = 1; start <= 10; start++)
	{
		putchar('+');
		putchar('!');
	}
	for (int start = 11; start <= 20; start++)
	{
		putchar('-');
		putchar('!');
	}*/
	int n, m,s,i,t;
	scanf("%d%d",&n,&m);
	s = 0;
	for (int i = m; i >= n; i--)
	{
		s+=i;
		printf("выполнено %d раз\n", i+1);
	}
	printf("результат %d\n", s);
	float y,k,x,l,h;
	puts("y=x^3-4*x^2+2");
	puts("¬ведите шаг табул€ци");
	scanf("%f",&l);
	for (float x = 1; x <= 3; x+=l)
	{
         y = F(x);
		 puts("______________\n");
		 printf("|%.3f|%.3f|\n", x, y);
		 puts("______________\n");
	}
	puts("¬ведите целое число");
	scanf("%d", &t);
	h = 1;
	for (float j = 1; j <= t; j+=0.1)
	{
		h = h * j;
	}
	puts("–езультат:");
	printf("%f", h);
}