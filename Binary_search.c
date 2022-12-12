#include<stdio.h>
void binary_search(int arr[],int size)
{
      printf("To support for unsorted list bubble sort is performed\n");
      int temp,j;
    printf("List before sorting\n");
    for (int i=0; i<size; i++)
    {
        printf("%d ",arr[i]);
    }
    for(int i=0;i<size-1;i++)
    {
        for(j=0;j<size-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }   
    }
      printf("\nList after sorting:\n");
          for (int i=0; i<size; i++)
    {
        printf("%d ",arr[i]);
    }
      int el1,lb,ub,mid; //lb=Lower bound, ub= Upper bound, el1= element to be searched
   
    printf("\nEnter element to search: ");
    scanf("%d",&el1);

    lb=0;
    ub= size-1;
    mid=(lb+ub)/2;
    int location = -1;

    while (lb<=ub)
    {
        if (arr[mid]==el1)
        {
            printf("Element is present at: %d",mid);
            location=mid;
            break;
        }
        else if (arr[mid]>el1)
        {
            ub=mid-1;
        }
        else
        {
            lb=mid+1;
        }
        
        mid = (lb+ub)/2;
    }
    if (location == -1)
    {
        printf("Element not found");
    }
}
 int main()
{
    
     int A[10],size,ch;
    printf("Enter the size of array:");
    scanf("%d",&size);
    for (int i=0; i<size; i++)
    {

        printf("Enter value for A[%d]: ",i);
        scanf("%d",&A[i]);
    }
    binary_search(A,size);
    return 0;
}