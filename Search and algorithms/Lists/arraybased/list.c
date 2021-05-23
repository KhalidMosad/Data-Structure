#include<stdio.h>
#include"list.h"


void CreateList(List *pl)
{
    pl->size = 0;
}
int ListEmpty(List *pl)
{
    return !pl->size ;
}

int ListFull(List *pl)
{
    return (pl->size== MAXLIST) ;

}
int ListSize(List *pl)
{
    return pl->size ;

}
void DestroyList(List *pl)
{
    pl->size = 0;    
}
void InsertList(int p, ListEntry e, List *pl)
{
    int i;
    if (p<= MAXLIST-1)
    {
        for(i=pl->size-1; i>=p; i--)
            pl->entry[i+1]= pl->entry[i];
        pl->entry[p]= e;
        pl->size++;
    }


}
void DeleteList(int p, ListEntry *pe, List*pl)
{
    int i;
    *pe = pl->entry[p];
    for(i=p; i<=pl->size-1; i++)
        pl->entry[i]= pl->entry[i+1];    
    pl->size--;
}
void TraverseList(List *pl, void(*Visit)(ListEntry))
{
    int i=0;
    while(i < pl->size)
    {
        (*Visit)(pl->entry[i]);
        i++ ;
    }

}
void RetrieveList(int p, ListEntry *pe, List *pl)
{
    // هنا انت عاوز فقط القيمه الي فالمكان دا من غير ما تغيرة ولا تشيله 
    *pe = pl->entry[p];


}
void ReplaceList(int p, ListEntry e, List *pl)
{

    pl->entry[p]=e;

}
