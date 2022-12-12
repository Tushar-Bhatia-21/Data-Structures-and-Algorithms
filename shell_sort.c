#include<stdio.h>

void shell_sort(int arr[], int n)
{
    for(int interval=n/2;interval>0;interval/=2)
    {
        for(int i=interval;i<n;i+=1)
        {
            int temp=arr[i];
            int j;
            for(j=i;j>=interval && arr[j-interval]>temp;j-=interval)
            {
                arr[j]=arr[j-interval];
            }
            arr[j]=temp;
        }
    }
}

void print(int arr[],int size)
{
    for(int i=0;i<size;++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int data[5];
    int size;
    printf("Enter the number of elements: ");
    scanf("%d",&size);
    for(int i=0;i<size;i++)
    {
        printf("Enter element A[%d]: ",i);
        scanf("%d",&data[i]);
    }
    printf("\nElements before sorting are: ");
    print(data,size);
    
    shell_sort(data,size);

    printf("\nElements after sorting are: ");
    print(data,size);
    return 0;
}