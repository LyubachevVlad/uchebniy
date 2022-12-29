#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
struct worker 
{
	char surname[25];
	char name[25];
	char patronymic[25];
	char salary[25];
};
typedef struct worker Workers;
Workers* inputa(Workers* arr, int size) 
{
	for (int i = 0; i < size; i++) {
		printf("\n�������� %d\n", i + 1);
		printf("������� �������: ");
		scanf("%s", &arr[i].surname);
		printf("������� ���: ");
		scanf("%s", &arr[i].name);
		printf("������� ��������: ");
		scanf("%s", &arr[i].patronymic);
		printf("������� ��������: ");
		scanf("%s", &arr[i].salary);
	}
	return arr;
}

int printa(Workers* arr, int size) 
{
	for (int i = 0; i < size; i++) {
		printf("\n�������� %d\n", i + 1);
		printf(" �������: %s\n", arr[i].surname);
		printf(" ���: %s\n", arr[i].name);
		printf(" ��������: %s\n", arr[i].patronymic);
		printf(" ��������: %s\n", arr[i].salary);
	}
	return 0;
}

int printonea(Workers arr, int number) 
{
	printf("\n�������� %d\n", number);
	printf(" �������: %s\n", arr.surname);
	printf(" ���: %s\n", arr.name);
	printf(" ��������: %s\n", arr.patronymic);
	printf(" ��������: %s\n", arr.salary);
	return 0;
}

int compare_salary(const void* av, const void* bv) 
{
	const Workers* a = av, * b = bv;
	if (a->salary < b->salary) return -1;
	if (a->salary > b->salary) return 1;
	return 0;
}

int lworkers(Workers* workersforfile) 
{
	char string[256];
	int counter = 0;
	int counter1 = 0;
	FILE* file;
	file = fopen("workers.txt", "rt");
	while (!feof(file)) {
		counter++;
		fgets(string, sizeof(string), file);
		char* mini_str = strtok(string, " ");
		while (mini_str != NULL)
		{
			if (counter1 == 1) 
			{
				strcpy(workersforfile[counter - 1].surname, mini_str);
				mini_str = strtok(NULL, " ");
			}
			else if (counter1 == 2) 
			{
				strcpy(workersforfile[counter - 1].name, mini_str);
				mini_str = strtok(NULL, " ");
			}
			else if (counter1 == 3) 
			{
				strcpy(workersforfile[counter - 1].patronymic, mini_str);
				mini_str = strtok(NULL, " ");
			}
			else if (counter1 == 4) 
			{
				strcpy(workersforfile[counter - 1].salary, mini_str);
				mini_str = strtok(NULL, " ");
			}
			else 
			{
				counter1 = 0;
			}
			counter1++;
		}
	}
	return 0;
}

Workers* changeElement(Workers* arr, int elementID) 
{
	char surname[25], name[25], patronymic[25], salary[25];
	printf("\n�������� %d", elementID);
	printf("\n������� ����� �������: ");
	scanf("%s", surname);
	strcpy(arr[elementID - 1].surname, surname);
	printf("������� ����� ���: ");
	scanf("%s", name);
	strcpy(arr[elementID - 1].name, name);
	printf("������� ����� ��������: ");
	scanf("%s", patronymic);
	strcpy(arr[elementID - 1].patronymic, patronymic);
	printf("������� ����� ��������: ");
	scanf("%s", salary);
	strcpy(arr[elementID - 1].salary, salary);
	return arr;
}

int finder(Workers* arr, int num, char word[25], int size) 
{

	for (int i = 0; i < size; i++) 
	{
		switch (num) 
		{
		case 1:
			if (strcmp(arr[i].surname, word) == 0) 
			{
				printf("\n�������� %d\n", i + 1);
				printf(" �������: %s\n", arr[i].surname);
				printf(" ���: %s\n", arr[i].name);
				printf(" ��������: %s\n", arr[i].patronymic);
				printf(" ��������: %s\n", arr[i].salary);
			}
			break;
		case 2:
			if (strcmp(arr[i].name, word) == 0) 
			{
				printf("\n�������� %d\n", i + 1);
				printf(" �������: %s\n", arr[i].surname);
				printf(" ���: %s\n", arr[i].name);
				printf(" ��������: %s\n", arr[i].patronymic);
				printf(" ��������: %s\n", arr[i].salary);
			}
			break;
		case 3:
			if (strcmp(arr[i].patronymic, word) == 0) 
			{
				printf("\n�������� %d\n", i + 1);
				printf(" �������: %s\n", arr[i].surname);
				printf(" ���: %s\n", arr[i].name);
				printf(" ��������: %s\n", arr[i].patronymic);
				printf(" ��������: %s\n", arr[i].salary);
			}
			break;
		case 4:
			if (strcmp(arr[i].salary, word) == 0) 
			{
				printf("\n��������% d\n", i + 1);
				printf(" �������: %s\n", arr[i].surname);
				printf(" ���: %s\n", arr[i].name);
				printf(" ��������: %s\n", arr[i].patronymic);
				printf(" ��������: %s\n", arr[i].salary);
			}
			break;
		default:
			printf("������ �� �������");
		}
	}
	return 0;
}

