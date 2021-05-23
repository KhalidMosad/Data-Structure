#include<stdio.h>
#include<stdlib.h>
#include"SingleList_interface.h"

struct node {
double data;
struct node * link;
};

struct  node* start = NULL;
int k;
void createlist(int n)
{
    k= n;
    double dataV;
        for(int i=1;  i<=n; i++)
        {

            struct  node * tempNode = (struct  node*) malloc(sizeof(struct  node));
            struct  node * temp;

            if(tempNode == NULL)
                {
                    printf("Unable to allocate memory.");
                    break;
                }
            if (i==1)
            {
                start = tempNode;
                temp= start;
            }
            temp->link= tempNode; 
            printf("Please Enter data for  node %d: ", i);
            scanf("%lf", &dataV);        
            tempNode->data = dataV;
            temp =tempNode ;
            tempNode->link = NULL;
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
    tempN->link=start;
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
    while(temp->link!=NULL)
    {
        temp = temp->link;
    }
    temp->link = tempN;
    tempN->link = NULL;
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
        temp = temp->link;
        if(temp==NULL)
        {
            printf("Wrong Position \n");
            break;
        }
        i++;
    }
    if(temp != NULL)
    {
    tempN->link = temp->link;    
    temp->link = tempN;
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

    start = start->link;
    free(temp);
    temp= NULL;
    printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");

}
void deleteLastNode()
{
    struct node *toDelete, *secondLastNode;

    if(start == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = start;
        secondLastNode = start;

        /* Traverse to the last node of the list */
        while(toDelete->link != NULL)
        {
            secondLastNode = toDelete;
            toDelete = toDelete->link;
        }

        if(toDelete == start)
        {
            start = NULL;
        }
        else
        {
            /* Disconnect link of second last node with last node */
            secondLastNode->link = NULL;
        }

        /* Delete the last node */
        free(toDelete);

        printf("SUCCESSFULLY DELETED LAST NODE OF LIST\n");
    }
}

void deleteNodeAtMiddle(int position)
{
    int i;
    struct node *toDelete, *prevNode;

    if(start == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = start;
        prevNode = start;

        for(i=2; i<=position; i++)
        {
            prevNode = toDelete;
            toDelete = toDelete->link;

            if(toDelete == NULL)
                break;
        }

        if(toDelete != NULL)
        {
            if(toDelete == start)
                start = start->link;

            prevNode->link = toDelete->link;
            toDelete->link = NULL;

            /* Delete nth node */
            free(toDelete);

            printf("SUCCESSFULLY DELETED NODE FROM MIDDLE OF LIST\n");
        }
        else
        {
            printf("Invalid position unable to delete.");
        }
    }
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
        start = start->link;
        free(temp);
        temp = start;

    }
    
}
void deleteFirstByKey(int key)
{
    struct node *prev, *cur;

    /* Check if start node contains key */
    while (start != NULL && start->data == key)
    {
        // Get reference of start node
        prev = start;

        // Adjust start node link
        start = start->link;

        // Delete prev since it contains reference to start node
        free(prev);

        // No need to delete further
        return;
    }

    prev = NULL;
    cur  = start;

    /* For each node in the list */
    while (cur != NULL)
    {
        // Current node contains key
        if (cur->data == key)
        {
            // Adjust links for previous node
            if (prev != NULL) 
                prev->link = cur->link;

            // Delete current node
            free(cur);

            // No need to delete further
            return;
        } 

        prev = cur;
        cur = cur->link;
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
        temp = temp->link;
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
       
        next = start->link;
        start = start->link;
        prev->link = NULL;
        

        while(start !=NULL)
        {
            start = start->link;

            next->link = prev;
            prev = next;
            next = start;

        }

        start = prev;
        printf("SUCCESSFULLY REVERSED LIST\n");

    }


}


void traverselist(void)
{
    struct  node * temp ;
    if(start == NULL)
    {
        printf("List is empty.");
        return;
    }
    temp = start;
    int i=1;
    for(i=1; i<k+50; i++)
    {
         printf("The data in node %d = %lf \n ",i, temp->data );
        temp = temp->link; 
        if (temp == NULL)
        {
            break;
        }
    }

}