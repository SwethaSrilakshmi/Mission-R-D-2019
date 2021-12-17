#include<stdio.h>
#include<stdlib.h>
long long int sum(int n, int a[])
{
	if (n < 0)
		return 0;

	return a[n] + sum(n - 1, a);
}
int pow(int a, int n)
{
	if (n == 0)
		return 1;
	return (a % 1000000007 * pow(a, n - 1) % 1000000007) % 1000000007;
}

int main()
{
	int a[4] = { 1, 2, 3, 45 };
	printf("%d\n", sum(4, a));
	printf("%d\n", pow(10,2));
	
	system("pause");
}