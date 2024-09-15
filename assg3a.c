#include<stdio.h>

int main(){
    int len,val,flag=-1;
    printf("enter the length of the array: ");
    scanf("%d",&len);
    int arr[len];
    for(int i=0;i<len;i++){
        printf("enter the arr[%d] element: ",i);
        scanf("%d",&arr[i]);
    }
    printf("enter the value to be searched for: ");
    scanf("%d",&val);
    
    for(int j=0;j<len;j++){
        if(arr[j]==val){
            flag=j;
            break;
        }
    }

    if(flag!=-1){
        printf("the value is found at %d position",flag+1);
    }
    else{
        printf("the value is not present in the array");
    }

    return 0;
}