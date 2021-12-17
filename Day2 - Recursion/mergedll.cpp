#include<stdio.h>
#include<stdlib.h>
struct dll
{
	struct dll *left;
	struct dll *right;
	int value;
};
typedef struct dll node;
node *split(node *head)
{
	node *fast = head, *slow = head;
	while (fast->right != NULL&&fast->right->right != NULL)
	{
		slow = slow->right;
		fast = fast->right->right;

	}
	node *temp = slow->right;
	slow->right = NULL;
	return temp;
}
node *merge(node *first,node *second)
{
	if (first == NULL)
		return second;
	if (second == NULL)
		return first;
	if (first->value<second->value)
	{
		first->right = merge(first->right, second);
		first->right->left = first;
		first->left= NULL;
		return first;
	}
	else
	{
		second->right = merge(first, second->right);
		second->right->left = second;
		second->left = NULL;
		return second;
	}

}
node *mergesort(node *head)
{
	if (head == NULL || head->right == NULL)
		return head;
	node *second = split(head);
	head=mergesort(head);
	second = mergesort(second);
	return merge(head, second);

}
node *getnode(char s)
{
	node * newnode = (node *)malloc(sizeof(node));
	newnode->value = s;
	newnode->right = NULL;
	newnode->left = NULL;
	return newnode;
}
node *create(char *s,node **end)
{
	node *temp = NULL;
	node *head = NULL;
	int i = 0;
	while (s[i] != '\0')
	{
		if (head == NULL)
		{
			head = getnode(s[i]);
			*end = head;
		}
		else
		{
			temp = head;
			while (temp->right != NULL)
			{
				temp = temp->right;
			}
			temp->right = getnode(s[i]);
			
			temp->right->left = temp;
			*end = temp->right;
		}
		i++;
	}
	return head;
}
int main()
{
	char s[] = "54321878";
	node *end = NULL;
	node *head = create(s,&end);
	
	head=mergesort(head);
	while (head != NULL)
	{
		printf("%c ", head->value);
		head = head->right;
	}
	return 0;
}