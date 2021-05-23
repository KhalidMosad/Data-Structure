#include<stdio.h>
#include "search.h"


int SequentialSearch(KeyType target, List *pl)
{
    int current, s= ListSize(pl);
    ListEntry currententry;

    for(current=0; current<s; current++)
    {
        RetrieveList(current, &currententry, pl);
        if(EQ(target , currententry.key))
            return current;
    }
    return -1;

}

int RecBinary2(List* pl, KeyType k, int bottom, int top)
{
    int middle;
    if(bottom<= top)
    {
        middle = (bottom + top)/2;
        if(EQ(k, pl->entry[middle].key))
            return middle ;
        if (LT(k, pl->entry[middle].key))
            return RecBinary2(pl, k, bottom, middle-1);
        else
            return RecBinary2(pl, k, middle+1, top);
    }
    return -1;
}

int RecBinary2Search(KeyType k, List * pl)
{
    return RecBinary2(pl, k, 0, pl->size-1);
}

int Binary2Search(KeyType k, List * pl)
{
    int middle, bottom =0, top = pl->size-1;
    while(bottom<= top)
    {
        middle = (bottom + top)/2;
        if(EQ(k, pl->entry[middle].key))
            return middle ;
        if (LT(k, pl->entry[middle].key))
           top= middle-1;
        else
            bottom= middle+1;
    }
    return -1;
}

void InsertOrder(ListEntry e, List* pl)
{
    int current, s= ListSize(pl);
    ListEntry currententry;
    for(current=0; current<s; current++)
    {
        RetrieveList(current, &currententry, pl);
        if(LE(e.key , currententry.key))
            break;
    }
    InsertList(current, e, pl);
}