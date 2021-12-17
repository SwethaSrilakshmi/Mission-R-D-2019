#include<stdio.h>
#include<stdlib.h>
long fib(int n)
{
	if (n == 0)
		return 0;
	if (n == 2 || n == 1)
		return 1;
	return (fib(n - 1) + fib(n - 2));
}
int f[1000001] = { 0 };
long fibb(int n)
{
	if (n <= 0)
		return 0;
	if (n == 2 || n == 1)
		return 1;
	if (f[n] == 0)
	{
		f[n] = fibb(n) + fibb(n - 1);
	}
	return f[n];



}
int main()
{
	printf("%d\n", fib(10));
	printf("%d\n", fibb(10));

	
	system("pause");
}