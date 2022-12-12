#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
	int coeff,pow;
	struct node*link;
};
void insert(struct node**,int,int);
struct node *getnode();
struct node * mult_list(struct node*,struct node*);
void traverse(struct node*);
int main()
{
	int c,p,n,i;
	struct node *l1,*l2,*l3;
	l1=l2=l3=NULL;
	printf("enter number of terms in first equation: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter coefficient of x: ");
		scanf("%d",&c);
        printf("Enter power of x: ");
		scanf("%d",&p);
		insert(&l1,c,p);
	}
	printf("enter number of nodes in second equation: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter coefficient of x: ");
		scanf("%d",&c);
        printf("Enter power of x: ");
		scanf("%d",&p);
		insert(&l2,c,p);
	}
	printf("\nfirst equation is \n");
	traverse(l1);
	printf("\nsecond equation is \n");
	traverse(l2);
	l3=mult_list(l1,l2);
	printf("\nthird equation is \n");
	traverse(l3);
}
struct node*getnode()
{
	struct node*t;
	t=(struct node *)malloc(sizeof(struct node));
	return(t);
}
void traverse(struct node*p)
{
	while(p!=NULL)
	{
		if(p->coeff>=0)
			printf("+%dx^%d",p->coeff,p->pow);
		else
			printf("%dx%d",p->coeff,p->pow);	
		p=p->link;	
	}
}
void insert(struct node ** p,int c,int pow)
{
	struct node *t,*q;
	q=*p;
	if(q==NULL)
	{
		t=getnode();
		t->coeff=c;
		t->pow=pow;
		t->link=NULL;
		*p=t;
	}
	else
	{
        while(q->link!=NULL&&q->pow!=pow)
	        q=q->link;
	    if(q->pow==pow)
	        q->coeff=q->coeff+c;
        else 
        {
            t=getnode();
            t->coeff=c;
            t->pow=pow;
            t->link=q->link;
            q->link=t;
        }
	}	
}
struct node * mult_list(struct node *l1,struct node *l2)
{
    struct node *p1,*p2,*p3;
    int coeff,pow;
    if(l1==NULL)
        return l2;
    if(l2==NULL)
        return l1; 
    p3=NULL;
    p1=l1;
    while(p1!=NULL)
    {
        p2=l2;
        while(p2!=NULL)
        {
            coeff=p1->coeff * p2->coeff;
            pow=p1->pow+p2->pow;
            insert(&p3,coeff,pow);
            p2=p2->link;
        }
        p1=p1->link;
    }
    return(p3);
}