#include<stdio.h>
#include<stdlib.h>

int main(){
    int r,c,nz=0;
    printf("enter the no of rows and columns for the matrix:");
    scanf("%d %d",&r,&c);
    int arr[r][c];
    printf("enter the elements for the matrix:\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("enter the arr[%d][%d] element ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }

    printf("the matrix is:\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d ",arr[i][j]);
            if(arr[i][j]!=0){
                nz++;
            }
        }
        printf("\n");
    }

    int sparse[nz+1][3];

    if(nz>=(r*c)/2){
        printf("this is not a sparse matrix");
        exit(0);
    }
    else{
        sparse[0][0]=r;
        sparse[0][1]=c;
        sparse[0][2]=nz;
        int s=1;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(arr[i][j]!=0){
                    sparse[s][0]=i;
                    sparse[s][1]=j;
                    sparse[s][2]=arr[i][j];
                    s++;
                }
            }
        }

        printf("the sparse matrix in 3-tuple format is:\n");
        for(int i=0;i<nz+1;i++){
            for(int j=0;j<3;j++){
                printf("%d ",sparse[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}