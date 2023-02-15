#include<stdio.h>
int main()
{
    int i,j,h,n,m,o,a[20],b[20],c[20];
    printf("\n Enter the limit:");
    scanf("%d",&n);
    printf("\n Enter the 1st array elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n First Array elements:");
    for(i=0;i<n;i++)
    {
        printf("%d \t",a[i]);
    }
    printf("\n");
    printf("\n Enter the limit:");
    scanf("%d",&m);
    printf("\n Enter the 2nd array elements:");
    for(i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
    }
    printf("\n Second array elements:");
    for(i=0;i<m;i++)
    {
        printf("%d \t",b[i]);
    }
    printf("\n");
    //merge
    o = n + m;
    for( i = 0; i < n; i++)
       c[i] = a[i];
    for( i = 0; i < m; i++)
        c[i + n] = b[i];

    printf("\n The merged array: ");
    for( i = 0; i < o; i++)
        printf("%d ", c[i]);
     printf("\n");
    printf("\n The sorted Array: ");
    for( i = 0; i < o; i++){
        int temp;
        for( j = i + 1; j < o; j++) {
            if(c[i] > c[j]) {
                temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }
    for(i = 0; i < o ; i++)
        printf(" %d ",c[i]);
    return 0;
}
