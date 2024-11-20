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

int main(){
  int val,ch;
  while(1){
    printf("\nMENU:\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n");
    printf("enter your choice:");
    scanf("%d",&ch);
    switch(ch){
      case 1:
        printf("enter the data to be inserted:");
        enqueue();
        break;

      case 2:
        if(front==NULL){
          printf("UNDERFLOW");
        }
        else{
          val=dequeue();
          printf("%d is deleted\n",val);
        }
        break;

      case 3:
        ptr=front;
        if(ptr==NULL){
          printf("Queue empty");
        }
        else{
          printf("the values are:\n");
          while(ptr!=NULL){
            printf("%d ",ptr->data);
            ptr=ptr->next;
          }
          printf("\n");
        }
        break;

      case 4:
        exit(0);

      default:
        printf("wrong choice input");    
    }
  }
  return 0;
}
