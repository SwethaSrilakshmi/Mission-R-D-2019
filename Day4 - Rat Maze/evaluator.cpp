#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
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
		if((exp[i] == '*' || exp[i] == '/' || exp[i] == '%' || exp[i] == '-' || exp[i] == '^' || exp[i] == '+'))
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

			if(len!=0)
				strcpy(stack1[++top1], num);
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

	if (len!=0)
		
	strcpy(stack1[++top1], num);
	while (top2!=-1)
	{
		char *a = (char*)malloc(sizeof(char) * 2);
		a[0] = stack2[top2--];
		a[1] = '\0';
		strcpy(stack1[++top1], a);

	}
	stack2[++top2] = exp[i];
	for (int i = 0; i <= top1; i++)
	{
		printf("%s\n ", stack1[i]);
	}
	return postfix(stack1, top1);
}
int main()
{
	int v=evaluation("(20/(2+3))^2*(3+2)");
	printf("%d", v);
	system("pause");
}