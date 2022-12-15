#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
double* mas(int size, double* ptr_array);
double sum(int size, double* ptr_array);
double* delete(double* ptr_array, int size,double sr);
double sredn(double* ptr_array, int size);
double* mas2(int size2, double* ptr_array2);
double* insert(double* ptr_array2, int* size2, int index, int num);
int* pmin(double* ptr_array2, int* size2,double el);
void main()
{
	setlocale(LC_ALL, "RUS");
	double* ptr_array;
	double* ptr_array2;
	int size, k,size2;
	double sr=0;
	double num = -999;
	srand(time(NULL));
	printf("¬ведите размер массива: ");
	scanf("%d", &size);
	ptr_array = (double*)malloc(size * sizeof(double));
	if (ptr_array == NULL)
	{
		puts("error");
		return -1;
	}
	mas(size, ptr_array);
	sum(size, ptr_array);
	printf("\n\n\n");
	double sredn(double* ptr_array, int size);
	delete(ptr_array, size,sr);
	printf("\n\n\n");
	srand(time(NULL));
	printf("¬ведите размер массива: ");
	scanf("%d", &size2);
	ptr_array2 = (double*)malloc(size2 * sizeof(double));
	if (ptr_array2 == NULL)
	{
		puts("error");
		return -1;
	}
     mas2(size2, ptr_array2);
	 int i = 0;
	 double min = ptr_array2[i];
	 for (int i = 0;i < size2;i++)
	 {
		 if (ptr_array2[i] < min)
		 {
			 min = ptr_array2[i];
		 }
	 }
	 printf("\n");
	 ptr_array2=insert( ptr_array2, &size2, pmin(ptr_array2, size2,min), -999);
	 for (int i = 0; i < size2 ; i++)
	 {
		 printf("\nptr_array2[%d] = %lf", i, ptr_array2[i]);
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
	printf("  —реднеезанчение на промежутке=%lf", sr2);
}
double sredn(double* ptr_array, int size)
{
	double k = 0,sr=0;
	for (int i = 0;i < size;i++)
	{
		k += ptr_array[i];
	}
	sr = k / size;
	return sr;
}
double* delete(double* ptr_array, int size,double sr) 
{
	for (int i = 0;i < size;i++)
	{
		if (ptr_array[i] < sr)
		{
			for (int j = i;j < size;j++)
				ptr_array[j] = ptr_array[j + 1];
				size--;
			}
		}
		for (int i = 0;i < size;i++)
		{
			printf("\nptr_array[%d] = %lf", i, ptr_array[i]);
		}
	return ptr_array;
} 
double* mas2(int size2, double* ptr_array2)
{
	for (int i = 0; i < size2; i++)
	{
		ptr_array2[i] = -100 + 1.f * (100 - (-100)) * rand() / RAND_MAX;
	}
	for (int i = 0; i < size2; i++)
	{
		printf("\nptr_array2[%d] = %lf", i, ptr_array2[i]);
	}
	return ptr_array2;
}
double* insert(double* ptr_array2, int* size2, int index, int num)
{
		int size_n = (*size2) + 1;
		if (ptr_array2 == NULL) return NULL;
		double*ptr_array_n = (double*)realloc(ptr_array2, size_n * sizeof(double));
		if (ptr_array_n == NULL) return ptr_array2;
		ptr_array2 = ptr_array_n;
		for (int i = size_n - 1; i > index;i--)
			ptr_array2[i] = ptr_array2[i - 1];
		ptr_array2[index] = num;
		*size2 = size_n;
		return ptr_array2;
}
int* pmin(double* ptr_array2, int* size2,double el)
{
	int pos = -1;
	for (int i = 0;i < size2;i++)
	{
		if (ptr_array2[i] == el)
		{
			pos = i;
		}
	}
	return pos;
}
