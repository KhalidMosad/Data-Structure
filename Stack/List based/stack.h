
typedef int StackEntry; 
#define MAXSTACK  100

typedef struct stacknode
{ 
   StackEntry entry;
   struct stacknnode* next;
   
}StackNode;

typedef struct stack
{ 
   StackNode* top;
   int Size;
   
}Stack;

void CreateStack(Stack * ps);
void Push (StackEntry e, Stack * ps);
int StackFull(Stack *ps);
void Pop (StackEntry *pe, Stack * ps);
int StackEmpty(Stack *ps);
void StackTop (StackEntry *pe, Stack * ps);
int StackSize(Stack * ps);
void ClearStack(Stack * ps);
void TraverseStack(Stack* S, void (*ptf)(StackEntry));