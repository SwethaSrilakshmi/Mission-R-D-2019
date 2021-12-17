#include<stdio.h>
#include<stdlib.h>
int ways(int n, int k)
{
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	int way = 0;
	for (int i = 1; i <= k&&i <= k; i++)
	{
		way += ways(n - i, k);
	}
	return way;
}
int main()
{
	printf("%d", ways(3, 3));
	system("pause");
}