
#include<stdio.h>
#include<stdlib.h>

int main() {
    // insert code here...
    int **arr1,**arr2,r1,c1,r2,c2,i,j,k;
    int **arr3;
    printf("Size-1:");
    scanf("%d%d",&r1,&c1);
    printf("Size-2:");
    scanf("%d%d",&r2,&c2);
    arr1=(int** )malloc(r1*c1*sizeof(int));
    arr2=(int** )malloc(r2*c2*sizeof(int));
    for (i=0;i<r1;i++)
    {
        for (j=0;j<c1;j++)
            printf("%d %d", i,j);
            scanf("%d:",&arr1[i][j]);
    }
    for (i=0;i<=r2;i++)
    {
        for (j=0;j<c2;j++)
                        printf("%d %d", i,j);
            scanf("%d:",&arr2[i][j]);
    }

    if (c1==r2)
    {    printf("Multiplication possible\n");
        arr3=(int**)malloc(r1*c2*sizeof(int));
    }
    else
    {    printf("Multiplication not possible\n");
       // getch();
        exit(0);
    }
    for (i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            for (k=0; k<c1; k++) {
                arr3[i][j]+=arr1[i][k]*arr2[k][i];
            }
        }
    }
    for (i=0;i<r1;i++)
    {
        for (j=0;j<c2;j++)
            printf("%d\t",arr3[i][j]);
        printf("\n");
    }
    getch();


}
