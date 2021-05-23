#include<stdio.h>
#include"tree.h"

void Display(TreeEntry t)
{
    printf("This is The Value of T %d", t);
}

void main(void)
{

    Tree t;
    Tree2 t2;
    InorderRec(&t, &Display);
    InorderRec2(&t2, &Display);

    ClearTreeRec(&t);

    TreeEntry e;
    InsertTreeRec(&t ,&e);
}