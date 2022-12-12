#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;
struct node *top=NULL;

void pop()
    {
    struct node *temp,*var=top;
    if(var==top)
    {
        top=top->next;
    }
    else
    {   printf("\n Underflow has occured");
        exit(0);
    }
    }
void push(int val)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    if(top==NULL)
    {
        top=temp;
        top->next=NULL;
    }
    else
    {
        temp->next=top;
        top=temp;
    }
}
void display()
{
    
    struct node *var=top;
    if(var!=NULL)
    {
        printf("\n Elements are: \n");
        while(var!=NULL)
        {
            printf("%d\n",var->data);
            var=var->next;
        }
        printf("\n");
    }
    else
    {
        printf("List is empty");
    }
}
 
 void main()
 {
    int value;
    int x;
    while(1)
    {printf("\nPress 1. For Push\nPress 2. For pop\nPress 3. To display\nPress 4. to end\n");
    scanf("%d",&x);
    
    switch(x)
    {
        case 1:
        {
            printf("\n Enter the value to be pushed:");
            scanf("%d",&value);
            push(value);
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            exit(0);
        }
    default:printf("\nwrong choice entered");
    }
 }
}