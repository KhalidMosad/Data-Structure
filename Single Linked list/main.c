#include<stdio.h>
#include<stdlib.h>
#include"SingleList_interface.h"

void main(void)
{
int k ;
int data;
int position;
int key;
printf("Please Enter the number of Nodes: ");
scanf("%d", &k);
createlist(k);
traverselist();

// printf("\nEnter data to insert at beginning of the list: ");
// scanf("%d", &data);
// insertNodeAtBeginning(data);
// traverselist();

// printf("\nEnter data to insert at End of the list: ");
// scanf("%d", &data);
// insertNodeAtEnd(data);
// traverselist();

// printf("nEnter data to insert at middle of the list: ");
// scanf("%d", &data);
// printf("Enter the position to insert new node: " );
// scanf("%d", &position);
// insertNodeAtMiddle(data, position);
// traverselist();

// deleteFirstNode();
// deleteLastNode();
// traverselist();
// printf("Enter the position to delete: " );
// scanf("%d", &position);
// deleteNodeAtMiddle(position);

// deleteList();
// printf("Enter the Key to delete: " );
// scanf("%d", &key);
// deleteFirstByKey(key);


reverseList();

printf("Reversed list: \n \n");
traverselist();


}