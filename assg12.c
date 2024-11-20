#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int data;
  struct node *next;
}nn;
nn *ptr,*start='\0',*front=NULL,*rear=NULL;

void enqueue(){
  ptr=(nn*)malloc(sizeof(nn));  
  scanf("%d",&ptr->data);  
  ptr->next=NULL;
  if(front==NULL && rear==NULL){
    front=ptr;
    rear=ptr;
  }
  else{
    rear->next=ptr;
    rear=ptr;
  }
}

int dequeue(){
  int x;
  x=front->data;
  ptr=front;
  front=front->next;
  if(front==NULL){
    rear=NULL;
  }
  free(ptr);
  return x;
}
