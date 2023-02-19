#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
}*firstnode;

void PrintList(struct node* node);
void Creation(int Length);
void InsertatBegin(int newData);

int main()
{
    int Length,i,newData;
    printf("\n\n Linked List : Insert a new node at the beginning of a Linked List :\n");
	printf("-------------------------------------------------------------\n");
    printf(" Input the Length of nodes : ");
    scanf("%d", &Length);
    Creation(Length);
    printf("\n Data entered in the list : \n");
    PrintList(firstnode);
    printf ("\n Enter  the New Data : ");
    scanf("%d",&newData);
    InsertatBegin(newData);
    printf("\n The New List are : \n");
    PrintList(firstnode);
    return 0;
}
void Creation(int Length)
{
    struct node *temp,*newnode;
	int data,i;
	firstnode = (struct node *)malloc(sizeof(struct node));
	printf(" Input data for node 1 : ");
    scanf("%d", &data);
    firstnode->data= data;
    firstnode->next = NULL; // links the address field to NULL
    temp=firstnode;
    for (i=2;i<=Length;i++)
    {
    	newnode=(struct node *)malloc(sizeof(struct node));
    	printf(" Input data for node %d : ",i);
    	scanf("%d",&data);
    	newnode->data=data;
    	newnode->next=NULL;
    	temp->next=newnode;
    	temp=temp->next;
    }

}

void PrintList(struct node* node) 
{
    int j;
    j=1;
    while (node != NULL) 
    {
        printf(" Data of %d Node = %d\n",j++, node->data);
        node = node->next;
    }
}
void InsertatBegin(int newData)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = newData; //Links the data part
    newnode->next = firstnode; //Links the address part
    firstnode = newnode; //Makes firstnode as first node
    
}