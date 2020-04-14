#include<stdio.h>
#include<stdlib.h>

/*****BY Aman Gupta*****/
/*Creation of Tree and traversal of node*/

struct node
{
	struct node *lchild;
	struct node *rchild;
	char data;
}*root=NULL;


struct node *createTree()
{
	char x,y;
	scanf("%c",&x);
	scanf("%c",&y);
	if(x-48==0)
	return NULL;

	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	p->data=x;
	p->lchild=p->rchild=NULL;
	
	printf("Enter the left child of %c\n",p->data);
	p->lchild=createTree();
	printf("Enter the right child of %c\n",p->data);
	p->rchild=createTree();
	return p;
	
}


void preorder(struct node *p)
{
	if(p)
	{
		printf("%c ",p->data);
		preorder(p->lchild);
		preorder(p->rchild);
	}
}


void inorder(struct node *p)
{
	if(p)
	{
		inorder(p->lchild);
		printf("%c ",p->data);
		inorder(p->rchild);
	}
}


void postorder(struct node *p)
{
	if(p)
	{
		
		postorder(p->lchild);
		postorder(p->rchild);
		printf("%c ",p->data);
	}
}


int main()
{
	printf("Enter the data of nodes of the tree (0 for no input)\n");

	printf("Enter the root element\n");
	root=createTree(root);
	
	printf("\nThe preorder traversal is\n");
	preorder(root);

	printf("\n\nThe inorder traversal is\n");
	inorder(root);

	printf("\n\nThe postorder traversal is\n");
	postorder(root);

	return 0;
}