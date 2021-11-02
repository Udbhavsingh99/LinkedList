/*Allocate memory for the newly inserted node and put data in the newly allocated node. Let the pointer to the new node be new_node. After memory allocation, following are the three cases that need to be handled.  

1) Linked List is empty:  
    a)since new_node is the only node in CLL, make a self loop.      
        new_node->next = new_node;  
    b) change the head pointer to point to new node.
          *head_ref = new_node;
2) New node is to be inserted just before the head node:    
(a) Find out the last node using a loop.
         while(current->next != *head_ref)
            current = current->next;
(b) Change the next of last node. 
        current->next = new_node;
(c) Change next of new node to point to head.
         new_node->next = *head_ref;
(d) change the head pointer to point to new node.
         *head_ref = new_node;
3) New node is to be  inserted somewhere after the head: 
(a) Locate the node after which new node is to be inserted.
         while ( current->next!= *head_ref && 
            current->next->data data)
        {   current = current->next;   }
(b) Make next of new_node as next of the located pointer
        new_node->next = current->next;
(c) Change the next of the located pointer
        current->next = new_node;*/

#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
};
/* function to insert a new_node in a list in sorted way.
Note that this function expects a pointer to head node
as this can modify the head of the input linked list */
void sortedInsert(node** head_ref, node* new_node)
{
    node* current = *head_ref;
    // Case 1 of the above algo
    if (current == NULL)
    {
        new_node->next = new_node;
        *head_ref = new_node;
    }
    // Case 2 of the above algo
    else if (current->data >= new_node->data)
    {
        /* If value is smaller than head's value then
        we need to change next of last node */
        while(current->next != *head_ref)
            current = current->next;
        current->next = new_node;
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    // Case 3 of the above algo
    else
    {
        /* Locate the node before the point of insertion */
        while (current->next!= *head_ref &&
            current->next->data < new_node->data)
        current = current->next;
        new_node->next = current->next;
        current->next = new_node;
    }
}

//Optimization 
/*The else if part can be modified*/
/*else if (current->data >= new_node->data)
{
  // swap the data part of head node and new node
  // assuming that we have a function swap(int *, int *)
swap(&(current->data), &(new_node->data));
new_node->next = (*head_ref)->next;
(*head_ref)->next = new_node;
}*/