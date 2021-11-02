#include<iostream>

using namespace std;

class node
{
    public:
    node* next;
    int data;
};

/*Traverse the list till last node. Use two pointers: one to store the address of last node and other for address of second last node. After the end of loop do following operations.
i) Make second last as last (secLast->next = NULL).
ii) Set next of last as head (last->next = *head_ref).
iii) Make last as head ( *head_ref = last)*/

/* We are using a double pointer
head_ref here because we change 
head of the linked list inside 
this function.*/
void moveToFront(node **head_ref) 
{ 
    /* If linked list is empty, or 
    it contains only one node, 
    then nothing needs to be done,
    simply return */
    if (*head_ref == NULL || (*head_ref)->next == NULL) 
        return; 
    /* Initialize second last
    and last pointers */
    node *secLast = NULL; 
    node *last = *head_ref; 
    /*After this loop secLast contains
    address of second last node and 
    last contains address of last node in Linked List */
    while (last->next != NULL) 
    { 
        secLast = last; 
        last = last->next; 
    } 
    /* Set the next of second last as NULL */
    secLast->next = NULL; 
    /* Set next of last as head node */
    last->next = *head_ref; 
    /* Change the head pointer
    to point to last node now */
    *head_ref = last; 
} 