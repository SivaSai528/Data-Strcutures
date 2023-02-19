#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * nextptr;
}*firstnode;
 

void ClListcreation(int length);
void displayClList();

int main()
{
    int length;
    firstnode = NULL;
	printf("\n\n Circular Linked List : Create and display a circular linked list :\n");
	printf("-----------------------------------------------------------------------\n");	   	

    printf(" Input the number of nodes : ");
    scanf("%d", &length);
 
    ClListcreation(length); 
    displayClList();
    return 0;
}

void ClListcreation(int length)
{
    int  data,i;
    struct node *temp, *newnode;

    if(length >= 1)
    {
    int value;
    for(int i=1;i<=length;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter Element\n");
		scanf("%d",&value);
        
        newnode->nextptr= NULL;
        newnode->data=value;
        if(firstnode==NULL)
            firstnode=newnode;
        else{
            temp->nextptr=newnode;
        }
        temp=newnode;
    }
        temp->nextptr = firstnode; 		//last node is linking with first node
    }
}

void displayClList()
{
    struct node *node;
    int n = 1;
        node = firstnode;
        printf("\n\n Data entered in the list are :\n");
        do 
        {
            printf(" Data %d = %d\n", n, node->data);

            node = node->nextptr;
            n++;
        }while(node != firstnode);
    
}