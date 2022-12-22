#include <stdio.h>
int main()
{
    int num;
    printf("Enter the array size:");
    scanf("%d", &num);
    int arr[num], copy[num];
    printf("Enter the arry value :");
    int temp = 0;
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }
    int k = 0;
    for (int i = 0; i < num; i++)
    {
        if (temp != arr[i])
        {
            int count = 1;
            temp = arr[i];

            for (int j = i + 1; j < num; j++)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                }
                if (count == 3)
                {
                    count = 0;
                }
            }
            if (count)
            {
                for (int i = 0; i < count; i++)
                {
                    copy[k++] = arr[i];
                }
            }
            printf("%d",k);
        }
    }
    // for(int i=0;i<k;i++)
    // {
    //     arr[i]=copy[i];
    // }
    for (int i = 0; i < k; i++)
    {
        printf("%5d", copy[i]);
    }
}