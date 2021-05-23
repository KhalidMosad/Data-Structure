#include<stdio.h>
#include<stdlib.h>
#include"list.h"


void CreateList(List *pl)
{
    pl->head = NULL;
    pl->size = 0;
    pl->currentpos=0;
    pl->current =NULL;
}
int ListEmpty(List *pl)
{
    return (pl->size==0) ;
}

int ListFull(List *pl)
{
    return 0 ;

}
int ListSize(List *pl)
{
    return pl->size ;

}
void DestroyList(List *pl)
{
   ListNode *q;
   while(pl->head)
   {
       q=pl->head->next;
       free(pl->head);
       pl->head = q;
   }  
   pl->size = 0;
}

int InsertList(int pos, ListEntry e, List *pl)
{
    ListNode *p;
   p=(ListNode *)malloc(sizeof(ListNode));
   p->entry=e;
   p->next=NULL;
   if (pos==0)
   {
        p->next=pl->head;
        pl->head=p;
        pl->currentpos=0; //new
        pl->current=pl->head; //new
   }
   else
   {//pl->current is used in place of q previously.
        if (pos<=pl->currentpos){
            pl->currentpos=0;//as i=0
            pl->current=pl->head;//as q=pl->head
        } //new.
        for(; pl->currentpos!=pos-1; pl->currentpos++)
            pl->current=pl->current->next;
        p->next=pl->current->next; 
        pl->current->next=p;
   }
   pl->size++;

}
void DeleteList(int pos, ListEntry *pe, List*pl)
{
   ListNode *tmp;
   if (pos==0){
	*pe=pl->head->entry;
	pl->current=pl->head->next;
	free(pl->head);
	pl->head=pl->current; //new 
	pl->currentpos=0; //new
   }
   else{
 	if (pos<=pl->currentpos){
		pl->currentpos=0;
		pl->current=pl->head;
	}
	for(; pl->currentpos!=pos-1; pl->currentpos++)
		pl->current=pl->current->next;
	*pe=pl->current->next->entry;
	tmp=pl->current->next->next;
	free(pl->current->next);
	pl->current->next=tmp;
   }
	pl->size--;

}
void TraverseList(List *pl, void(*Visit)(ListEntry))
{
    ListNode * p= pl->head;
    while(p)
    {
        (*Visit)(p->entry);
        p = p->next;
    }

}

void RetrieveList(int pos, ListEntry *pe, List *pl)
{
    // هنا انت عاوز فقط القيمه الي فالمكان دا من غير ما تغيرة ولا تشيله 
   int i;
   ListNode * q = pl->head;
    for(i=0; i<pos; pos++)
    {
        q= q->next;
    }
    *pe= q->entry;


}
void ReplaceList(int pos, ListEntry e, List *pl)
{
   int i;
   ListNode * q = pl->head;
    for(i=0; i<pos; pos++)
    {
        q= q->next;
    }
    q->entry= e;


}
