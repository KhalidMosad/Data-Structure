#include<stdio.h>
#include"stack.h"

void CreateStack(Stack * ps)
{
    ps->top = 0;
    //*ps. top = 0;
}

void Push (StackEntry e, Stack * ps)
{

    ps-> entry[ps->top]= e;
    ps->top++ ; 
    // or 
    //ps-> entry[ps->top++]= e;
}


int Push1 (StackEntry e, Stack * ps)
{

    if (ps->top == MAXSTACK)
    {
        printf("STACK IS FULL");
        return 0;        
    }
    else
    {
        ps-> entry[ps->top]= e;
        ps->top++ ; 
    // or 
    //ps-> entry[ps->top++]= e;     
        return 1;   
    }
        

}
int StackFull(Stack *ps)
{
    if(ps->top == MAXSTACK)
        return 1 ;
    else
        return 0;
     // or  
     // return ps->top>= MAXSTACK
}

void Pop (StackEntry * pe, Stack * ps)
{
    ps->top-- ;
    *pe = ps->entry[ps->top];
    //*pe = ps->entry[--ps->top];
}
int StackEmpty(Stack *ps)
{
    if(ps->top == 0)
        return 1 ;
    else
        return 0;
     // or  
     // return !ps->top
}

void StackTop (StackEntry *pe, Stack * ps)
{
    ps->top-- ;
    *pe = ps->entry[ps->top];
    ps->top++;

    // or  *pe = ps->entry[ps->top-1];

}
int StackSize(Stack * ps)
{
    return ps->top ;
}

void ClearStack(Stack * ps)
{
    ps->top = 0;
}

void TraverseStack(Stack*ps, void (*ptf)(StackEntry))
{
    while(ps->top != 0)
    {
        (*ptf)(ps->entry[--ps->top]);
    }

}