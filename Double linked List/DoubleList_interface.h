struct node {
double data;
struct node * Next;
struct node * Previous;
};



void createlist(int n);
void insertNodeAtBeginning(int info);
void insertNodeAtEnd(int info);
///void insertNodeAtMiddle(int info, int position);
///void deleteFirstNode(void);
///void deleteLastNode(void);
///void deleteNodeAtMiddle(int position);
void deleteList(void);
///void deleteFirstByKey(int key);
///int countNodes(void);
void traverselistFromFirst(void);
void traverselistFromLast(void);