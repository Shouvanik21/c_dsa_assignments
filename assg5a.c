#include<stdio.h>

int main(){
    int len;
    printf("enter the length of the array: ");
    scanf("%d",&len);
    int arr[len];
    for(int i=0;i<len;i++){
        printf("enter the arr[%d] element: ",i);
        scanf("%d",&arr[i]);
    }
    

    printf("the unsorted array is:\n");
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }

    for(int i=0;i<len;i++){
        for(int j=0;j<len-i-1;j++){
            if(arr[j]>arr[j+1]){
                //swap them
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    printf("\nthe sorted array is:\n");
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}