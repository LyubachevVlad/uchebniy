#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
int* randomarray(int* ptr_array, int size)
{
	for (int i = 0; i < size; i++)
	{
		ptr_array[i] = 1 * (50 - 0) * rand() / RAND_MAX;
	}
	for (int i = 0; i < size; i++)
	{
		printf("\narray[%d]=%d", i, ptr_array[i]);
	}
	return ptr_array;
}
int* maximum(int* array1, int* array2, int* array3, int size4, int* array4,int size1,int size2,int size3)
{
	int k1 = 0, k2 = 0, k3 = 0;
	for (int i = 0; i < size4; i++)
	{
		if ((array2[k2] < array1[k1]) && (array3[k3] < array1[k1]))
		{
			array4[i] = array1[k1];
		}
		else
			if ((array1[k1] < array2[k2]) && (array3[k3] < array2[k2]))
			{
				array4[i] = array2[k2];
			}
			else
				if ((array1[k1] < array3[k3]) && (array2[k2] < array3[k3]))
				{
					array4[i] = array3[k3];
				}
		k1++;
		k2++;
		k3++;
		if (k1 > size1) k1 = -1;
		if (k2 > size2) k2 = -1;
		if (k3 > size3) k3 = -1;
	}
	return array4;
}
void main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	int size1 = 10 + rand() % 20 - 10;
	int size2 = 10 + rand() % 20 - 10;
	int size3 = 10 + rand() % 20 - 10;
	int size4 = 0;
	if (((size1 > size2) && (size1 > size3)) || ((size1==size2) || (size1==size3)))
	{
		 size4 = size1;
	}
	else
		if (((size2>size1)&&(size2>size3)) || ((size2 == size1) || (size2 == size3)))
		{
			 size4 = size2;
		}
		else
			if (((size3 > size1) && (size3 > size2)) || ((size3 == size1) || (size3 == size2)))
			{
				 size4 = size3;
			}
	int* array1 = (int*)malloc(size1 * sizeof(int));
	int* array2 = (int*)malloc(size2 * sizeof(int));
	int* array3 = (int*)malloc(size3 * sizeof(int));
	int* array4 = (int*)malloc(size4 * sizeof(int));
	randomarray(array1, size1);
	puts("");
	randomarray(array2, size2);
	puts("");
	randomarray(array3, size3);
	puts("");
	maximum(array1, array2, array3, size4, array4, size1, size2, size3);
	for (int i = 0; i < size4; i++)
	{
		printf("%d ", array4[i]);
	}
}