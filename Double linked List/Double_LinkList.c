#include<stdio.h>
#include<stdlib.h>
#include"DoubleList_interface.h"


struct  node* start = NULL;
struct  node* End = NULL;

void createlist(int n)
{
    double dataV;

        struct  node * temp = (struct  node*) malloc(sizeof(struct  node));
        start = temp;
        End = temp;

        if(temp == NULL)
        {
            printf("Unable to allocate memory.");
            exit(0);
        }
        printf("Please Enter data for  node 1: ");
        scanf("%lf", &dataV);

        temp->data= dataV;
        temp->Next = NULL;
        temp->Previous =NULL;

        for(int i=2;  i<=n; i++)
        {

            struct  node * tempNode = (struct  node*) malloc(sizeof(struct  node));
            if(tempNode == NULL)
                {
                    printf("Unable to allocate memory.");
                    break;
                }

            printf("Please Enter data for  node %d: ", i);
            scanf("%lf", &dataV);


            temp->Next= tempNode;
            tempNode->data = dataV;
            tempNode->Previous = temp;
            temp = temp->Next;
            tempNode->Next = NULL;
            End= tempNode;
        }
}
void insertNodeAtBeginning(int info)
{
    struct node* tempN = (struct node*)malloc(sizeof(struct node));
    if(tempN==NULL)
    {
        printf("Unable to allocate memory.");
         exit(0); 
    }

    
    tempN->data = info;
    tempN->Next=start;
    start->Previous = tempN;
    tempN->Previous= NULL;
    start = tempN;
    printf("DATA INSERTED SUCCESSFULLY\n");
}

void insertNodeAtEnd(int info)
{
    struct node* tempN = (struct node*)malloc(sizeof(struct node));
    struct node* temp= start;
    if(tempN==NULL)
    {
        printf("Unable to allocate memory.");
         exit(0); 
    }
    while(temp->Next!=NULL)
    {
        temp = temp->Next;
    }
    tempN->Previous = temp;
    temp->Next = tempN;
    tempN->Next = NULL;
    tempN->data = info;
     printf("DATA INSERTED SUCCESSFULLY\n");
}

void insertNodeAtMiddle(int info, int position)
{
    struct node* tempN = (struct node*)malloc(sizeof(struct node));
    struct node* temp= start;
    if(tempN==NULL)
    {
        printf("Unable to allocate memory.");
         exit(0); 
    }

    int i=1;
    while(i!= position )
    {
        temp = temp->Next;
        if(temp==NULL)
        {
            printf("Wrong Position \n");
            break;
        }
        i++;
    }
    if(temp != NULL)
    {
    tempN->Next = temp->Next;    
    temp->Next = tempN;
    tempN->data = info;
    printf("DATA INSERTED SUCCESSFULLY\n");    
    }

}

void deleteFirstNode(void)
{
    struct node* temp= start;
    if(start == NULL)
    {
        printf("List is already empty.");
    }

    start = start->Next;
    free(temp);
    temp= NULL;
    printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");

}

void deleteLastNode(void)
{
    struct node* temp= start;
    struct node* temp2;
    if(start == NULL)
    {
        printf("List is already empty.");
    }
    while(temp->Next->Next != NULL)
    {
        temp = temp ->Next;
    }
    temp2= temp;

    temp->Next = NULL;
    temp2 = temp2->Next;
    free(temp2);
    temp2 = NULL;
    printf("SUCCESSFULLY DELETED LAST NODE OF LIST\n");
}

void deleteNodeAtMiddle(int position)
{
    int i = 1;
    struct node* temp= start;
    struct node* temp2;

    if(start == NULL)
    {
        printf("List is already empty.");
    }

    if(position==1)
    {
        start = start->Next;
        free(temp);

    }
    else
    {
        while(i< position-1)
        {
        temp = temp->Next; 
            
            if (temp->Next==NULL)
            {
                    printf("Wrong Position \n");
                    break;

            }
            i++;
        }
        if(temp->Next!=NULL)
        {
            temp2 =temp;
            temp = temp->Next;
            temp2->Next = temp->Next;
            free(temp);
         
        }


    }

    printf("SUCCESSFULLY DELETED the required NODE OF LIST\n"); 

}

void deleteList(void)
{
    struct node* temp= start;
    struct node* temp2;

    if(start == NULL)
    {
        printf("List is already empty.");
    }
    while(start!= NULL)
    {
        start = start->Next;
        free(temp);
        temp = start;

    }
    
}

void deleteFirstByKey(int key)
{
    struct node* temp= start;
    struct node* temp2;

    if(start == NULL)
    {
        printf("List is already empty.");
    }
    
    if(start->data == key)
    {
        start = start->Next;
        free(temp);

    }
    else
    {
        while(temp->Next->data != key)
        {
            temp= temp->Next;
        }

        temp2 = temp;
        temp= temp->Next;
        temp2->Next = temp->Next;
        free(temp);

    }




}

int countNodes(void)
{
    int count = 0;
    struct node *temp;

    temp = start;

    while(temp != NULL)
    {
        count++;
        temp = temp->Next;
    }

    return count;
}

void reverseList(void)
{
    struct node* prev = start;
    struct node* next;

    if(start == NULL)
    {
        printf("List is already empty.");
    }
    if(start != NULL)
    {
       
        next = start->Next;
        start = start->Next;
        prev->Next = NULL;
        

        while(start !=NULL)
        {
            start = start->Next;

            next->Next = prev;
            prev = next;
            next = start;

        }

        start = prev;
        printf("SUCCESSFULLY REVERSED LIST\n");

    }


}

void traverselistFromFirst(void)
{
    struct  node * temp ;
    if(start == NULL)
    {
        printf("List is empty.");
        return;
    }


    temp = start;
    int i=1;
    
    while(temp != NULL)
    {

        printf("The data in node %d = %lf \n ",i, temp->data );

        temp = temp->Next;
         i++;
    }

}

void traverselistFromLast(void)
{
    struct  node * temp ;
    if(start == NULL)
    {
        printf("List is empty.");
        return;
    }


    temp = End;
    int i=1;
    
    while(temp != NULL)
    {

        printf("The data in node %d = %lf \n ",i, temp->data );

        temp = temp->Previous;
         i++;
    }
}


