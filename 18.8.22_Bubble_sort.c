#include<stdio.h>
int main()
{
        int arr[10];
        int size,i,j,temp;
        printf("Enter the size of array:\n");
        scanf("%d",&size);
        printf("Enter array elements:\n");
        for(i=0;i<size;i++)
        {
            scanf("%d",&arr[i]);
        }
       printf("Elements before sorting are:\n");
       for(i=0;i<size;i++)
       {
        printf("[%d]\t",arr[i]);
       } 
    int x;
    printf("\nPress 1. For no operation\nPress 2. For bubble sort\n");
    scanf("%d",&x);
      switch(x)
      {
        case 1:
      {
        printf("No sorting is performed");
      }      
       case 2:
    {
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
    printf("Elements after sorting are\n");
    for(i=0;i<size;i++)
       {
        printf("[%d]\t",arr[i]);
       }
    }
}
}
