#include<stdio.h>
#include<locale.h>
void triangle(int h)
{
	for (int i = 0; i < h; i++, printf("\n"))
	{
		for (int j = (h - i) - 1; j > 0; j--)
		{
			printf(" ");
		}
		for (int j = (i * 2) + 1; j > 0; j--)
		{
			printf("*");
		}
	}
}
float plosh(int h)
{
	float a,s;
	a = h * 2 - 1;
	s = 0.5 * a * h;
	return s;
}
void name()
{
	printf("�������������� ����������� � �����������, � ������� ��� ������� ����� ����� ����� �� �����. �������� ���������� ������ �������, � ��������� �������� �� ������� � ����������. �� �����������, ������ ���������� ����������� ����� �������� ��������������, �� �������� ����������� �������.");
}
void main()
{
	setlocale(LC_ALL, "RUS");
	int h,i,j;
	
	puts("������ ������������");
	scanf("%d", &h);
	
	while (1)
	{   
		int c;
		printf("1-���������� ������,2-�������� ������� ������,3-������� ����������� ���� ������,4-�����\n");
	    scanf("%d", &c);
		switch (c)
		{
		 case 1:
			triangle(h);
			break;
		 case 2:
			printf("S=%f", plosh(h));
			break;
		 case 3:
			name();
			break;
		}
		if (c == 4) break;
	}
}