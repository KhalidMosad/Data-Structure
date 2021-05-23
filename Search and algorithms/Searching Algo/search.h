typedef int KeyType; 
typedef int List; 

#define EQ(a,b) ((a)==(b))
#define LT(a,b) ((a)<(b))
#define LE(a,b) ((a)<=(b))
#define GT(a,b) ((a)>(b))
#define GE(a,b) ((a)>=(b))


#define EQST(a,b) (!strcmp((a),(b)))
#define LTST(a,b) (strcmp((a),(b))<0)
#define LEST(a,b) (strcmp((a),(b))<=0)
#define GTST(a,b) (strcmp((a),(b))>0)
#define GEST(a,b) (strcmp((a),(b))>=0)


typedef struct elementtype{
    KeyType key;   // KeyType will be either, int, float, char, or string
    int year;
    int etype;
    union{
        int year;
        float age;
    }info;
}ElementType;


int SequentialSearch(KeyType target, List *pl);
int RecBinary2Search(KeyType k, List * pl);
int Binary2Search(KeyType k, List * pl);

void InsertOrder(ListEntry e, List* pl);