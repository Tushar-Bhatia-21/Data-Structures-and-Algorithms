#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node* getnode()
{
    struct node *t;
    t=(struct  node *)malloc(sizeof(struct node));
    return t;
}

void addfirst(struct node** start,int item)
{
    struct node *new;
    new =getnode();
    if(new==NULL)
    {
     
        printf("Overflow");
        
    }

    new->info=item;
    if((*start)->link==NULL)
    {
    (*start)->link=new;
    new->link=*start;
    }
    else
    {
    new->link=(*start)->link;
    (*start)->link=new;
    }
}

void append(struct node **start,int item)
{
    struct node* new,*ptr;
    new=getnode();
    if(new==NULL)
    {
        printf("\nOverflow\n");
        return;
    }
    new->info=item;
    if((*start)->link=NULL)
    {
        (*start)->link=new;
    }
    else
    {
        ptr=(*start)->link;
        while(ptr->link!=*start)
        ptr=ptr->link;
        ptr->link=new;
    }
    new->link=*start;
}

void traverse(struct node *start)
{
    struct node *ptr;
    ptr=start->link;
    while(ptr!=start)
    {
        printf("%d\t",ptr->info);
        ptr=ptr->link;
    }
}

void search(struct node* start, int item, struct node** loc,struct node** locp)
{
    struct node *save,*ptr;
    if(start->link==NULL)
    {
        *loc=*locp=NULL;
        return;
    }
    if(item==start->link->info)
    {
        *loc=start->link;
        *locp=NULL;
        return;
    }
    save=start->link;
    ptr=start->link->link;
    while(ptr!=start)
    {
        if(ptr->info==item)
        {
                *loc=ptr;
                *locp=save;
                return;
        }
        save=ptr;
        ptr=ptr->link;
    }
    *loc=*locp=NULL;
}

void delnode(struct node ** start,int item)
{
    struct node *loc,*locp;
    search(*start,item,&loc,&locp);
    if(loc==NULL)
    {
        printf("\nItem is not in the list\n");
    }
    else if(locp==NULL)
   {
        (*start)->link=(*start)->link->link;
   }
   else
   {
        locp->link=loc->link;
   }
}

void addafter(struct node** start, int item,int pos)
{
    struct node* new,*ptr;
    int i;
    for(i=1;i<pos;i++)
    {
        ptr=(*start)->link;
        if(ptr==*start)
        {
            printf("\nNode does not exist\n");
            return;
        }
        ptr=ptr->link;
    }
    new=getnode();
    if(new==NULL)
    {
        printf("\nOverflow\n");
        return;
    }
    new->info=item;
    new->link=ptr->link;
    ptr->link=new;
}

int main()
{
    struct node *p;
    int item,pos,cnt,ch;
    p=getnode();
    p->link=NULL;
    while(1)
    {
        printf("\nPress 1.For Addition at first\nPress 2. to Append\nPress 3. for add after a node\nPress 4. To delete\nPress 5. to traverse\nPress 6. to exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                printf("\nEnter a number:");
                scanf("%d",&item);
                addfirst(&p,item);
                break;
            }
            case 2:
            {
                printf("\nEnter a number:");
                scanf("%d",&item);
                append(&p,item);
                break;
            }
            case 3:
            {
                printf("\nEnter a number and pos: ");
                scanf("%d\n%d",&item,&pos);
                addafter(&p,item,pos);
                break;
            }
            case 4:
            {
                printf("\nEnter the item to be deleted: ");
                scanf("%d",&item);
                delnode(&p,item);
                break;
            }
            case 5:
            {
                traverse(p);
                break;
            }
            case 6:
            {
                exit(0);
            }
        }
    }
    return 0;
}