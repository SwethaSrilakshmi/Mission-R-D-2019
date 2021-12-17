#include<stdio.h>
#include<stdlib.h>
int isAnagram(int frequency1[], int frequency2[])
{
	for (int i = 0; i < 26; i++)
	{
		if (frequency1[i] != frequency2[i])
		{
			return 0;
		}
		
	}
	return 1;
}
void createFrequency(int frequency[], char *string)
{
	int i = 0;
	while (string[i] != '\0')
	{
		if (string[i] >= 'a'&&string[i] <= 'z')
		{
			frequency[string[i] - 'a']++;
		}
		else
		{
			frequency[string[i] - 'A']++;
		}
		i++;
	}
}
int main()
{
	char filename[10];
	printf("enter filename :");
	scanf("%s", filename);
	char word[100];
	printf("enter word for anagrams :");
	scanf("%s", word);
	int frequency1[26] = { 0 };
	createFrequency(frequency1, word);
	FILE *fstream = fopen(filename, "r+");
	if (fstream == NULL)
	{
		printf("file not found");
	}
	else
	{
		char string[100];
		
		while (fscanf(fstream, "%s", string) != -1)
		{
			int freq[26] = { 0 };
			createFrequency(freq, string);
			if(isAnagram(freq, frequency1))
				printf("%s\n", string);

		}
	}
	system("pause");
	return 0;
}