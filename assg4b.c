#include<stdio.h>

int binary_search(int arr[],int val,int left,int right){
    int flag=-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]==val){
            flag=mid;
            break;
        }
        else if(arr[mid]>val){
            return binary_search(arr,val,left,mid-1);
        }
        else{
            return binary_search(arr,val,mid+1,right);
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
    
    int ans=binary_search(arr,val,0,len-1);   

    if(ans!=-1){
        printf("the value is found at %d position",ans+1);
    }
    else{
        printf("the value is not present in the array");
    }

    return 0;
}