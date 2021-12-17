#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void encodeRunLength(char * str)
{
	int i = 1, j = 0;
	int count = 1;

	while (str[i] != '\0')
	{
		if (str[i] == str[i - 1])
			count++;
		else if (count>1)
		{
			str[j++] = str[i-1];
			int k = log10(count)+1;
			int l = k;
		
			
				while (count > 0)
				{
					str[j + k - 1] = (count % 10) + '0';
					k--;
					count /= 10;
				}
				j += l;
				count = 1;
			
		}
		else
		{
			str[j++] = str[i-1];
		}
		i++;
	}
	if (count > 1)
	{
		str[j++] = str[i-1];
		int k = log10(count) + 1;
		int l = k;
		while (count > 0)
		{
			str[j + k - 1] = (count % 10) + '0';
			k--;
			count /= 10;
		}
		j += l;
		
	}
	else
	{
		str[j++] = str[i-1];
	}
	str[j] = '\0';

}
int  calculateLength(char *str)
{
	int i = 0,sum=0,count=0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0'&&str[i] <= '9')

		{

			count *= 10;
			count += (str[i] - '0');
			i++;
			continue;
		}
		
		else
		{
			if (count != 0)
			{
				sum += count;
				count = 0;
				sum--;
			}
			
		}
		sum++;
		i++;
		
		
	}
	if (count != 0)
	{
		sum += count;
		count = 0;
		sum--;
	}
	return sum; 
}
void decodeRunLength(char *str)
{
	int len = calculateLength(str);
	str[len--] = '\0';
	int i = 0;
	while (str[i] != '\0')
		i++;
	int j = i - 1;
	int sum = 0, count = 1;
	while (j >= 0)
	{
		if (str[j] >= '0'&&str[j] <= '9')
		{
			sum += (count*(str[j] - '0'));
			count *= 10;
		}
		else
		{
			count = 1;
			if (sum == 0)
				str[len--] = str[j];
			while (sum > 0)
			{
				str[len--] = str[j];
				sum--;
			}
		}
		j--;
	}
	



}
int main()
{
	int n;
	char str[1000];
	
	printf("enter string :");
	scanf("%s", &str);
	
	encodeRunLength(str);
	
	printf("the encoded string :%s\n", str);
	decodeRunLength(str);
	printf("the decoded string :%s\n", str);
	
	return 0;
}