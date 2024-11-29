#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left,*right;
};

struct node* newnode(int a)
{
	struct node* leaf=(struct node*)malloc(sizeof(struct node));
	leaf->data=a;
	leaf->left=leaf->right=NULL;
	return leaf;
}

struct node* insert(struct node* ptr,int key)
{
	if(ptr==NULL)
		return newnode(key);
	if(key<ptr->data)
		ptr->left=insert(ptr->left,key);
	else
		ptr->right=insert(ptr->right,key);
	return ptr;	
}

void preorder(struct node* ptr)
{
	if(ptr!=NULL)
	{
		printf("%d \t",ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void postorder(struct node* ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%d \t",ptr->data);
	}
}void postorder(struct node* ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%d \t",ptr->data);
	}
}

void inorder(struct node* ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->left);
		printf("%d \t",ptr->data);
		inorder(ptr->right);
	}
}
