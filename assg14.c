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

int main()
{
	int ch,key,i,n;
	struct node* root=NULL;
	printf("Enter the number of keys to be stored:");
	scanf("%d",&n);
	printf("Enter key to insert: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&key);
		root=insert(root,key);
	}
	printf("\nMenu:\n");
        printf("1. PREORDER\n");
        printf("2. INORDER\n");
        printf("3. POSTORDER\n");
        printf("4. Exit\n");
	while(1)
	{
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
		switch(ch)
		{
			case 1:
			preorder(root);
			       break;
			case 2:
			inorder(root);
			       break;
			case 3:
			postorder(root);
			       break;	   	   	   
			case 4:
			exit(0);       
		}
	}
	return 0;
}
