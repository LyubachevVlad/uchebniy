#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
void main()
{
	setlocale(LC_ALL, "RUS");
	char s2[20], s1[20] = "Hello, ", k = "m", p[2] = " ";
	int sch = 0;
	printf("What is your name?\n");
	scanf("%s", &s2);
	strcat(s1, s2);
	printf("%s!!!\n", s1);
	for (int i = 0; i <= 4; i++)
	{
		putchar(toupper(s1[i]));
	}
	printf(", %s!!!", s2);
	for (int i = 0; i <= 40 - strlen(s1); i++)
	{
		putchar('!');
	}
	s1[8] = ' ';
	for (int i = 8; i <= strlen(s1); i++)
	{
		s1[i] = s1[i + 1];
	}
	printf("\n%s!!!\n", s1);
}
