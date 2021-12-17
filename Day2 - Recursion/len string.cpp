#include<stdio.h>
#include<stdlib.h>
void num(int len,int n,int a[])
{
	char result[] = { '0', '1', '2', 'E', 'h', '5', '9', 'L', '8', '6' };
	if (len == 0)
	{
		int i;
		for (i = n - 1; i >=0&&a[i]==0; i--)
		{
			
		}
		if (i == -1)
			printf("0");
		else
		{
			for (; i >= 0; i--)
			{
				printf("%c", result[a[i]]);
			}
			
		}
		printf("\n");
	}
	else
	{
		for (int i = 0; i <= 9; i++)
		{
			a[len - 1] = i;
			num(len - 1,n,a);
		}
	}
}
int main()
{
	int a[4];
	num(4, 4, a);
	system("pause");
}