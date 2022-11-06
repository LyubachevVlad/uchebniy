#include<stdio.h>
#include<locale.h>
void triangle(int h)
{
	for (int i = 0; i < h; i++, printf("\n"))
	{
		for (int j = (h - i) - 1; j > 0; j--)
		{
			printf(" ");
		}
		for (int j = (i * 2) + 1; j > 0; j--)
		{
			printf("*");
		}
	}
}
float plosh(int h)
{
	float a,s;
	a = h * 2 - 1;
	s = 0.5 * a * h;
	return s;
}
void name()
{
	printf("–авнобедренный треугольник Ч треугольник, в котором две стороны равны между собой по длине. Ѕоковыми называютс€ равные стороны, а последн€€ неравна€ им сторона Ч основанием. ѕо определению, каждый правильный треугольник также €вл€етс€ равнобедренным, но обратное утверждение неверно.");
}
void main()
{
	setlocale(LC_ALL, "RUS");
	int h,i,j;
	
	puts("¬ысота треугольника");
	scanf("%d", &h);
	
	while (1)
	{   
		int c;
		printf("1-нарисовать фигуру,2-показать площадь фигуры,3-вывести определение этой фигуры,4-выйти\n");
	    scanf("%d", &c);
		switch (c)
		{
		 case 1:
			triangle(h);
			break;
		 case 2:
			printf("S=%f", plosh(h));
			break;
		 case 3:
			name();
			break;
		}
		if (c == 4) break;
	}
}