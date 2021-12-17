
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
struct node
{
	int value;
	char string[100];
	char formula[100];
};
int strtoint(char *record)
{
	int i = 0;
	int sum = 0;
	while (record[i] != '\0')
	{
		sum *= 10;
		sum += record[i] - '0';
		i++;
	}
	return sum;
}
void strcopy(char a[], char *b)
{
	int i = 0;
	while (b[i] != '\0')
	{
		a[i] = b[i];
		i++;
	}
	a[i] = '\0';
}

int isnum(char *exp)
{
	int i = 0;
	while (exp[i] != '\0')
	{
		if ((exp[i] >= '0'&&exp[i] <= '9') || exp[i] == '*' || exp[i] == '/' || exp[i] == '%' || exp[i] == '-' || exp[i] == '^' || exp[i] == '+' || exp[i] == ')' || exp[i] == '(')
		{

			i++;
		}
		else
		{
			return 0;
		}

	}
	return 1;
}
void import(int flag,char *filename,node **mat)
{
	char buffer[1024];
	char *record, *line;
	int i = 0, j = 0;

	FILE *fstream = fopen(filename, "r+");
	if (fstream == NULL)
	{
		printf("\n file opening failed");

	}
	else
	{
		int c = 0;
		while ((line = fgets(buffer, sizeof(buffer), fstream)) != NULL)
		{
			
			if (flag == 1 && c == 0)
			{
				record = strtok(line, "\t");
				while (record != NULL)
				{

					if (isnum(record))
					{
						mat[i][j].value = strtoint(record);
						strcopy(mat[i][j++].formula, record);

					}
					else
					{
						strcopy(mat[i][j++].string, record);
					}
					record = strtok(NULL, "\t");
				}
				c = -1;
			}
			if (c == 0)
			{
				record = strtok(line, "\t");
				while (record != NULL)
				{

					if (isnum(record))
					{
						mat[i][j].value = strtoint(record);
						strcopy(mat[i][j++].formula, record);
					}
					else
					{
						strcopy(mat[i][j++].string, record);
					}
					record = strtok(NULL, "\t");
				}

			}
			flag = 0;
			c = 0;

			i++;
			j = 0;

		}

	}
}

void print(int flag,node **mat,char *head)
{
	if (strcmp(head, "") == 0)
	{
		int n = 9;
		if (flag == 1)
			n = 10;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (strcmp(mat[i][j].string, "") == 0)
				{
					printf("%d ", mat[i][j].value);
				}
				else
				{
					printf("%s ", mat[i][j].string);
				}


			}
			printf("\n");
		}
	}
	else
	{
		int i = 0, sum = 0;
		for (i = 0; i <=11; i++)
			if (strcmp(head, mat[0][i].string) == 0)
			{
				break;
			}
		if (i == 12)
		{
			for (i = 0; i < 10; i++)
			{
				if (strcmp(head, mat[i][0].string) == 0)
				{
					break;
				}
			}
			if (i == 10)
				printf("%s not found", head);
			else
			{
				
				for (int j = 0; j <=11; j++)
				{
					
					if (strcmp(mat[i][j].string, "") == 0)
					{
						printf("%d ", mat[i][j].value);
					}
					else
					{
						printf("%s ", mat[i][j].string);
					}
				}
			}
			printf("\n");
		}
		else
		{
			
			for (int j = 0; j < 10; j++)
			{
				if (strcmp(mat[j][i].string, "") == 0)
				{
					printf("%d\n", mat[j][i].value);
				}
				else
				{
					printf("%s\n", mat[j][i].string);
				}
			}

		}

	}
}
void print_header(node **mat)
{
	for (int i = 0; i < 12; i++)
	{
		printf("%s ", mat[0][i].string);
	}
	
}
int sum(char *name,node **mat)
{
	int i = 0,sum=-1;
	for (i = 0; i < 11;i++)
		if (strcmp(name, mat[0][i].string) == 0)
		{
			break;
		}
	if (i == 11)
	{
		for (i = 0; i < 10; i++)
		{
			if (strcmp(name, mat[i][0].string) == 0)
			{
				break;
			}
		}
		if (i == 10)
			printf("%s not found", name);
		else
		{
			sum = 0;
			for (int j = 2; j < 11; j++)
			{
				sum += mat[i][j].value;
			}
		}
	}
	else
	{
		sum = 0;
		for (int j = 1; j < 10; j++)
		{
			sum += mat[j][i].value;
		}

	}
	return sum;
	
}
int avg(char *name, node **mat)
{
	int i = 0, sum = -1;
	for (i = 0; i < 11; i++)
		if (strcmp(name, mat[0][i].string) == 0)
		{
			break;
		}
	if (i == 11)
	{
		for (i = 0; i < 10; i++)
		{
			if (strcmp(name, mat[i][0].string) == 0)
			{
				break;
			}
		}
		if (i == 10)
			printf("%s not found", name);
			
		else
		{
			sum = 0;
			int j = 0;
			for ( j = 2; j < 11; j++)
			{
				sum += mat[i][j].value;
			}
			sum /= 10;
		}
	}
	else
	{
		sum = 0;
		int j = 0;
		for (j = 1; j < 10; j++)
		{
			sum += mat[j][i].value;
		}
		sum /=9;
	}
	return sum;

	
	
}
void topper(node **mat, char* name)
{
	if (strcmp(name, "") == 0)
	{
		int row = 0;
		for (int i = 1; i <= 9; i++)
		{
			int sum = 0, fin = 0;;
			for (int j = 2; j <= 11; j++)
			{
				sum += (mat[i][j].value);
			}
			if (sum > fin)
			{
				fin = sum;
				row= i;
			}

		}
		printf("%s\n", mat[row][0].string);
	}
	else
	{
		for (int i = 2; i <= 11; i++)
		{
			if (strcmp(mat[0][i].string, name) == 0)
			{
				int row = 0;
				int value = 0;
				for (int j = 1; j <= 9; j++)
				{
					if (mat[j][i].value > value)
					{
						value = mat[j][i].value;
						row = j;
					}
				}
				printf("%s\n", mat[row][0].string);
				return;
			}
			
		}
		printf("%s not found", name); 
	}
}
char *lower(char *str)
{
	int i = 0;
	while (str[i] != ' '&&str[i]!='\0')
	{
		if (str[i] >= 'A'&&str[i] <= 'Z')
		{
			str[i] = str[i] - 'A' + 'a';
		}
		i++;
	}
	return str;
}
char *higher(char *str)
{
	int i = 0;
	while (str[i] != ' '&&str[i] != '\0')
	{
		if (str[i] >= 'a'&&str[i] <= 'z')
		{
			str[i] = str[i] - 'a' + 'A';
		}
		i++;
	}
	return str;
}
void set(char *str, struct node **mat, char *formula)
{
	int j = str[0] - 'A';
	int i = 0;
	int k = 1;
	while (str[k] != '\0')
	{
		i *= 10;
		i += str[k] - '0';
		k++;
	}
	i-= 1;
	if (strcmp(mat[i][j].string, "") == 0)
		strcpy(mat[i][j].formula, formula);
	else
		printf("formula not set for strings\n");
}

