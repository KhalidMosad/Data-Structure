
#define MAXLIST         50
typedef  int ListEntry ;

typedef struct list
{
    ListEntry entry[MAXLIST];
    int size;
}List;

void CreateList(List *pl);
int ListEmpty(List *pl);
int ListFull(List *pl);
int ListSize(List *pl);
void DestroyList(List *pl);
void InsertList(int p, ListEntry e, List *pl);
void DeleteList(int p, ListEntry *pe, List*pl);
void TraverseList(List *pl, void(*Visit)(ListEntry));
void RetrieveList(int p, ListEntry *pe, List *pl);
void ReplaceList(int p, ListEntry e, List *pl);