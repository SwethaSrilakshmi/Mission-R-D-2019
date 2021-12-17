#include<stdio.h>
#include<stdlib.h>
#define X 10000001
#define SIZE(x) (x/32)+!!(x%32)
#define SETBIT(a,pos) (a[(pos/32)]|=(1<<(pos%32)))
#define CLEARBIT(a,pos) (a[(pos/32)]&=~(1<<(pos%32)))
#define GETBIT(a,pos) (a[(pos/32)]&(1<<(pos%32)))
int main()
{
	int *a = (int*)malloc(sizeof(int)*SIZE(X));
	for (int i = 0; i < SIZE(X); i++)
	{
		a[i] = 0;
	}
	char filename[100];
	scanf("%s[^\n]", filename);
	FILE *fstream = fopen(filename, "r+");
	int value;
	int res = fscanf(fstream, "%d", &value);
	while (res != -1)
	{
		SETBIT(a, value);
		res = fscanf(fstream, "%d", &value);
	}
	fclose(fstream);
	fstream = fopen("out.txt", "w+");
	for (int i = 1; i < X; i++)
	{
		if (GETBIT(a, i))
		{
			fprintf( fstream,"%d\n", i);
		}
	}
	fclose(fstream);
	system("pause");
	
}