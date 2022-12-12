#include <stdio.h>
#include<stdlib.h>
struct node 
{
   int data;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;


void printList() {
   struct node *ptr = head;
   printf("\n[ ");
	
    while(ptr != NULL) 
   {
     
      printf("(%d) ",ptr->data);
      ptr = ptr->next;
   }
	
   printf(" ]");
}
void insertFirst(int data) {

   struct node *link = (struct node*) malloc(sizeof(struct node));
	
   link->data = data;
	
   link->next = head;
	
   head = link;
}

void main() {
int a,b;
int size;
printf("Enter the number of elements:");
scanf("%d",&size);
printf("\nEnter the elements:\n");
for(int i=0;i<size;i++)
{
    scanf("%d",&a);
    insertFirst(a);
}
 
printf("List is:");
   printList();
}

