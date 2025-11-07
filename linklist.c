#include <stdio.h>
#include <stdlib.h>


void insertstart();
void delstart();
void display();

struct linklist
{
    int num;
    struct linklist *next;
};
struct linklist *ptr,*head,*start,*ptr1,*temp;
void main()
{
    int choice;
    head=(struct linklist*)malloc(sizeof(struct linklist));
    printf("enter the value\n");
    scanf("%d",&head->num);
    head->next=NULL;
    do
    {
        printf("\n1. insertion at beginning");
        printf("\n2. deletion at beginning");
        printf("\n3. display");
        printf("\n4. exit");
       
        printf("\n enter choice");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:insertstart();
            break;
            case 2:delstart();
            break;
            case 3:display();
            break;
            
        }
    }
    while(choice!=4);

}

void insertstart()
{
    temp=(struct linklist*)malloc(sizeof(struct linklist));
    printf("\nenter the value");
    scanf("%d",&temp->num);
    temp->next=head;
    head=temp;
}

void delstart()
{
    ptr=head;
    head=head->next;
    printf("\nthe deleted node is %d",ptr->num);
    ptr=NULL;
}

void display()
{
    ptr=head;
    printf("link list is :\n");
    while(ptr!=NULL)
    {
        printf("%d",ptr->num);
        ptr=ptr->next;
}
}




