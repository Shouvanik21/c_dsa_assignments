#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char data;
    struct node *next;
};
struct node *ptr,*stack,*top=NULL;
