#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
double* mas(int size, double* ptr_array);
double sum(int size, double* ptr_array);
double delete_k(double* ptr_array, int size, int k);
double find_element(double* ptr_array, int n, double element);
void main()
{
	setlocale(LC_ALL, "RUS");
	double* ptr_array;
	int size, k;
	srand(time(NULL));
	printf("Введите размер массива: ");
	scanf("%d", &size);
	ptr_array = (double*)malloc(size * sizeof(double));
	if (ptr_array == NULL)
	{
		puts("error");
		return -1;
	}
	mas(size, ptr_array);
	sum(size, ptr_array);
	puts("\nКакой элемент массива удалить?");
	scanf("%d", &k);
	delete_k(ptr_array, size, k);
	size--;
	for (int i = 0; i < size; i++)
	{
		printf("array[%d] = %lf\n", i, ptr_array[i]);
	}
}
double* mas(int size, double* ptr_array)
{
	for (int i = 0; i < size; i++)
	{
		ptr_array[i] = -1 + 1.f * (1 - (-1)) * rand() / RAND_MAX;
	}
	for (int i = 0; i < size; i++)
	{
		printf("\nptr_array[%d] = %lf", i, ptr_array[i]);
	}
	return ptr_array;
}
double sum(int size, double* ptr_array)
{
	int f=0,ot=0,f1=0;
	double sr2=0,pr=0;
	for (int j = 0; j < size; j++)
	{
		if (ptr_array[j] < 0)
		{
		    f = j;
			break;
		}
	}
	for (int j = f + 1; j < size; j++)
	{
		if (ptr_array[j] < 0)
		{
			f1 = j;
			break;
		}
	}
	for (int j = f + 1; j < f1; j++, ot++)
	{
			pr += ptr_array[j];
	}
	sr2 = pr / ot;
	printf("  Среднеезанчение на промежутке=%lf", sr2);
}
double delete_k(double* ptr_array, int size, int k) 
{
	int n = size - 1;
	for (int i = k; i < (size - 1); i++) 
	{
		for (int i = (find_element(ptr_array, size, k) - 1); 
			i < (size - 1); i++) ptr_array[i] = ptr_array[i + 1];
	}
	return n;
}
double find_element(double* ptr_array, int n, double element)
{
	int element1 = -1;
	for (int i = 0; i < n; i++)
	{
		if (ptr_array[i] == element)
		{
			element1 = i + 1;
		}
	}
	return element1;
}