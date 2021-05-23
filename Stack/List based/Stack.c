#include<stdio.h>
#include<stdlib.h>
#include"stack.h"


void CreateStack(Stack * ps)
{
    ps->top = NULL;
    ps->Size = 0;
}

void Push (StackEntry e, Stack * ps)
{   
    StackNode *pn = (StackNode*)malloc(sizeof(StackNode));
    pn->entry = e;
    pn->next =  ps->top;
    ps->top = pn;  
    ps->Size++;
}

int StackFull(Stack *ps)
{
        return 0;
}

void Pop (StackEntry * pe, Stack * ps)
{
    StackNode * temp = ps->top;
    *pe = ps->top->entry;
    ps->top = ps->top->next;
    free(temp);
    temp = NULL;
     ps->Size--;
}
int StackEmpty(Stack *ps)
{
    if(ps->top == NULL)
        return 1 ;
    else
        return 0;
// or return ps->top == NULL
}


void StackTop (StackEntry *pe, Stack * ps)
{
    *pe = ps->top->entry;
}

int StackSize(Stack * ps)
{
    StackNode* pn= ps->top;
    int x=0;
    while(pn != NULL)
    {
        x++;
        pn = pn->next;
    }
    return x;   
}

void ClearStack(Stack * ps)
{
    StackNode* pn= ps->top;
    while(ps->top != NULL)
    {
        ps->top = ps->top->next;
        free(pn);
        pn = ps->top;

    }
    pn = NULL;
    ps->top =NULL;
    ps->Size = 0;
}

void TraverseStack(Stack*ps, void (*ptf)(StackEntry))
{
    StackNode * pn = ps->top ;
    while(pn != NULL)
    {
        (*ptf)(pn->entry);
        pn = pn->next;
    }
}