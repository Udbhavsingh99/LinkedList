//A linked list is called circular if it is not NULL-terminated and all nodes are connected in the form of a cycle.
/*Logic 
The idea is to store head of the linked list and traverse it. If we reach NULL, linked list is not circular. If reach head again, linked list is circular. */

#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
};

/* This function returns true if given linked
   list is circular, else false. */
bool isCircular(node *head)
{
    // An empty linked list is circular
    if (head == NULL)
    return true;
    // Next of head
    node *node = head->next;
    // This loop would stop in both cases (1) If
    // Circular (2) Not circular
    while (node != NULL && node != head)
    node = node->next;
    // If loop stopped because of circular
    // condition
    return (node == head);
}