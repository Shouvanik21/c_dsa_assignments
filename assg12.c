#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int data;
  struct node *next;
}nn;
nn *ptr,*start='\0',*front=NULL,*rear=NULL;
