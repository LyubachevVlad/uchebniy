#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#include<io.h>
void main()
{
	setlocale(LC_ALL, "RUS");
	float sum = 0, a;
	int n = 0, razn = 0, k;
	char c;
	FILE* f;
	FILE* tf;
	f = fopen("numder.txt", "r");
	while (!feof(f))
	{
		fscanf(f, "%f\n", &a);
		sum += a;
		n++;
	}
	fclose(f);
	printf("Среднее арифметическое=%f", sum / n);
	FILE* t;
	char name[25] = "1000.txt";
	t = fopen("1000.txt", "wt");
	srand(time(NULL));
	puts("\nСоздание файла");
	if ((t = fopen(name, "wt")) == NULL)
	{
		printf("Ошибка отрытия файла для записи");
		return 0;
	}
	for (int i = 0; i < 25; i++)
	{
		int x = 1 + rand() % 100;
		fprintf(t, "%d\n", x);
	}
	fclose(t);
	t = fopen("1000.txt", "r");
	char name2[20] = "1000-7.txt";
	tf = fopen("1000-7.txt", "w");
	while (!feof(t))
	{
		fscanf(t, "%d\n", &k);
		razn = 1000-k;
		fprintf(tf, "%d\n", razn);
	}
	fclose(t);
	fclose(tf);

	FILE* win;
	char wname[50] = "win.txt";
	char w[150];
	win = fopen("win.txt", "r");
	puts("\nОткрытие файла");
	while (!feof(win)) 
	{
		if (fgets(w, sizeof(w), win) != NULL) 
		{
			char* p = strtok(w, " ");
			while (p != NULL)
			{
				printf("%s", p);
				p = strtok(NULL, " ");
			}
		}
	}
	fclose(win);
}
