#include<stdio.h>

void swap(int *a, int*b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void Selection_sort(int arr[],int size)
{
    for (int step = 0; step < size - 1; step++) 
    {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) 
        {
        if (arr[i] < arr[min_idx])
            min_idx = i;
        }
        swap(&arr[min_idx], &arr[step]);
  }
}

void print_array(int arr[],int size)
{
    for(int i=0;i<size;++i)
    {
        printf("%d ",arr[i]);
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
    print_array(data,size);
    
    Selection_sort(data,size);

    printf("\nElements after sorting are: ");
    print_array(data,size);
    return 0;
}
