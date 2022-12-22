#include<stdio.h>
int main()
{
    int d, n;
    printf("Enter The number of array elements:-");
    scanf("%d",&n);
    int arr[n];
    printf("Number of rotation:");
    scanf("%d",&d);

    printf("Enter The array elements:-");
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<d;i++)
    {
        int temp=arr[0];
        for(int j=0;j<n-1;j++){
            arr[j] =arr[j+1];
        }
        arr[n-1] = temp;
    }
    for(int i=0;i<n;i++)
    {
        printf("%4d",arr[i]);
    }
}