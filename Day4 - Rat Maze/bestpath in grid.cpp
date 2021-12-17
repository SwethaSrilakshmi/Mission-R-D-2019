#include<stdio.h>
#include<stdlib.h>
int pathExists(int i, int j, int mat[][10], int visited[][10],int n,int m,int x,int y,int result[][10],int steps)
{
	static int len=999999;
	if (i == x - 1 && j == y - 1)
	{
		visited[i][j] = 1;
		if (len >steps)
		{
			len = steps;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					result[i][j] = visited[i][j];
				}
				
			}
		}
		visited[i][j] = 0;
		
		return 1;

	}
	if (i < 0 || j < 0 || i >= n || j >= m || mat[i][j] == 1 || visited[i][j] == 1)
	{
		return 0;
	}
	visited[i][j] = 1;
	int a = pathExists(i, j + 1, mat, visited, n, m, x, y,result,steps+1);
	
	int b = pathExists(i, j - 1, mat, visited, n, m, x, y,result,steps+1 );
	int c = pathExists(i + 1, j, mat, visited, n, m, x, y, result, steps + 1);
	int d = pathExists(i - 1, j, mat, visited, n, m, x, y, result, steps + 1);
	visited[i][j] = 0;
	return (a || b || c || d);
}
int main()
{
	int m, n;
	int mat[10][10];
	int visited[10][10];
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &mat[i][j]);
			visited[i][j] = 0;
		}
	}
	int x, y;
	scanf("%d%d", &x, &y);
	int result[][10] = { 0 };
	int value=pathExists(0, 0, mat, visited, n, m, x, y, result,0);
	if (value == 1)
	{
		printf("the shortest path is\n");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				printf("%d ", result[i][j]);

			}
			printf("\n");
		}
	}
	else
	{
		printf("path doesnot exist");
	}
	system("pause");
	return 0;
}