#include<stdio.h>
#include<stdlib.h>
void perm(int a[], int pos,int v[], int len, int res[])
{
	if (pos == len)
	{
		for (int i = 0; i < len; i++)
		{
			printf("%d", res[i]);
		}
		printf("\n");
		
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			if (v[i] == 0&&((a[i]==a[i-1]&&v[i-1]==1)||a[i-1]!=a[i]))
			{
				v[i] = 1;
				res[pos] = a[i];
				perm(a, pos + 1, v, len, res);
				v[i] = 0;
			}
		}
	}
}

int main()
{
	int a[] = {1,1,2,2,3,3,3 };
	int v[7] = { 0 }, r[7];
	perm(a, 0, v, 7, r);
	system("pause");
}
