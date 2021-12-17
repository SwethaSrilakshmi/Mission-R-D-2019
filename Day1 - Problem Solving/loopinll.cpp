#include<stdio.h>
#include<stdlib.h>
struct sll
{
	int data;
	struct sll *next;
};
typedef struct sll node;
node *detectLoop(node *head)
{
	node *slow = head->next;
	node *fast = head->next->next;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	slow = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
node *getnode(char s)
{
	node * newnode = (node *)malloc(sizeof(node));
	newnode->data = s;
	newnode->next = NULL;
	return newnode;
}
int main()
{
	node *head = getnode('1');
	head->next = getnode('2');
	head->next->next = getnode('3');
	head->next->next->next = getnode('4');
	head->next->next->next->next = getnode('5');

	head->next->next->next->next->next = getnode('6');

	head->next->next->next->next->next->next = head->next->next->next;
	node * Node = detectLoop(head);
	return 0;
}