#include<stdio.h>
#include"tree.h"


void CreateTree(Tree *pt)
{
    *pt = NULL;
}
void CreateTree2(Tree2 *pt)
{
    pt->depth = 0;
    pt->root = NULL;
    pt->size = 0;

}


int TreeEmpty(Tree *pt)
{
    return (!*pt);
}

int TreeEmpty2(Tree2 *pt)
{
    return (!pt->root);
}

int TreeFull(Tree *pt)
{
    return 0;
}

int TreeFull2(Tree2 *pt)
{
    return 0;
}


void ClearTreeRec(Tree *pt)
{
    if(*pt)
    {
        ClearTreeRecAux(pt);
        *pt =NULL;
    }

}

void ClearTreeRec2(Tree2 *pt)
{
    ClearTreeRec(&pt->root);
    pt->size =0;
    pt->depth = 0;
}

void ClearTreeRecAux(Tree *pt)
{
    if(*pt)
    {
        ClearTreeRecAux(&(*pt)->left);
        ClearTreeRecAux(&(*pt)->right);
        free(*pt);
    }

}
int TreeSize(Tree2 *pt )
{
  return  pt->size;
}
int TreeDepth(Tree2 *pt)
{
   return pt->depth;
}

int TreeSizeRec(Tree *pt )
{
    if(!*pt)
        return 0;
    return (1+ TreeSizeRec(&(*pt)->left)+TreeSizeRec(&(*pt)->right));
}
int TreeDepthRec(Tree *pt)
{
    if(!*pt)
    return 0;
    int a= TreeDepthRec(&(*pt)->left);
    int b= TreeDepthRec(&(*pt)->right);
    return (a>b)? 1+a:1+b;
}
void InorderRec(Tree * pt, void(*pvisit)(TreeEntry))
{
    if(*pt)
    {
        InorderRec(&(*pt)->left, pvisit);
        (*pvisit)((*pt)->entry);
        InorderRec(&(*pt)->right, pvisit);
    }

}

void InorderRec2(Tree2 *pt, void(*pvisit)(TreeEntry))
{
    if(pt->root)
    {
        InorderRec(&pt->root, pvisit);
    }

}

void InsertTreeRec(Tree *pt, TreeEntry *pe )
{
    if(!*pt)
    {
        *pt = (Tree)malloc(sizeof(TreeNode));
        (*pt)->entry = *pe;
        (*pt)->left =NULL;
        (*pt)->right =NULL;
    }
    else if(LT(pe->key,(*pt)->entry.key))
        InsertTreeRec(&(*pt)->left, pe);
    else
        InsertTreeRec(&(*pt)->right, pe);    
}

void InsertTreeRecAux(Tree *pt, TreeEntry *pe, int *pdepth )
{
    if(!*pt)
    {
        *pt = (Tree)malloc(sizeof(TreeNode));
        (*pt)->entry = *pe;
        (*pt)->left =NULL;
        (*pt)->right =NULL;
    }
    else if(LT(pe->key,(*pt)->entry.key))
        InsertTreeRecAux(&(*pt)->left, pe, pdepth);
    else
        InsertTreeRecAux(&(*pt)->right, pe, pdepth);    

        (*pdepth)++;
}

void InsertTreeRec2(Tree2 *pt, TreeEntry *pe )
{
    int d=0;
    InsertTreeRecAux(&pt->root, pe, &d); 
    if (pt->depth <d)
        pt->depth =d;
    pt->size ++;

}

int FindItemTreeRec(Tree *pt, TreeEntry*pe, KeyType k)
{
    if(!pt)
        return 0;
    if(EQ((*pt)->entry.key,k))
    {
        *pe = (*pt)->entry;
        return 1;
    }
    if(LT(k,(*pt)->entry.key))
        return FindItemTreeRec(&(*pt)->left,pe,k);
    else
        return FindItemTreeRec(&(*pt)->right,pe,k);        
}

int FindItemTreeRec2(Tree2 *pt, TreeEntry*pe, KeyType k)
{
    return FindItemTreeRec(&pt->root,pe,k);
}

int DeleteItemTree(Tree *pt, TreeEntry *pe, KeyType k)
{
    int found =0;
    TreeNode *q= *pt, *r= NULL;

    while(q && !(found = EQ(k,q->entry.key)))
    {
        r= q;
        if(LT(k, q->entry.key))
            q=q->left;
        else
            q=q->right;
    }
    if(found)
    {
        *pe = q->entry;
        if(!r)
            DeleteNodeTree(pt);
        else if(LT(k, r->entry.key))
            DeleteNodeTree(&r->left);
        else
            DeleteNodeTree(&r->right);                    
    }

}


void DeleteNodeTree(Tree *pt)
{
    TreeNode *q= *pt, *r;
    if(!(*pt)->left)
        *pt = (*pt)->right;
    if(!(*pt)->right)
        *pt = (*pt)->left;   
    else {
        /* Ineffiecient solution
        *pt =(*pt)->right;
        for(r= q->right; r->left; r=r->left);
        r->left = q->left;
        */

       /* Effecient solution*/
        q= (*pt)->left;
        if(!q->right)
        {
            (*pt)->entry = q->entry;
            (*pt)->left = q->left;
        }
        else
        {
            do {
                r=q;
                q = q->right;
            }while ( q->right);
            (*pt)->entry = q->entry;
            r->right = q->left;          
        }
    }  
    free(q);   
}
void Preorder(Tree*, void(*)(TreeEntry));
void Postorder(Tree*, void(*)(TreeEntry));
