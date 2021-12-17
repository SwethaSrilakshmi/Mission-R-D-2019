#include<stdio.h>
#include<stdlib.h>
#define MAX 16001
void merge(int a[], int low, int mid, int high)
{
	int *result = (int*)malloc(sizeof(int)*MAX);
	int j = mid + 1,i=low,k=0;
	while (i <= mid&&j <= high)
	{
		if (a[i] < a[j])
		{
			result[k++] = a[i++];
		}
		else
		{
			result[k++] = a[j++];
		}
	}
	while (i <= mid)
	{
		result[k++] = a[i++];
	}
	while (j <= high)
	{
		result[k++] = a[j++];
	}
	j = 0;
	for (int i = low; i <= high; i++)
	{
		a[i] = result[j++];
	}
	free(result);
}
void mergesort(int a[], int low, int high)
{
	if (low < high)
	{
		int mid = ((low + high) / 2);
		mergesort(a, low, mid);
		mergesort(a, mid+1, high);
		merge(a, low, mid, high);
	}
}
void filecopy()
{
	FILE *fptr2= fopen("b.txt", "w+");
	FILE *fptr1 = fopen("c.txt", "r+");
	int value;
	int res = fscanf(fptr1, "%d", &value);
	while (res != -1)
	{
		fprintf(fptr2, "%d\n", value);
		res = fscanf(fptr1, "%d", &value);
	}
	fclose(fptr1);
	fclose(fptr2);
}
void filemerge()
{
	FILE *fptr1 = fopen("a.txt", "r+");
	FILE *fptr2 = fopen("b.txt", "r+");
	FILE *fptr3 = fopen("c.txt", "w+");
	int a, b;
	int k=fscanf(fptr1, "%d", &a);
	int j=fscanf(fptr2, "%d", &b);
	while (k != -1 && (j != -1))
	{
		if (a < b)
		{
			fprintf(fptr3, "%d\n", a);
			k=fscanf(fptr1, "%d", &a);
		}
		else
		{
			fprintf(fptr3, "%d\n", b);
			j=fscanf(fptr2, "%d", &b);

		}
	}
	while (k != -1)
	{
		fprintf(fptr3, "%d\n", a);
		k=fscanf(fptr1, "%d", &a);
	}
	while (j != -1)
	{
		fprintf(fptr3, "%d\n", b);
		j=fscanf(fptr2, "%d", &b);
	}
	fclose(fptr1);
	fclose(fptr2);
	fclose(fptr3);

	filecopy();


}
int main()
{
	

	int a[MAX];
	printf("enter file  name to sort :");
	char filename[10];
	scanf("%s", filename);
	FILE *fptr = fopen(filename, "r+");
	FILE *fptr1 = fopen("a.txt", "w+");
	FILE *fptr2 = fopen("b.txt", "w+");
	FILE *fptr3 = fopen("c.txt", "w+");
	fclose(fptr1);
	fclose(fptr2);
	fclose(fptr3);

	

	if (fptr == NULL)
	{
		printf("file impossible to read");
	}
	else
	{

		int first = 1;
		int res, value;;
		res = fscanf(fptr, "%d", &value);
		while (res != -1)
		{


			int i = 0;
			for (i = 0; i < MAX && res != -1; i++)
			{


				a[i] = value;
				res = fscanf(fptr, "%d", &value);
			}
			mergesort(a, 0, i - 1);
			FILE *fptr1 = fopen("a.txt", "w+");
			for (int j = 0; j < i; j++)
			{
				fprintf(fptr1,"%d\n", a[j]);
			}

			fclose(fptr1);
			filemerge();
		}
		FILE *fptr1 = fopen("b.txt", "w+");
		fclose(fptr1);

		}
	
	system("pause");
	return 0;
}