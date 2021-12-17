#include<stdio.h>
#include<stdlib.h>
int pathExists(int i, int j, int mat[][10], int visited[][10], int n, int m, int x, int y)
{
	static int len = 999999;
	if (i == x - 1 && j == y - 1)
	{
		visited[i][j] = 1;
		
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					printf("%d ", visited[i][j]);
				}
				printf("\n");

			}
		
		
		visited[i][j] = 0;

		return 1;

	}
	if (i < 0 || j < 0 || i >= n || j >= m || mat[i][j] == 1 || visited[i][j] == 1)
	{
		return 0;
	}
	visited[i][j] = 1;
	return(pathExists(i, j + 1, mat, visited, n, m, x, y) || pathExists(i, j - 1, mat, visited, n, m, x, y) || pathExists(i + 1, j, mat, visited, n, m, x, y) || pathExists(i - 1, j, mat, visited, n, m, x, y));
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
	int value=pathExists(0, 0, mat, visited, n, m, x, y);
	if (value == 1)
	{
		
	}
	else
	{
		printf("path doesnot exist");
	}
	system("pause");
	return 0;
}