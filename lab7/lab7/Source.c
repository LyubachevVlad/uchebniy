#include<locale.h>
#include<stdio.h>
#include<math.h>
void main()
{
	setlocale(LC_ALL, "RUS");
    float a, b;
    char c, t;
    printf("������� ����� ��� �����: ");
    scanf("%c", &t);
    switch ((t >= 'a' && t <= 'z') || (t >= 'A' && t <= 'Z'))
    {
    case 1:
        printf("������� �����.\n");
        puts("������� �����, ��������, �����");
    }
    switch (t >= '1' && t <= '9')
    {
    case 1:
        printf("������� �����.\n");
        puts("������� �����, ��������, �����");
    }
    scanf("%f %c %f", &a, &c, &b);
    switch (c)
    {

    case '+':
        printf("%g", a + b);
        break;

    case '-':
        printf("%g", a - b);
        break;

    case '*':
        printf("%g", a * b);
        break;
    case '/':
        printf("%g", a /b);
        break;
    case '$':
        printf("%g", pow(a, b));
        break;
    }
}