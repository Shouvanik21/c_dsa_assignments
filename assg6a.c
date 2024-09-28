#include<stdio.h>
#define size 100

void swap(int* a, int* b) {  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
int set_loc(int arr[], int low, int high) {  
    int p = arr[low];
    int i = low;
    int j = high;

    while (i < j) {

        // Find the first element greater than
        // the pivot (from starting)
        while (arr[i] <= p && i <= high - 1) {
            i++;
        }

        // Find the first element smaller than
        // the pivot (from last)
        while (arr[j] > p && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j; 
}  

void quick_sort(int arr[],int beg,int end){
    int loc;
    if(beg<end){
        loc=set_loc(arr,beg,end);
        quick_sort(arr,beg,loc);
        quick_sort(arr,loc+1,end);
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

    quick_sort(arr,0,n-1);
    
    printf("the sorted array is: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}