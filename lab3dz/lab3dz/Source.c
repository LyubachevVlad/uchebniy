#include <locale.h>
#include <stdio.h>
#include <math.h>
#define p 3.14
void main(void)
{
	setlocale(LC_ALL, "RUS");
	double w;
	float r,l,s,j,grad;
	puts("¬ведите число радиан");
	scanf("%lf", &w);
	puts("¬ведите радиус");
	scanf("%f", &r);
	l = (p * r * w) / 180.;
	s = (w / 2) * r * r;
	j = 2 * r * sin(w / 2.);
	printf("ƒлина дуги %4f\n", l);
	printf("ѕлощадь сектора %4f\n", s);
	printf("ƒлина хорды %4f\n", j);

}