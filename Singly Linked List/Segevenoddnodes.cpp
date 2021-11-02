//Segregate Even & Odd Nodes

#include<iostream>
using namespace std;

class node
{
    public:
    node* next;
    int data;
};

//Method 1
/*The idea is to get pointer to the last node of list. And then traverse the list starting from the head node and move the odd valued nodes from their current position to end of the list.
Thanks to blunderboy for suggesting this method.
Algorithm: 
…1) Get pointer to the last node. 
…2) Move all the odd nodes to the end. 
……..a) Consider all odd nodes before the first even node and move them to end. 
……..b) Change the head pointer to point to the first even node. 
……..b) Consider all odd nodes after the first even node and move them to the end. */

void segregateEvenOdd(node **head_ref)
{
    node *end = *head_ref;
    node *prev = NULL;
    node *curr = *head_ref;
    /* Get pointer to the last node */
    while (end->next != NULL)
        end = end->next;
    node *new_end = end;
    /* Consider all odd nodes before the first
     even node and move then after end */
    while (curr->data % 2 != 0 && curr != end)
    {
        new_end->next = curr;
        curr = curr->next;
        new_end->next->next = NULL;
        new_end = new_end->next;
    }
    // 10->8->17->17->15
    /* Do following steps only if
    there is any even node */
    if (curr->data%2 == 0)
    {
        /* Change the head pointer to
        point to first even node */
        *head_ref = curr;
        /* now current points to
        the first even node */
        while (curr != end)
        {
            if ( (curr->data) % 2 == 0 )
            {
                prev = curr;
                curr = curr->next;
            }
            else
            {
                /* break the link between
                prev and current */
                prev->next = curr->next;
                /* Make next of curr as NULL */
                curr->next = NULL;
                /* Move curr to end */
                new_end->next = curr;
                /* make curr as new end of list */
                new_end = curr;
                /* Update current pointer to
                next of the moved node */
                curr = prev->next;
            }
        }
    }
    /* We must have prev set before executing
    lines following this statement */
    else prev = curr;
    /* If there are more than 1 odd nodes
    and end of original list is odd then
    move this node to end to maintain
    same order of odd numbers in modified list */
    if (new_end != end && (end->data) % 2 != 0)
    {
        prev->next = end->next;
        end->next = NULL;
        new_end->next = end;
    }
    return;
}

//Method 2
/*The idea is to split the linked list into two: one containing all even nodes and other containing all odd nodes. And finally, attach the odd node linked list after the even node linked list. 
To split the Linked List, traverse the original Linked List and move all odd nodes to a separate Linked List of all odd nodes. At the end of loop, the original list will have all the even nodes and the odd node list will have all the odd nodes. To keep the ordering of all nodes same, we must insert all the odd nodes at the end of the odd node list. And to do that in constant time, we must keep track of last pointer in the odd node list.*/

void segregateEvenOdd(struct Node **head_ref)
{
    // Starting node of list having
    // even values.
    node *evenStart = NULL;
    // Ending node of even values list.
    node *evenEnd = NULL;
    // Starting node of odd values list.
    node *oddStart = NULL;
    // Ending node of odd values list.
    node *oddEnd = NULL;
    // Node to traverse the list.
    node *currNode = *head_ref;
    while(currNode != NULL){
        int val = currNode -> data;
        // If current value is even, add
        // it to even values list.
        if(val % 2 == 0) {
            if(evenStart == NULL){
                evenStart = currNode;
                evenEnd = evenStart;
            }
            else{
                evenEnd -> next = currNode;
                evenEnd = evenEnd -> next;
            }
        }
        // If current value is odd, add
        // it to odd values list.
        else{
            if(oddStart == NULL){
                oddStart = currNode;
                oddEnd = oddStart;
            }
            else{
                oddEnd -> next = currNode;
                oddEnd = oddEnd -> next;
            }
        }
        // Move head pointer one step in
        // forward direction
        currNode = currNode -> next;   
    }
    // If either odd list or even list is empty,
    // no change is required as all elements
    // are either even or odd.
    if(oddStart == NULL || evenStart == NULL){
        return;
    }
    // Add odd list after even list.    
    evenEnd -> next = oddStart;
    oddEnd -> next = NULL;
    // Modify head pointer to
    // starting of even list.
    *head_ref = evenStart;
}