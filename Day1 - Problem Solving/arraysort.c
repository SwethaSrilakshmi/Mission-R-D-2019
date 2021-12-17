#include<stdio.h>
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;

}

void sort(int a[], int n)
{
	int start = 0, end = n - 1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0)
		{
			while (a[start] == 0)
			{
				start++;
			}
			if (i>start)
				swap(&a[start], &a[i]);
		}
		else if (a[i] == 2)
		{
			while (a[end] == 2)
			{
				end--;
			}
			if (i<end)
			{
				if ((a[end] == 0)&&(i!=start))
				{
					
					swap(&a[end], &a[start++]);
				}
				  swap(&a[end], &a[i]);
			}
		}
		

	}
}
int main()
{
	int n;
	printf("enter the n :");
	scanf("%d",&n);
	int a[n];
	printf("enter the %d values :",n);
	for (int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	sort(a,n);
	for(int i=0;i<n;i++)
		printf("%d ", a[i]);
	
	return 0;
}
