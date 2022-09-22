#include<locale.h>
#include<stdio.h>
#define b 20
#define h 5
float BAG(float bag,float n)
{
	float prb = (bag - b) * n;
	return prb;
}
float RUCH(float ruch, float v)
{
	float prr = (ruch - h) * v ;
	return prr;
}
void main(void)
{
	setlocale(LC_ALL, "RUS");
	float bag, ruch,prb,prr,v,n;
	puts("¬ведите массу багажа");
	scanf("%f%f", &bag,&n);
	puts("¬ведите массу ручной клади");
	scanf("%f%f", &ruch,&v);
	prb = BAG(bag, n);
	prr = RUCH(ruch, v);
	printf("—чет за багаж - %f\n", prb);
	printf("—чет за ручную кладь - %f\n", prr);
}