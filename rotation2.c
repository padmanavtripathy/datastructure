#include<stdio.h>
int main()
{
    int d, n;
    printf("Enter The number of array elements:-");
    scanf("%d",&n);
    int arr[n];
    printf("Number of rotation:");
    scanf("%d",&d);
    int copy[d];

    printf("Enter The array elements:-");
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<d;i++)
    {
        copy[i]=arr[i];
    }
    for(int j=0;j<n-d;j++){
    arr[j] =arr[d+j];
    }
    for(int i=0;i<d;i++)
    {
        arr[n-d+i]=copy[i];
    }
    for(int i=0;i<n;i++)
    {
        printf("%4d",arr[i]);
    }
}