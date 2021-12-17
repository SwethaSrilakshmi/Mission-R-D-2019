
#include<stdio.h>
#include<stdlib.h>
void get_occurences(char **a, char *string, int direction, int i, int j, int pos, int len,int n,int m)
  {
	if (pos == len)
	{
		if (direction==0)
		{
		
			printf("{[%d][%d] to [%d][%d]}\n",i,j+len+1,i,j+1);
			

		}
		if (direction==1)
		{
			
			printf("{[%d][%d] to [%d][%d]}\n", i, j-len, i, j-1);
		}
		if (direction == 2)
		{
			
			printf("{[%d][%d] to [%d][%d]}\n", i+len,j,i+1,j);
		}
		if (direction == 3)
		{
			
			printf("{[%d][%d] to [%d][%d]}\n", i-len, j, i-1, j);
		}
		if (direction == 4)
		{
		
			printf("{[%d][%d] to [%d][%d]}\n", i+len,j+len,i+1,j+1);
		}
		if (direction == 5)
		{
			
			printf("{[%d][%d] to [%d][%d]}\n", i+len,j-len,i+1,j-1);
		}
		if (direction == 6)
		{
			
			printf("{[%d][%d] to [%d][%d]}\n", i-len,j+len,i-1,j+1);
		}
		if (direction == 7)
		{
			
			printf("{[%d][%d] to [%d][%d]}\n",i-len,j-len,i-1,j-1);
		}
	}
	else
	{
		if (direction == 0||(direction==-1&&j-len+1>=0))
		{
			if (a[i][j] == string[pos])
				get_occurences(a, string, 0, i, j - 1, pos + 1, len,n,m);
		}

		
		if (direction == 1 || (direction == -1 && j +len - 1 < m))
		{
			if (a[i][j] == string[pos])
				get_occurences(a, string, 1, i, j +1, pos + 1, len,n,m);
		}
		if (direction == 2 || (direction == -1 && i-len+1>=0))
		{
			if (a[i][j] == string[pos])
				get_occurences(a, string, 2, i-1, j, pos + 1, len,n,m);
		}
		if (direction == 3 || (direction == -1 && i + len - 1 <n))
		{
			if (a[i][j] == string[pos])
				get_occurences(a, string, 3, i+1, j , pos + 1, len, n, m);
		}
		if (direction == 4 || (direction == -1 && j-len+1>=0&&i-len+1<=0))
		{
			if (a[i][j] == string[pos])
				get_occurences(a, string, 4, i-1, j - 1, pos + 1, len, n, m);
		}
		if (direction == 5 || (direction == -1 &&j+len-1<m&&i-len+1>=0))
		{
			if (a[i][j] == string[pos])
				get_occurences(a, string, 5, i-1, j+ 1, pos + 1, len, n, m);
		}
		if (direction == 6 || (direction == -1 && j-len+1<=0&&i+len-1<n))
		{
			if (a[i][j] == string[pos])
				get_occurences(a, string, 6, i+1, j - 1, pos + 1, len, n, m);
		}
		if (direction == 7 || (direction == -1 && i + len - 1 <n&&j+len-1<m))
		{
			if (a[i][j] == string[pos])
				get_occurences(a, string, 7, i+1, j + 1, pos + 1, len, n, m);
		}




	}


}
void occurences(char **a, char *string, int len, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			get_occurences(a, string, -1, i, j, 0, len, n, m);
		}
	}
}
int main()
{
	char *a[] = { "ramu", "aaus", "kmmu", "ramu" };
	char *string = "ramu";
	occurences(a, string, 4, 4, 4);
	
		
		system("pause");
}