#include<stdio.h>
#include<stdlib.h>

int main(){
    int len,ch;
    printf("enter the length of the array:");
    scanf("%d",&len);
    printf("enter the elements of the array:");
    int arr[len];
    for(int i=0;i<len;i++){
        scanf("%d",&arr[i]);
    }

    while(1){
        printf("enter your choice: 1.find max and min 2.insert an element 3.remove an element 4.display the array 5.exit  ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                int min=arr[0],max=arr[0];
                for(int i=0;i<len;i++){
                    if(arr[i]>max){
                        max=arr[i];
                    }
                    if(arr[i]<min){
                        min=arr[i];
                    }
                }
                printf("the maximum element is %d and the minimum element is %d \n",max,min);
                break;

            case 2:
                int val,loc;
                printf("enter the value:");
                scanf("%d",&val);
                printf("enter the location:");
                scanf("%d",&loc);
                if(loc>=0  && loc <=len-1){
                    for(int i=len;i>=loc;i--){
                        arr[i]=arr[i-1];
                    }
                    arr[loc-1]=val;
                    len=len+1;

                    for(int i=0;i<len;i++){
                    printf("%d\n",arr[i]);
                }
                }
                else{
                    printf("loc is out of index \n");
                }               
                break;

            case 3:
                int LOC;
                printf("enter the location:");
                scanf("%d",&LOC);
                if(LOC>=0  && LOC<=len-1){
                    for(int i=LOC-1;i<len;i++){
                        arr[i]=arr[i+1];
                    }
                    len=len-1;

                    for(int i=0;i<len;i++){
                    printf("%d\n",arr[i]);
                }
                }
                else{
                    printf("loc is out of index \n");
                }          
                break;

            case 4:
                for(int i=0;i<len;i++){
                    printf("%d\n",arr[i]);
                }
                break;

            case 5:
                exit(0);   

            default:
                printf("invalid choice input");  
        }
    }

    return 0;
}