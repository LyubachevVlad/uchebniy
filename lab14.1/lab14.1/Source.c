#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<ctype.h>
double* full_elements(double* ptr_array, int n);
int put_elements(double* ptr_array, int n);
double* calc_elements(double* ptr_array, int n);
int put_elements2(double* ptr_array, int n);
double sum_elements(double* ptr_array, int begin, int end);
int find_element(double* ptr_array, int n, double element);
double function_min(double* ptr_array, int n, int k);
void main()
{
	setlocale(LC_ALL, "RUS");
	int N,size,begin,end,k;
	double sum=0,element;
	printf("Введите размер массива > ");
	scanf("%d", &size);
	double* array = (double*)calloc(size, sizeof(double));
	full_elements(array, size);
	put_elements(array, size);
	puts("\n");
	calc_elements(array, size);
	put_elements2(array, size);
	printf("Промежуток для суммы: ");
	scanf("%d%d", &begin, &end);
	sum_elements(array, begin, end);
	printf("Введите число которое хотите найти: ");
	scanf("%lf", &element);
	printf("Позиция найденого элемента=%d\n",find_element(array, size, element));
	printf("Введите число которому должно быто кратно\n");
	scanf("%d", &k);
	function_min(array,size,k);
}
double* full_elements(double* ptr_array, int n)
{
	srand(time(NULL));
	for (int i = 0;i < n;i++)
	{
		ptr_array[i] = rand() % 101 - 50;
	}
	return ptr_array;
}
int put_elements(double* ptr_array, int n)
{
	for (int i = 0;i < n;i++)
	{
		printf("A[%d]=%lf\n",i, ptr_array[i]);
	}
	return 0;
}
double* calc_elements(double* ptr_array, int n)
{
	for (int i = 0;i < n;i++)
	{
		if (ptr_array[i] < 0)
		{
			ptr_array[i] = 0;
		}
	}
	return ptr_array;
}
int put_elements2(double* ptr_array, int n)
{
	for (int i = 0;i < n;i++)
	{
		printf("A[%d]=%lf\n", i, ptr_array[i]);
	}
	return 0;
}
double sum_elements(double* ptr_array, int begin, int end)
{
	double sum=0;
	for (int i = begin;i < end;i++)
	{
		sum += ptr_array[i];
	}
	printf("\nСумма элементов промежутка=%lf\n", sum);
}
int find_element(double* ptr_array, int n, double element)
{
	int pos = 0;
	for (int i = 0;i < n;i++)
	{
		if (ptr_array[i] == element)
		{
			pos=i;
			return pos;
		}
	}
	return -1;
}
double function_min(double* ptr_array, int n, int k)
{
	double min = -10000000, d = 0;;
	for (int i = 0;i <= n;i++)
	{
		d = ptr_array[i] / k;
		printf("%lf\n", d);
		if ((k * d == ptr_array[i])||(ptr_array[i] < min))
		{
			min = ptr_array[i];
		}
	}
	printf("Минимальное число кратное к=%lf", min);
}


