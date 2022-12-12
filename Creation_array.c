#include<stdio.h>
#include<stdlib.h>
void create(int*,int i);
create(int *arr,int i)
{
    int size,i;
    printf("Enter the size of array");
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
      scanf("%d",&arr[i]);
    }
    printf("The elements of array are:");
    for(i=0;i<size;i++)
    {
        printf("[%d]\t",arr[i]);
    }
  int main()
  {
    create(arr*,i);
  }  
}