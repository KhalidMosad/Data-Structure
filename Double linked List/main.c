#include<stdio.h>
#include<stdlib.h>
#include"DoubleList_interface.h"

void main(void)
{
int k ;
int data;
int position;
int key;
printf("Please Enter the number of Nodes: ");
scanf("%d", &k);
createlist(k);
traverselistFromFirst();
traverselistFromLast();

}