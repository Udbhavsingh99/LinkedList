#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
};

//Floyd's Cycle Finding Algorithm
/*Steps :
Traverse linked list using two pointers.
Move one pointer(slow_p) by one and another pointer(fast_p) by two.
If these pointers meet at the same node then there is a loop. If pointers do not meet then linked list doesn’t have a loop.*/
/*Algorithm:  
Find the common point in the loop by using the Floyd’s Cycle detection algorithm
Store the pointer in a temporary variable and keep a count = 0
Traverse the linked list until the same node is reached again and increase the count while moving to next node.
Print the count as length of loop*/

// Returns count of nodes present in loop.
int countNodes(node *n)
{
    //We initiate a counter variable
    int res = 1;
    //We dereference node n into temp
    node *temp = n;
    //We check if the next node of temp is not NULL
    while (temp->next != n)
    {
        //If its not NULL then increment counter by 1
        res++;
        //Move the temp pointing to the present node to the next node
        temp = temp->next;
    }
    //Return the counter 
    return res;
}
/* This function detects and counts loop
nodes in the list. If loop is not there
in then returns 0 */
int countNodesinLoop(node *list)
{
    //Initiate the slow & fast ptr to head node
    node *slow_p = list, *fast_p = list;
    //Check if slow , fast & node next ot fast node is not NULL
    while (slow_p && fast_p && fast_p->next)
    {
        //Move slow ptr to next node
        slow_p = slow_p->next;
        //Move fast ptr to next of next node
        fast_p = fast_p->next->next;
        /* If slow_p and fast_p meet at some point then there is a loop */
        if (slow_p == fast_p)
        //If loop is prsent then call count Nodes function
            return countNodes(slow_p);
    }
    /* Return 0 to indicate that there is no loop*/
    return 0;
}

node *newNode(int key)
{
    //Allocate memory inside heap
    node *temp =(node*)malloc(sizeof(node));
    //Enter data into data part of temp node
    temp->data = key;
    //Make the node next to the present node as NULL ie. the next/link part of the node should point to NULL
    temp->next = NULL;
    //Return temp
    return temp;
}