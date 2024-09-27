#include<stdio.h>
#define size 100

void merge(int arr[],int beg,int mid,int end){
    int i=beg,j=mid+1,index=beg,temp[size],k;
    while((i<=mid) && (j<=end)){
        if(arr[i]<arr[j]){
            temp[index]=arr[i];
            i++;
        }
        else{
            temp[index]=arr[j];
            j++;
        }
        index++;
    }
    if(i>mid){
        while(j<=end){
            temp[index]==arr[j];
            j++;
            index++;
        }
    }
    else{
        while(i<=mid){
            temp[index]=arr[i];
            i++;
            index++;
        }
    }
    for(k=beg;k<index;k++){
        arr[k]=temp[k];
    }
    
}

void merge_sort(int arr[],int beg,int end){
    int mid;
    if(beg<end){
        mid=(beg+end)/2;
        merge_sort(arr,beg,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,beg,mid,end);
    }
}

int main(){
    int arr[100],n,i;
    printf("enter the length of the array:");
    scanf("%d",&n);

    printf("enter the elements:");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    merge_sort(arr,0,n-1);
    
    printf("the sorted array is: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}