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

    for(int i=1;i<len;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }

    printf("\nthe sorted array is:\n");
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}