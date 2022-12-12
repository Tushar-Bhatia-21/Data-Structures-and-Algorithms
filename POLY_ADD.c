#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
	int coeff,pow;
	struct node*link;
};
void append(struct node**,int,int);
struct node *getnode();
void add_poly(struct node*,struct node*,struct node**);
void traverse(struct node*);
int main()
{
	int n1,n2,i,c,p;
	struct node *l1,*l2,*l3;
	l1=l2=l3=NULL;
	printf("enter number of terms in first equation: ");
	scanf("%d",&n1);
	for(i=0;i<n1;i++)
	{
		printf("\nEnter coeff of x: ");
		scanf("%d",&c);
        printf("\nEnter power of x: ");
		scanf("%d",&p);
		append(&l1,c,p);
	}
	printf("enter number of nodes in second equation: ");
	scanf("%d",&n2);
	for(i=0;i<n2;i++)
	{
		printf("\nEnter coeff of x: ");
		scanf("%d",&c);
        printf("\nEnter power of x: ");
		scanf("%d",&p);
		append(&l2,c,p);
	}
	printf("\nfirst equation is \n");
	traverse(l1);
	printf("\nsecond equation is \n");
	traverse(l2);
	add_poly(l1,l2,&l3);
	printf("\nthird equation is \n");
	traverse(l3);
}
void append(struct node ** start,int c,int p)
{
	struct node* new,*ptr;
	new=getnode();
	if(new==NULL)
	{
		printf("overflow");
		return;
	}
	new->coeff=c;
	new->pow=p;
	new->link=NULL;
	if(*start==NULL)
		*start=new;
	else
	{
		ptr=*start;
		while(ptr->link!=NULL)
			ptr=ptr->link;
		ptr->link=new;	
	}	
}
struct node*getnode()
{
	struct node*t;
	t=(struct node *)malloc(sizeof(struct node));
	return(t);
}
void traverse(struct node*start)
{
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		if(ptr->coeff>0)
			printf("+%dx^%d",ptr->coeff,ptr->pow);
		else
			printf("-%dx^%d",abs(ptr->coeff),ptr->pow);	
		ptr=ptr->link;	
	}
}
void add_poly(struct node *l1,struct node *l2,struct node **l3)
{
	while(l1!=NULL&&l2!=NULL)
	{
		if(l1->pow==l2->pow)
		{
			append(l3,l1->coeff+l2->coeff,l1->pow);
			l1=l1->link;
			l2=l2->link;
		}
		else if(l1->pow>l2->pow)
		{
			append(l3,l1->coeff,l1->pow);
			l1=l1->link;
		}
		else
		{
			append(l3,l2->coeff,l2->pow);
			l2=l2->link;
			
		}
	}
	while(l1!=NULL)
	{
		append(l3,l1->coeff,l1->pow);
		l1=l1->link;
	}
	while(l2!=NULL)
	{
		append(l3,l2->coeff,l2->pow);
		l2=l2->link;
	}
}