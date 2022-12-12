#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next,*prev;
};

struct node *head = NULL;

void create_list(int val)
{
    struct node *newnode, *p;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val; 
    newnode->next = NULL;

    
    if(head == NULL) 
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        p = head;
        while(p->next != head) 
        {
            p = p->next;
        }
        p->next = newnode;
        newnode->next = head;
        
    }
}

void printlist()
{
    struct node *p = head;
    if (head == NULL) printf("\nList is empty\n");
    else
    {
        do
        {
            printf("%d ",p->data);
            p = p->next;
        }
        while (p != head);
        
    }
}

void insertbeg(int val)
{
    struct node *newnode1,*p;
    newnode1 = (struct node*)malloc(sizeof(struct node));
    newnode1->data = val;
    newnode1->next = NULL;
    if(newnode1==NULL)
    {
        printf("\nOverflow");
    }
    
    if(head==NULL)
    {
        head=newnode1;
        newnode1->next=head;
        newnode1->prev=head;
    }
    else
    {
    p=head;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = newnode1;
    newnode1->prev=p;
    head->prev=newnode1;
    newnode1->next=head;
    head = newnode1;
    }
}

void insertend(int val)
{
    struct node *newnode2, *p;
    newnode2 = (struct node*)malloc(sizeof(struct node));
    newnode2->data = val;
    newnode2->next = NULL;
    if(newnode2==NULL)
    {
        printf("\nOverflow");
    }
    else
{
    if(head==NULL)
    {
        head=newnode2;
        newnode2->next=NULL;
        newnode2->prev=NULL;
    }
    else
    {
    p=head;
    while(p->next != head) 
    {
        p = p->next;
    }
    p->next=newnode2;
    newnode2->prev=p;
    head->prev=newnode2;
    newnode2->next=head;
    }
}
}

void delpos(int pos)
{
    struct node *p;
    p = head;
    if (head == NULL)
    {
        printf("List underflow!");
        return;
    }
    else 
    {
        if (p->next == NULL &&p->prev==NULL && pos == 1)
        {
            head = NULL;
            return;
        }
        else
        {
            for (int i=0; i<pos-2; i++)
            {
                p = p->next;
            }
            p->next = p->next->next;
            p->prev=p->prev->prev;
        }
    }
}

void srchelement(int srchele)
{
    struct node *p;
    int found = 0;
    p = head;
    if(p==NULL)
    {
        printf("\nEmpty list\n");
    }
    else
    {
        do
        {
            if (p->data == srchele)
            {
                found = 1;
            }
            p = p->next;
        }
        while (p != head);
        if (found)
        {
            printf("Element found!");
        }
        else 
        {
            printf("Element not found!");
        }
    }
}

int main()
{
    int n;
    int ele;
    int choice = 0;
    int newele1;
    int newele2;
    int pos;
    int srchele;
    printf("Enter number of nodes to create a list: ");
    scanf("%d",&n);
        for (int i=0; i<n ; i++)
        {
            printf("Enter elements: ");
            scanf("%d",&ele);
            create_list(ele);
        }
        while (choice < 6)
        {
            printf("\nEnter choice for\nInsertion at beginning(1)\nInsertion at end(2)\nDeletion at any point(3)\nSearching(4)\nDisplay(5)\nExit(6)\nEnter choice: ");
            scanf("%d",&choice);
            switch (choice)
            {
                case 1: printf("Enter element: ");
                        scanf("%d",&newele1);
                        create_list(newele1);
                        break;

                case 2: printf("Enter element: ");
                        scanf("%d",&newele2);
                        insertend(newele2);
                        break;

                case 3: printf("Enter position: ");
                        scanf("%d",&pos);
                        delpos(pos);
                        break;

                case 4: printf("Enter element to search: ");
                        scanf("%d",&srchele);
                        srchelement(srchele);
                        break;

                case 5: printlist();
                        break;

                case 6: break;

                default: printf("Invalid Choice!");
            }
        }
    
    return 0;
}