int iscell(char *exp)
{
	int f = 0;
	while (exp[f]>='A'&&exp[f]<='Z')
	{
		f++;
	}
	int k = f;
	while (exp[f] >= '0'&&exp[f] <= '9')
	{
		f++;
	}
	if (k != f)
	{
		if (exp[f] == '\0')
			return 1;
	}
	return 0;
}
char *removeformula(char *formula, node **mat)
{
	char *result = (char *)malloc(sizeof(char) * 100);
	char *fina1 = (char *)malloc(sizeof(char) * 100);
	int f = 0, len = 0, in = 0;;
	while (formula[f] != '\0')
	{
		if (formula[f] == '+' || formula[f] == '-' || formula[f] == '*' || formula[f] == '/' || formula[f] == '^' || formula[f] == '%' || formula[f] == ')')
		{
			result[len] = '\0';

			if (len != 0)
			{
				len = 0;
				char *record = strtok(result, " ");
				if (strcmp(lower(record), "avg") == 0 || strcmp(lower(record), "sum") == 0)
				{


					record = strtok(NULL, " ");
					int val = sum(record, mat);
					char res[10];
					sprintf(res, "%d", val);
					int f1 = 0;
					while (res[f1] != '\0')
					{
						fina1[in++] = res[f1];
						f1++;
					}


				}
				else
				{
					int f1 = 0;
					while (result[f1] != '\0')
					{
						fina1[in++] = result[f1];
						f1++;
					}


				}
			}
			fina1[in++] = formula[f];
		}

		else
		{
			if (formula[f] == '(')
			{
				fina1[in++] = formula[f];;
			}
			else
			{
				result[len++] = formula[f];
			}
		}
		f++;
	}
	result[len] = '\0';

	if (len != 0)
	{
		len = 0;
		char *record = strtok(result, " ");
		if (strcmp(lower(record), "avg") == 0 || strcmp(lower(record), "sum") == 0)
		{


			record = strtok(NULL, " ");
			int val = sum(record, mat);
			if (val == -1)
				return NULL;
			char res[10];
			sprintf(res, "%d", val);
			int f1 = 0;
			while (res[f1] != '\0')
			{
				fina1[in++] = res[f1];
				f1++;
			}


		}
		else
		{
			int f1 = 0;
			
			while (result[f1] != '\0')
			{
				fina1[in++] = result[f1];
				f1++;
			}


		}
	}
	fina1[in++] = formula[f];
	return higher(fina1);

}
char *expansion(char *string, node **mat, int k, int j)
{ 
	string = removeformula(string, mat);
	if (string == NULL)
		return NULL;
	char a[4];
	a[0] = j + 'A';
	a[2] = '\0';

	if (k > 9)
	{
		a[1] = k / 10;
		a[2] = k % 10;
	}
	else
	{
		a[1] = k + '1';
	}
	a[3] = '\0';
	char *res = (char*)malloc(sizeof(char) * 100);
	int i = 0;
	char exp[10];
	int len = 0, in = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '%' || string[i] == '/' || string[i] == '-' || string[i] == '+' || string[i] == '^' || string[i] == '*' || string[i] == ')')
		{
			exp[len] = '\0';
			if (len > 0)
			{
				if (isnum(exp))
				{
					int f = 0;
					while (exp[f] != '\0')
					{
						res[in++] = exp[f];
						f++;
					}
				}

				else if (iscell(exp))
				{
					int col = exp[0] - 'A';
					int f = 1, row = 0;;
					while (exp[f] != '\0')
					{
						row *= 10;
						row += exp[f] - '0';
						f++;
					}
					row -= 1;

					f = 0;
					res[in++] = '(';
					while (mat[row][col].formula[f] != '\0')
					{
						res[in++] = mat[row][col].formula[f];
						f++;
					}
					res[in++] = ')';


				}

				res[in++] = string[i];
				len = 0;
			}
		}
		else if (string[i] == '(')
			res[in++] = string[i];
		else
		{
			exp[len++] = string[i];
		}
		i++;
			
	}
		
	exp[len] = '\0';
	res[in] = string[i];
	if (isnum(exp))
	{
		int f = 0;
		while (exp[f] != '\0')
		{
			res[in++] = exp[f];
			f++;
		}
		res[in++] = exp[f];
	}
	else if (iscell(exp))
	{

		int col = exp[0] - 'A';
		int f = 1, row = 0;;
		while (exp[f] != '\0')
		{
			row *= 10;
			row += exp[f] - '0';
			f++;
		}
		row -= 1;

		f = 0;
		res[in++] = '(';
		while (mat[row][col].formula[f] != '\0')
		{
			res[in++] = mat[row][col].formula[f];
			f++;
		}
		res[in++] = ')';


	}


	res[in++] = string[i];
	res[in] = '\0';
	if (strstr(res, a))
	{

		return NULL;
	}
	if (isnum(res))
	{
		return  res;
	}
	else
	{
		return expansion(res, mat, k, j);
	}
}
int priority(char op)
{
	if (op == '^')
		return 3;
	if (op == '*' || op == '/' || op == '%')
		return 2;
	return 1;
}
int postfix(char *exp[], int len)
{
	int stack[100], top = -1;
	for (int i = 0; i <= len; i++)
	{
		if (exp[i][0] == '/' || exp[i][0] == '%' || exp[i][0] == '*' || exp[i][0] == '^' || exp[i][0] == '+' || exp[i][0] == '-')
		{
			int b = (stack[top--]);
			int a = stack[top--];
			if (exp[i][0] == '*')
				stack[++top] = a*b;
			else if (exp[i][0] == '/')
				stack[++top] = a / b;
			else if (exp[i][0] == '%')
				stack[++top] = a %b;
			else if (exp[i][0] == '-')
				stack[++top] = a - b;
			else if (exp[i][0] == '+')
				stack[++top] = a + b;
			else if (exp[i][0] == '^')
				stack[++top] = (int)pow((double)a, (double)b);

		}
		else
		{
			stack[++top] = strtoint(exp[i]);
		}
	}
	if (top == 0)
		return stack[top];
	return -999999;
}
int evaluation(char *exp)
{
	int i = 0, len = 0;
	char  stack2[100];
	char **stack1 = (char**)malloc(sizeof(char*) * 100);
	for (int i = 0; i < 100; i++)
	{
		stack1[i] = (char*)malloc(sizeof(char) * 100);
	}
	int top1 = -1, top2 = -1;
	char *num = (char*)malloc(sizeof(char) * 10);
	while (exp[i] != '\0')
	{
		if ((exp[i] == '*' || exp[i] == '/' || exp[i] == '%' || exp[i] == '-' || exp[i] == '^' || exp[i] == '+'))
		{
			num[len] = '\0';

			len = 0;
			if (exp[i - 1] != ')')
			{
				strcpy(stack1[++top1], num);
			}
			while (top2 != -1 && stack2[top2] != '(' && (priority(exp[i]) <= priority(stack2[top2])))
			{
				char *a = (char*)malloc(sizeof(char) * 2);
				a[0] = stack2[top2--];
				a[1] = '\0';
				strcpy(stack1[++top1], a);

			}
			stack2[++top2] = exp[i];


		}
		else if (exp[i] == '(')
		{
			stack2[++top2] = exp[i];


		}
		else if (exp[i] == ')')
		{

			if (len != 0)
			{
				num[len] = '\0';
				strcpy(stack1[++top1], num);
			}
			len = 0;
			while (stack2[top2] != '(')
			{
				char *a = (char*)malloc(sizeof(char) * 2);
				a[0] = stack2[top2];
				a[1] = '\0';
				strcpy(stack1[++top1], a);
				top2--;
			}
			top2--;

		}
		else
		{
			num[len++] = exp[i];
		}
		i++;
	}
	num[len] = '\0';

	if (len != 0)

		strcpy(stack1[++top1], num);
	while (top2 != -1)
	{
		char *a = (char*)malloc(sizeof(char) * 2);
		a[0] = stack2[top2--];
		a[1] = '\0';
		strcpy(stack1[++top1], a);

	}
	stack2[++top2] = exp[i];

	return postfix(stack1, top1);
}

