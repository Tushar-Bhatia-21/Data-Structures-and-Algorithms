#include<stdio.h>
void linear_search(int arr[],int size)
{
    int element;
    for (int i=0; i<size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\nEnter the element to be searched:");
    scanf("%d",&element);
    int found=0,index;
    for(int i=0;i<size;i++)
    {
        if(arr[i]==element)
        {
            found=1;
            index=i;
            break;
        }
    else
    {
        found=0;
    }
    }
    if(found)
    {
        printf("Element found at position:%d",index);
    }
    else
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
    
   linear_search(A,size);
}