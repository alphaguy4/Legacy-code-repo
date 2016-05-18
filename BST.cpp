// Implementaition of Binary search Trees
/*
	Three Basic operations available ::
	1.Insertion
	2.Deletion
	3.Searching 
	Time Complexity : O(logn)
*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node *left,*right;
};
void insert(struct Node **root,int data)
{
	int f = 1;
	struct Node *tmp = (struct Node *)malloc(sizeof(struct Node *));
	tmp->data = data;
	tmp->right = tmp->left =NULL;
	if(*root == NULL)
	{
		*root = tmp;
		return;
	}
	struct Node *cur = *root;
	struct Node *prev = *root;
	while(cur != NULL)
	{
		prev = cur;
		if(cur->data == data)
		{
			printf("Element already exist \n");
			return;
		}
		if(cur->data > data)
		{   
			f = 1;
			cur = cur->left;
		}
		else
		{
			f = 2;
			cur = cur->right;
		}
	}
	if(f == 1)
		prev->left = tmp;
	else
		prev->right = tmp;
	return;
}
void print(struct Node **root)
{
	if(*root == NULL)
	{
		return;
	}
	print(&((*root)->left));
	printf("%d ",(*root)->data);
	print(&((*root)->right));
}
void search(struct Node **root,int data)
{
	struct Node *cur = *root;
	while(cur!= NULL)
	{
		if(cur->data == data)
		{
			printf("Element Found.\n");
			return;
		}
		else
		if(cur->data > data)
		{
			cur = cur->left;
		}
		else
			cur = cur->right;
	}
	printf("Error 404 Not Found\n");
	return ;
}
void del(struct Node **root,int data)
{
	int f =0;
	if(root == NULL)
	{
		printf("Empty tree\n");
		return;
	}
	struct Node *prev = *root;
	struct Node *cur = *root;
	while(cur->data != data)
	{
		prev = cur;
		if(cur->data > data)
		{   
			f = 1; 
			cur = cur->left;
		}
		else
		{
			f = 2;
			cur = cur->right;
		}
	}
	if(cur == NULL)
	{
		printf("Not found\n");
		return;
	}
	//leaf Node
	if(cur->right == NULL &&cur->left == NULL)
	{
		if(f == 1)
			prev->left = NULL;
		else
			prev->right = NULL;
		free(cur);
		return;
	}
	// Only one child
	if(cur->left == NULL || cur->right == NULL )
	{
		if(cur->right != NULL)
			prev->right = cur->right;
		else
			prev->left = cur->left;
		free(cur);
		return;
	}
	else
	{
		int data;
		struct Node *temp = cur->right;
		while(temp != NULL)
		{
			data = temp->data;
			temp = temp->left;
		}
		cur->data = data;
		prev->right = cur->right;
		free(cur);
		return;
	}
}
int main()
{
	int tmp,choice;
	struct Node *root=NULL;
	printf("Created an empty BST :: \n\n");
	printf("1.To insert a number\n");
	printf("2.Delete an existing number\n");
	printf("3.Search an element\n");
	printf("4.To print Inorder Traversal of tree\n");
	while(1)
	{
		printf("> ");
		scanf("%d",&choice);
		switch(choice) 
		{
			case 1 : printf("Element :");
					 scanf("%d",&tmp);
					 insert(&root,tmp);
					 break;
			case 2 : printf("Delete :");
					 scanf("%d",&tmp);
					 del(&root,tmp);
					 break;
			case 3 : printf("Search :");
					 scanf("%d",&tmp);
					 search(&root,tmp);
					 break;
			case 4 : print(&root);
					 printf("\n");
					 break;
			default : printf("Invalid Choice\n"); 

		}
	}
	return 0;
}