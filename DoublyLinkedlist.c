//Some operations on Doubly linked list 
#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
    struct Node *left,*right;
};
int isEmpty(struct Node **head)
{
	if(*head == NULL)
		return 1;
	else
		return 0;
}
void insertAtBeg(struct Node **head,int data)
{
	struct Node *tmp = (struct Node *)malloc(sizeof(struct Node *));
	tmp->data = data;
	tmp->right = NULL;
	tmp->left = NULL;
	if(*head == NULL)
	{
		*head = tmp;
		return;
	}
	tmp->right = *head;
	*head = tmp;
}
void insertAtEnd(struct Node **head,int data)
{
	struct Node *tmp = (struct Node *)malloc(sizeof(struct Node *));
	tmp->data = data;
	tmp->right = NULL;
	tmp->left = NULL;
	if(*head == NULL)
	{
		(*head) = tmp;
		return;
	}
	struct Node *cur = *head;
	while(cur->right!= NULL)
	{
		cur = cur->right;
	}
	tmp->left = cur;
	cur->right = tmp;
}
void print(struct Node **head)
{
	struct Node *cur = *head;
	while(cur)
	{
		printf("%d ",cur->data);
		cur = cur->right;
	}
	printf("\n");
}
void remove(struct Node **head,int data)
{
	int flag = 0;
	if(isEmpty(head))
	{
		printf("List is Empty\n");
		return;
	}
	struct Node *cur = *head;
	if((*head)->data == data)
	{
		*head = cur->right;
		free(cur);
		return;	
	}
	struct Node *prev = *head;
	while(cur != NULL)
	{
		if(cur->data == data)
		{
			flag = 1;
			break;
		}
		prev = cur;
		cur = cur->right;
	}
	if(!flag)
	{
		printf("Error 404 Not Found\n");
		return;
	}
	prev->right = cur->right;
	free(cur);

}
void duplicate(struct Node **head)
{
	struct Node *p,*q;
	p = *head;
	while( p->right != NULL)
	{
		q = p->right;
		while( q != NULL)
		{
			if(p->data == q->data)
			{
				remove(head,p->data);
			}
			q = q->right;
		}
		p = p->right;
	}
}
void sort(struct Node **head)
{
	struct Node *p,*q;
	p = *head;
	while(p->right != NULL)
	{
		q = p->right;
		while (q != NULL)
		{
			if(p->data > q->data)
			{
				p->data += q->data;
				q->data =p->data - q->data;
				p->data -= q->data;
			}
			q = q->right;
		}
		p = p->right;
	}
}
//Reversing the doubly Linked list
void reverse(struct Node **head)
{
	struct Node *cur = *head;
	struct Node *prev = NULL;
	struct Node *next;
	while(cur != NULL)
	{
		next = cur->right;
		cur->right = prev;
		cur->left = next;
		prev = cur;
		cur = next;
	}
	*head = prev;
}
int main()
{
	int tmp,choice;
	struct Node *head = NULL;
	printf("Congratulations You have sucessfully created A Doubly linked list\n\n");
	printf("1.To insert an Element at the END\n");
	printf("2.To insert Element at Beg\n");
	printf("3.Remove an element\n");
	printf("4.Print the D-linkedList \n");
	printf("5.To remove duplicate elements\n");
	printf("6.Sort the list\n");
	printf("7.Reverse the list\n");
	while(1)
	{
		printf("> ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : printf("Element : ");
					 scanf("%d",&tmp);
					 insertAtEnd(&head,tmp);
					 break;
			case 2 : printf("Element : ");
					 scanf("%d",&tmp);
					 insertAtBeg(&head,tmp);
					 break;
			case 3 : printf("Remove : ");
					 scanf("%d",&tmp);
					 remove(&head,tmp);
					 break;
			case 4 : print(&head);
					 break;
			case 5 : duplicate(&head);
					 break;
			case 6 : sort(&head);
					 break;
			case 7 : reverse(&head);
					 break;
			default: printf("Invalid Choice\n");
		}
	}
	return 0;
}