int otb(Workers* arr, int num, char word[25], int wsize) 
{
	Workers temp_arr[2];
	int counter = 0;
	for (int i = 0; i < wsize; i++) 
	{
		strcpy(temp_arr[i].surname, arr[i].surname);
		strcpy(temp_arr[i].name, arr[i].name);
		strcpy(temp_arr[i].patronymic, arr[i].patronymic);
		strcpy(temp_arr[i].salary, arr[i].salary);
	}
	for (int i = 0; i < wsize; i++) 
	{
		switch (num) 
		{
		case 1:
			if (strcmp(temp_arr[i].surname, word) == 0)
			{
				strcpy(arr[counter].surname, temp_arr[i].surname);
				strcpy(arr[counter].name, temp_arr[i].name);
				strcpy(arr[counter].patronymic, temp_arr[i].patronymic);
				strcpy(arr[counter].salary, temp_arr[i].salary);
				counter++;
			}
			break;
		case 2:
			if (strcmp(temp_arr[i].name, word) == 0) 
			{
				strcpy(arr[counter].surname, temp_arr[i].surname);
				strcpy(arr[counter].name, temp_arr[i].name);
				strcpy(arr[counter].patronymic, temp_arr[i].patronymic);
				strcpy(arr[counter].salary, temp_arr[i].salary);
				counter++;
			}
			break;
		case 3:
			if (strcmp(temp_arr[i].patronymic, word) == 0) 
			{
				strcpy(arr[counter].surname, temp_arr[i].surname);
				strcpy(arr[counter].name, temp_arr[i].name);
				strcpy(arr[counter].patronymic, temp_arr[i].patronymic);
				strcpy(arr[counter].salary, temp_arr[i].salary);
				counter++;
			}
			break;
		case 4:
			if (strcmp(temp_arr[i].salary, word) == 0) 
			{
				strcpy(arr[counter].surname, temp_arr[i].surname);
				strcpy(arr[counter].name, temp_arr[i].name);
				strcpy(arr[counter].patronymic, temp_arr[i].patronymic);
				strcpy(arr[counter].salary, temp_arr[i].salary);
				counter++;
			}
			break;
		}
	}
	FILE* cou;
	if ((cou = fopen("Counter.txt", "wt")) == NULL)
	{
		printf("������ �������� ����� ��� ������");
		return 0;
	}
	fprintf(cou, "%d", counter);
	fclose(cou);
}

int write(Workers* arr, int workers_aff_size)
{
	FILE* out;
	if ((out = fopen("NewFile.txt", "wt")) == NULL) 
	{
		printf("������ �������� ����� ��� ������");
		return 0;
	}
	for (int i = 0; i < workers_aff_size; i++) 
	{
		fprintf(out, "%s %s %s %s\n", arr[i].surname, arr[i].name, arr[i].patronymic, arr[i].salary);
	}
	return 0;
}

int main() 
{
	setlocale(LC_ALL, "RUS");
	Workers workers_array[20];
	int array_size;
	int number,count;
	int elementID;
	printf("������� ���������� ����������: ");
	scanf("%d", &array_size);
	inputa(workers_array, array_size);
	printa(workers_array, array_size);
	printf("\n������� ������ ��������� �������: ");
	scanf("%d", &number);
	printonea(workers_array[number - 1], number);
	puts("|--------------------------|");
	qsort(workers_array, 4, sizeof(Workers), compare_salary);
	printa(workers_array, array_size);
	puts("|--------------------------|");
	Workers workersforfile[20];
	int workers_aff_size = 2;
	lworkers(workersforfile);
	printa(workersforfile, workers_aff_size);
	puts("|--------------------------|");
	printf("\n������� ����� �������� ������� ��� ���������: ");
	scanf("%d", &elementID);
	changeElement(workersforfile, elementID);
	printa(workersforfile, workers_aff_size);
	puts("|--------------------------|");
	int search_number;
	char search_word[25];
	printf("\n������� ����� ����, �� �������� ����� ������ ��������(1 - �������; 2 - ���; 3 - ��������; 4 - �/�): ");
	scanf("%d", &search_number);
	printf("\n������� ��������, �� �������� ����� ����� ���������: ");
	scanf("%s", &search_word);
	finder(workersforfile, search_number, search_word, workers_aff_size);
	puts("|--------------------------|");
	otb(workers_array, search_number, search_word, workers_aff_size);
	FILE* cou1;
	if ((cou1 = fopen("Counter.txt", "rt")) == NULL)
	{
		printf("������ �������� ����� ��� ������");
		return 0;
	}
	fscanf(cou1, "%d", &count);
	fclose(cou1);
	printa(workers_array, count);
	puts("|--------------------------|");
	write(workersforfile, workers_aff_size);
	return 0;
}