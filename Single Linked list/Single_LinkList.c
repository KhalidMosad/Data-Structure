#include<stdio.h>
#include<stdlib.h>
#include"SingleList_interface.h"

struct node {
double data;
struct node * link;
};

struct  node* start = NULL;

void createlist(int n)
{
    double dataV;

        struct  node * temp = (struct  node*) malloc(sizeof(struct  node));
        start = temp;


        if(temp == NULL)
        {
            printf("Unable to allocate memory.");
            exit(0);
        }
        printf("Please Enter data for  node 1: ");
        scanf("%lf", &dataV);

        temp->data= dataV;
        temp->link = NULL;

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


            temp->link= tempNode;
            tempNode->data = dataV;
            temp = temp->link;
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

void deleteLastNode(void)
{
    struct node* temp= start;
    struct node* temp2;
    if(start == NULL)
    {
        printf("List is already empty.");
    }
    while(temp->link->link != NULL)
    {
        temp = temp ->link;
    }
    temp2= temp;

    temp->link = NULL;
    temp2 = temp2->link;
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
        start = start->link;
        free(temp);

    }
    else
    {
        while(i< position-1)
        {
        temp = temp->link; 
            
            if (temp->link==NULL)
            {
                    printf("Wrong Position \n");
                    break;

            }
            i++;
        }
        if(temp->link!=NULL)
        {
            temp2 =temp;
            temp = temp->link;
            temp2->link = temp->link;
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
        start = start->link;
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
        start = start->link;
        free(temp);

    }
    else
    {
        while(temp->link->data != key)
        {
            temp= temp->link;
        }

        temp2 = temp;
        temp= temp->link;
        temp2->link = temp->link;
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
            next =start;
           

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
    
    while(temp != NULL)
    {

        printf("The data in node %d = %lf \n ",i, temp->data );

        temp = temp->link;
         i++;
    }
    // for(i=1; i<10; i++)
    // {
    //      printf("The data in node %d = %lf \n ",i, temp->data );
    //     temp = temp->link; 
    //     if (temp == NULL)
    //     {
    //         break;
    //     }
    // }

}


