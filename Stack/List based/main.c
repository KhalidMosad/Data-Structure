#include<stdio.h>
#include"stack.h"

void Display(StackEntry e)
{
    printf("e is: %d \n",e);
}

void main()
{
    Stack s;
    StackEntry  e;
    int size;
    CreateStack(&s);
    scanf("%d",&e);
    if(!StackFull(&s))
        Push(e, &s);
    // if (!StackEmbty(&s))
    //     Pop (&e, &s);

    // StackTop(&e, &s);
    // size = StackSize(&s);

    TraverseStack(&s, &Display);

}


