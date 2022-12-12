#include<stdio.h>
int main()
{
    int arr[10],lar_el=0,Second_lar_el=0;
    int size,i;
    printf("Enter the size of array:");
    scanf("%d",&size);
    printf("Enter the array elements:\n");
    for(i=0;i<size;i++)
    {
    scanf("%d",&arr[i]);
    }
for(i=0;i<size;i++)
{
   if(lar_el<arr[i])
   {
    Second_lar_el=lar_el;
    lar_el=arr[i];
   }
   else if(Second_lar_el<arr[i])
   {
    Second_lar_el=arr[i];
   }
}
printf("The largest element is:%d\nSecond Largest element is:%d",lar_el,Second_lar_el);
}