
typedef int KeyType; 


typedef struct treeentry
{
   int key;
   
}TreeEntry;
 

typedef struct treenode{
    TreeEntry entry;
    struct treenode * left, *right ; 
}TreeNode;


typedef TreeNode * Tree;

typedef struct tree{
    TreeNode * root;
    int size;
    int depth;
}Tree2;


void CreateTree(Tree *);
void ClearTreeRec(Tree *);
void ClearTreeRec2(Tree2 *pt);
void InsertTreeRec(Tree *pt, TreeEntry *pe );
void InsertTreeRec2(Tree2 *pt, TreeEntry *pe );
int TreeSizeRec(Tree *pt );
int TreeDepthRec(Tree *pt);
int TreeSize(Tree2 *pt );
int TreeDepth(Tree2 *pt);

int FindItemTreeRec(Tree *pt, TreeEntry*pe, KeyType k);
int FindItemTreeRec2(Tree2 *pt, TreeEntry*pe, KeyType k);

int DeleteItemTree(Tree *pt, TreeEntry *pe, KeyType k);
void DeleteNodeTree(Tree *pt);

void InorderRec(Tree * pt, void(*pvisit)(TreeEntry));
void InorderRec2(Tree2 *pt, void(*pvisit)(TreeEntry));


void Preorder(Tree*, void(*)(TreeEntry));
void Inorder(Tree*, void(*)(TreeEntry));
void Postorder(Tree*, void(*)(TreeEntry));
