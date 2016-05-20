//Implementation of AVL trees
/*
	Basic operations 
	1.Insertion
	2.Searching an element
	3.Deletion 
	4.Inorder Traversal
*/ 
#include <stdio.h>
#include <stdlib.h>
struct Node{
	int data;
	struct Node *left,*right;
	int height;
};
struct Node *create(int data)
{
	struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));
	tmp->data = data;
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->height = 1;
	return tmp;
}
int max(int a,int b)
{
	return a > b ? a : b;
}
int height(struct Node *node)
{   
	if(node == NULL)
		return 0;
	return node->height;
}
int getbalance(struct Node *node)
{
	if(node == NULL)
		return 0;
	return height(node->left) - height(node->right);
}
// left rotation
struct Node *leftRotation(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    // Return new root
    return y;
}
struct Node *rightRotation(struct Node *x)
{
	struct Node *y = x->left;
	struct Node *tmp =  y->right;
	y->right = x;
	x->left = tmp;
	//Updating height
	x->height = max(height(x->left),height(x->right)) + 1;
	y->height = max(height(y->left),height(y->right)) + 1;

	return y;
}
// Worst case insertion O(2*logn)
struct Node *insert(struct Node *root,int data)
{
	if(root == NULL)
		return create(data);
	if(data > root->data)
		root->right = insert(root->right,data);
	else
		root->left  = insert(root->left,data);
	root->height = max(height(root->left),height(root->right)) + 1;
	int balance = getbalance(root);
	// left left case
	if(balance >  1 && data < root->left->data)
		return rightRotation(root);
	else // left right case
	if(balance > 1 && data > root->left->data)
	{
		root->left = leftRotation(root->left);
		return rightRotation(root);
	}
	else // right-right case
	if(balance < -1 && data > root->right->data)
	{
		return leftRotation(root);
	}
	else // right left case;
	if(balance < -1 && data < root->right->data)
	{
		root->right = rightRotation(root->right);
		return leftRotation(root);
	}
	// no change required;
	return root;

}
void search(struct Node *root,int tmp)
{
	if(root == NULL)
		return;
	if(root->data == tmp)
	{
		printf("Found\n");
		return;
	}
	search(root->left,tmp);
	search(root->left,tmp);
}
void print(struct Node *root)
{
	if(root == NULL)
		return;
	print(root->left);
	printf("%d ",root->data);
	print(root->right);
}
struct Node *getIntval(struct Node *root)
{
	struct Node *tmp = root;
	while(tmp->left)
		tmp = tmp->left;
	return tmp;
}
struct Node *delete(struct Node *root,int key)
{
	if(root == NULL)
		return root;
	if(key > root->data)
	{
		root->right = delete(root->right,key);
	}
	else
	if(key < root->data)
	{
		root->left = delete(root->left,key);
	}
	else
	{ 
		//one child or No child
		if(root->left == NULL || root->right == NULL)
		{
			struct Node *tmp = root->left ? root->left : root->right;
			if(tmp == NULL)
			{
				tmp = root;
				root = NULL;
			}
			else
				root = tmp;
			free(tmp);
		}
		else
		{
			struct Node *tmp = getIntval(root->right);
			root->data = tmp->data;
			root->right = delete(root->right,tmp->data);
		}
	}
	// if only one node
	if(root == NULL)
		return root;
	int balance = getbalance(root);
	//left left case
	if(balance > 1 && getbalance(root->left) >=0)
		return rightRotation(root);
	else // left-right case
	if(balance > 1 && getbalance(root->left) < 0)
	{
		root->right = leftRotation(root->right);
		return rightRotation(root);
	}
	else // right left case
	if(balance < -1 && getbalance(root->right) >=0)
	{
		root->left = rightRotation(root->left);
		return leftRotation(root);
	}
	else // right right case
	if(balance < -1 && getbalance(root->right) < 0)
	{
		return leftRotation(root);
	}
	return root;
}
int main()
{
	int tmp,choice;
	printf("Sucessfully created an Empty AVL tree\n\n");
	printf("1.Insert an element in Tree\n");
	printf("2.Search an element \n");
	printf("3.Delete an element\n");
	printf("4.print the InOrder Traversal\n");
	struct Node *root = NULL;
	while(1)
	{
		printf("> ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : printf("Element : ");
					 scanf("%d",&tmp);
					 root = insert(root,tmp);
					 break;
			case 2 : printf("Search : ");
					 scanf("%d",&tmp);
					 search(root,tmp);
					 break;
			case 3 : printf("Delete :");
					 scanf("%d",&tmp);
					 root = delete(root,tmp);		 
					 break;
			case 4 : print(root);
					 printf("\n");
					 break;
			default : printf("Invalid Choice\n\n");
		}
	}
	return 0;
}