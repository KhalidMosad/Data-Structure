#include<stdio.h>
#include"list.h"
void Display(ListEntry e)
{
    printf("The Value of the entry is =  %d \n", e);
}

void main()
{
    List l;
    ListEntry e;
    CreateList(&l);

    for(int i=0; i<5; i++)
    {
        scanf("%d",&e);
        if(!ListFull(&l))
            InsertList(i,e,&l);
    }
    TraverseList(&l,&Display);

}