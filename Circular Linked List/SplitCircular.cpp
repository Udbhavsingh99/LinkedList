/*1) Store the mid and last pointers of the circular linked list using tortoise and hare algorithm. 
2) Make the second half circular. 
3) Make the first half circular. 
4) Set head (or start) pointers of the two linked lists.
In the below implementation, if there are odd nodes in the given circular linked list then the first result list has 1 more node than the second result list. */

#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
};

/* Function to split a list (starting with head)
into two lists. head1_ref and head2_ref are
references to head nodes of the two resultant
linked lists */
void splitList(node *head, node **head1_ref, node **head2_ref)
{
    node *slow_ptr = head;
    node *fast_ptr = head;
    if(head == NULL)
        return;
    /* If there are odd nodes in the circular list then
    fast_ptr->next becomes head and for even nodes
    fast_ptr->next->next becomes head */
    while(fast_ptr->next != head && fast_ptr->next->next != head)
    {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }
    /* If there are even elements in list
       then move fast_ptr */
    if(fast_ptr->next->next == head)
        fast_ptr = fast_ptr->next;
    /* Set the head pointer of first half */
    *head1_ref = head;
    /* Set the head pointer of second half */
    if(head->next != head)
        *head2_ref = slow_ptr->next;
    /* Make second half circular */
    fast_ptr->next = slow_ptr->next;
    /* Make first half circular */
    slow_ptr->next = head;
}