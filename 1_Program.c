#include<stdio.h>
int main()
{
    int size,i,arr[5];
    printf("Select the size of array:");
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("The elements of array are\n");
    for(i=0;i<size;i++)
    {
        printf("[%d]\n",arr[i]);
    }
    int choice;
    do{
        printf("Choose operation to perform\n Press 1. for insertion\n Press 2. for traversing\n Press 3. for deletion\n Press 4. for no operation\n");
        scanf("%d",&choice);
        switch (choice)
        {case 1:
        printf("Select the position for the element to be inserted\n");
        for(i=0;i<size;i++)
        {
            printf("[%d]\n",arr[i]);
        }
        int choice_1,element;
        scanf("%d",&choice_1);
        printf("Enter the element to be inserted:");
        scanf("%d",&element);
        size++;
        for(int i=size-1;i>=choice_1;i--)
        {
        	arr[i]=arr[i-1];
    	}
    	arr[choice_1]=element;
        for(int i=0;i<size;i++)
        	printf("[%d]\n",arr[i]);
        	break;
        case 2:
        printf("The array is\n");
        for(i=0;i<size;i++)
        {
            printf("[%d]\n", arr[i]);
        }
        break;
        case 3:
        {
            int choice_3;
        
        printf("Array is:\n");
        for(i=0;i<size;i++)
        {
            printf("[%d]\n", arr[i]);
        }
        printf("Enter the element to be deleted:");
        scanf("%d",&choice_3);
        if(choice_3 < 0 || choice_3 > size)
        {
            printf("Invalid position! Please enter position between 1 to %d", size);
        }
        else
        {
            for(i=choice_3-1; i<size-1; i++)
            {
                arr[i] = arr[i + 1];
            }
            size--;
            printf("\nElements of array after delete are:\n ");
            for(i=0; i<size; i++)
            {
                printf("[%d]\n", arr[i]);
            }
        }
        break;
        }
        defaut:
        printf("No operation is performed");
        break;
        }
    }
    while(choice!=4);
    return 0;
}
