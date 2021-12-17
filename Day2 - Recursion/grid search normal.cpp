#include<stdio.h>
#include<stdlib.h>
int searchLeft(int i, int j, char **puzzle, char *string, int strlen)
{
	if (j - strlen + 1 >= 0)
	{
		int l = 0;
		for (l = 0; l < strlen; l++)
		{
			if (puzzle[i][j] == string[l])
			{
				j--;
			}
			else
			{
				return 0;
			}
		}
		if (string[l] = '\0')
		{
			return 1;
		}
	}
	return 0;
}
int searchRight(int i, int j, char **puzzle, char *string, int strlen, int m)
{
	if (j + strlen - 1 <= m)
	{
		int l = 0;
		for (l = 0; l < strlen; l++)
		{
			if (puzzle[i][j] == string[l])
			{
				j++;
			}
			else
			{
				return 0;
			}
		}
		if (string[l] == '\0')
		{
			return 1;
		}
	}
	return 0;
}
int searchTop(int i, int j, char **puzzle, char *string, int strlen)
{
	if (i - strlen + 1 >= 0)
	{
		int l = 0;
		for (l = 0; l < strlen; l++)
		{
			if (puzzle[i][j] == string[l])
			{
				i--;
			}
			else
			{
				return 0;
			}
		}
		if (string[l] == '\0')
		{
			return 1;
		}
	}
	return 0;
}
int searchBottom(int i, int j, char **puzzle, char *string, int strlen, int n)
{
	if (i + strlen - 1 <= n)
	{
		int l = 0;
		for (l = 0; l < strlen; l++)
		{
			if (puzzle[i][j] == string[l])
			{
				i++;
			}
			else
			{
				return 0;
			}
		}
		if (string[l] == '\0')
		{
			return 1;
		}
	}
	return 0;
}
int searchLTD(int i, int j, char **puzzle, char *string, int strlen)
{
	if (i - strlen + 1 >= 0 && j - strlen + 1 >= 0)
	{
		int l = 0;
		for (l = 0; l < strlen; l++)
		{
			if (puzzle[i][j] == string[l])
			{
				i--;
				j--;
			}
			else
			{
				return 0;
			}
		}
		if (string[l] == '\0')
		{
			return 1;
		}
	}
	return 0;
}
int searchRTD(int i, int j, char **puzzle, char *string, int strlen, int m)
{
	if (i - strlen + 1 >= 0 && j + strlen - 1 <= m)
	{
		int l = 0;
		for (l = 0; l < strlen; l++)
		{
			if (puzzle[i][j] == string[l])
			{
				i--;
				j++;
			}
			else
			{
				return 0;
			}
		}
		if (string[l] == '\0')
		{
			return 1;
		}
	}
	return 0;
}
int searchLBD(int i, int j, char **puzzle, char *string, int strlen, int n)
{
	if (j - strlen + 1 >= 0 && i + strlen - 1 <= n)
	{
		int l = 0;
		for (l = 0; l < strlen; l++)
		{
			if (puzzle[i][j] == string[l])
			{
				i++;
				j--;
			}
			else
			{
				return 0;
			}
		}
		if (string[l] == '\0')
		{
			return 1;
		}
	}
	return 0;
}
int searchRBD(int i, int j, char **puzzle, char *string, int strlen, int n, int m)
{
	if (j + strlen - 1 <= m&&i + strlen - 1 <= n)
	{
		int l = 0;
		for (l = 0; l < strlen; l++)
		{
			if (puzzle[i][j] == string[l])
			{
				i++;
				j++;
			}
			else
			{
				return 0;
			}
		}
		if (string[l] == '\0')
		{
			return 1;
		}
	}
	return 0;
}
void occurence(char **puzzle, char *string, int strlen, int n, int m)
{
	int c = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (puzzle[i][j] == string[0])
			{
				if (searchLeft(i, j, puzzle, string, strlen))
				{
					c++;
					printf("{[%d][%d] to [%d][%d]}\n", i, j, i, j - strlen + 1);
				}
				if (searchRight(i, j, puzzle, string, strlen, m))
				{
					c++;
					printf("{[%d][%d] to [%d][%d]}\n", i, j, i, j + strlen - 1);
				}
				if (searchTop(i, j, puzzle, string, strlen))
				{
					c++;
					printf("{[%d][%d] to [%d][%d]}\n", i, j, i - strlen + 1, j);
				}
				if (searchBottom(i, j, puzzle, string, strlen, n))
				{
					c++;
					printf("{[%d][%d] to [%d][%d]}\n", i, j, i + strlen - 1, j);
				}
				if (searchLTD(i, j, puzzle, string, strlen))
				{
					c++;
					printf("{[%d][%d] to [%d][%d]}\n", i, j, i - strlen + 1, j - strlen + 1);
				}
				if (searchRTD(i, j, puzzle, string, strlen, m))
				{
					c++;
					printf("{[%d][%d] to [%d][%d]}\n", i, j, i - strlen + 1, j + strlen - 1);
				}
				if (searchLBD(i, j, puzzle, string, strlen, n))
				{
					c++;
					printf("{[%d][%d] to [%d][%d]}\n", i, j, i + strlen - 1, j - strlen + 1);
				}
				if (searchRBD(i, j, puzzle, string, strlen, m, n))
				{
					c++;
					printf("{[%d][%d] to [%d][%d]}\n", i, j, i + strlen - 1, j + strlen - 1);
				}
			}


		}
	}
	printf("the number of occurences  is %d", c);
}
int main()
{
	char *a[] = { "ramu", "aaus", "kmmu", "ramu" };
	char *string = "ramu";
	occurence(a, string, 4, 4, 4);
	system("pause");
}