int evaluate(node cell, int i, int j, node **mat)
{
	char a[4];
	a[0] = j + 'A';
	a[2] = '\0';
	if (i > 9)
	{
		a[1] = i / 10;
		a[2] = i % 10;
	}
	else
	{
		a[1] = i + '1';
	}


	a[3] = '\0';
	
	char *result = expansion(cell.formula, mat, i, j);
	if (result != NULL)
	{
		int value = evaluation(result);
		if (value == -999999)
		{
			//printf("invalid expression");
			return 0;
		}
		else
			mat[i][j].value = value;
	}
	else
		return 0;
	return 1;
}
void get(char* str, struct node **mat)
{
	int j = str[0] - 'A';
	int f = 1, i = 0;;
	while (str[f] != '\0')
	{
		i *= 10;
		i += str[f] - '0';
		f++;
	}
	i -= 1;
	if (strcmp(mat[i][j].string, "") == 0)
	{
		int flag = evaluate(mat[i][j], i, j, mat);
		if (flag == 1)
			printf("%d", mat[i][j].value);
		else
			printf("invalid ");
	}
	else
	{
		printf("%s",mat[i][j].string);
	}
}
int main()
{
	struct node** mat = (struct node**)malloc(sizeof(struct node*) * 20);
	for (int i = 0; i < 20; i++)
	{
		mat[i] = (struct node*)malloc(sizeof(struct node)*20);
	}
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			strcopy(mat[i][j].formula, "0");
			strcopy(mat[i][j].string, "");
			mat[i][j].value = 0;



		}
	}
	
	

	while (1)
	{
		printf(">");
		char *command = (char*)malloc(sizeof(char) * 100);
		scanf("%[^\n]s", command);
		char dummy;
		scanf("%c", &dummy);
		lower(command);
		char *record;
		if (strstr(command, "sum"))
		{
			record = strtok(command, " ");
			record = strtok(NULL, " ");
			printf("%d ", sum(record, mat));
			printf("\n");
		}
		if (strstr(command, "avg"))
		{
			record = strtok(command, " ");
			record = strtok(NULL, " ");
			printf("%d ", avg(record, mat));
			printf("\n");
		}
		if (strstr(command, "print"))
		{
			record = strtok(command, " ");
			record = strtok(NULL, " ");
			if (record==NULL)
				print(1, mat, "");

			else if (strcmp(lower(record), "header") == 0)
			{
				print_header(mat);
			}
			else
			{
				higher(record);
				print(1, mat, record);
			}
			printf("\n");
		}
		if (strstr(command, "import"))
		{
			record = strtok(command, " ");
			record = strtok(NULL, " ");
			import(1, record, mat);
		}
		if (strstr(command, "topper"))
		{
			record = strtok(command, " ");
			record = strtok(NULL, " ");
			if (record == NULL)
				topper(mat, "");
			else
				topper(mat, record);
		}
		if (strstr(lower(command), "exit"))
		{
			exit(0);
		}
		if (strstr(command, "set"))
		{
			int c = 0;
			record = strtok(command, " ");
			char *cd = (char*)malloc(sizeof(char) * 100);
			
			record = strtok(NULL, "=");
			strcpy(cd, record);
			record = strtok(NULL, "=");
			set(cd, mat, record);
		}
		char *cd = (char*)malloc(sizeof(char) * 100);
		if (strstr(command, "get"))
		{
			strcpy(cd, command);
			int c = 0;
			record = strtok(command, " ");
			while (record != NULL)
			{
				c++;
				record = strtok(NULL, " ");
			}
			if (c > 2)
				printf("invalid function");
			else
			{
				record = strtok(cd, " ");
				record = strtok(NULL, " ");
				get(record, mat);
			}
			printf("\n");
		}

	}
	system("pause");
}