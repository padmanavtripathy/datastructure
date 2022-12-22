#include<stdio.h>
int main()
{
    int arr[]={18,15,6,8,9,10};
    int x=18;
    for(int i=0;i<6;i++)
    {
        int temp=x-arr[i];
        for(int j=i+1;j<6;j++)
        {
            if(temp == arr[j])
            {
                printf("%d  and %d",arr[i],arr[j]);
            }
        }
    }
}