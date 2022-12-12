#include<stdio.h>
int main()
{
    char a[20];
    int i,length=0;
    printf("Enter the string:");
    scanf("%s",&a);
    for(i=0;a[i]!='\0';i++)
    {
        length++;
    }
    printf("Length of String is: %d",i);
}