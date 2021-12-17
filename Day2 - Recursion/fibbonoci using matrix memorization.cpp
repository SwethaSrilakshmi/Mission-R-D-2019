#include<stdio.h>
#include<stdlib.h>
void multiply(int A[][2])
{
	int a, b, c, d;
	a = A[0][0] * A[0][0] + A[0][1] * A[1][0];
	b = A[0][0] * A[0][1] + A[0][1] * A[1][1];
	c = A[1][0] * A[0][0] + A[1][1] * A[1][0];
	d = A[1][0] * A[0][1] + A[1][1] * A[1][1];
	A[0][0] = a;
	A[0][1] = b;
	A[1][0] = c;
	A[1][1] = d;
}
void  clacApowN(int A[][2], int n)
{
	if (n == 1)
	{
		A[0][0] = 0;
		A[0][1] = 1;
		A[1][0] = 1;
		A[1][1] = 1;
	}
	else
	{
		clacApowN(A, n / 2);
		multiply(A);
		if (n % 2 != 0)
		{
			int B[2][2];
			clacApowN(B, 1);
			int a, b, c, d;
			a = A[0][0] * B[0][0] + A[0][1] * B[1][0];
			b = A[0][0] * B[0][1] + A[0][1] * B[1][1];
			c = A[1][0] * B[0][0] + A[1][1] * B[1][0];
			d = A[1][0] * B[0][1] + A[1][1] * B[1][1];
			A[0][0] = a;
			A[0][1] = b;
			A[1][0] = c;
			A[1][1] = d;
		}
	}
}
void fibba(int A[][2], int n)
{
	clacApowN(A, n);

}
int main()
{
	int A[2][2];
	fibba(A, 11);
	printf("%d ", A[0][1]);
	system("pause");
}