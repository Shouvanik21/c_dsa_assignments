#include<stdio.h>

int linear_search(int arr[],int val,int len){
    int flag=-1;
    for(int j=0;j<len;j++){
        if(arr[j]==val){
            flag=j;
            break;
        }
    }
    return flag;
}

int main(){
    int len,val;
    printf("enter the length of the array: ");
    scanf("%d",&len);
    int arr[len];
    for(int i=0;i<len;i++){
        printf("enter the arr[%d] element: ",i);
        scanf("%d",&arr[i]);
    }
    printf("enter the value to be searched for: ");
    scanf("%d",&val);

    int ans=linear_search(arr,val,len);   
    

    if(ans!=-1){
        printf("the value is found at %d position",ans+1);
    }
    else{
        printf("the value is not present in the array");
    }

    return 0;
}