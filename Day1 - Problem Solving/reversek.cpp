#include<stdio.h>
#include<stdlib.h>
struct sll
{
	int data;
	struct sll *next;
};
typedef struct sll node;
node * reverseK(node * head,int k)
{
	node *temp = head;
	node *prev = NULL;
	while (temp != NULL)
	{
		node* stack[100];
			int top = -1;
		int count = 0;
		node *temp1 = temp;
		while (count < k&&temp!=NULL)
		{
			stack[++top] = temp;
			temp = temp->next;
			count++;
		}
		if (count == k)
		{
			while (top != -1)
			{
				if (prev == NULL)
				{
					prev = stack[top--];
					head = prev;

				}
				else
				{
					prev->next = stack[top--];
					prev = prev->next;
				}

			}
			prev->next = NULL;
		}
		else
		{
			prev->next = temp1;
		}
	}
	return head;

}
node *getnode(char s)
{
	node * newnode = (node *)malloc(sizeof(node));
	newnode->data = s;
	newnode->next = NULL;
	return newnode;
}
node *create(char *s)
{
	node *temp = NULL;
	node *head = NULL;
	int i = 0;
	while (s[i] != '\0')
	{
		if (head == NULL)
		{
			head = getnode(s[i]);
		
		}
		else
		{
			temp = head;
			while (temp->next!= NULL)
			{
				temp = temp->next;
			}
			temp->next= getnode(s[i]);

			
		}
		i++;
	}
	return head;
}
int main()
{

	char *s = "123455678";
	node *head = create(s);
	head = reverseK(head, 3);
	return 0;
}