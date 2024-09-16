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
        int min_idx=i;
        for(int j=i+1;j<len;j++){
            if(arr[j]<arr[min_idx]){
                min_idx=j;
            }
            if(min_idx!=i){
                //swap them
                int temp=arr[min_idx];
                arr[min_idx]=arr[i];
                arr[i]=temp;
            }
        }
        
    }

    printf("\nthe sorted array is:\n");
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}