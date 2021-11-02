#include<iostream>
#include<assert.h>
using namespace std;

class node
{
    public:
    int data;
    node* next;
};
/*
Recursive Solution
Merge is one of those nice recursive problems where the recursive solution code is much cleaner than the iterative code. You probably wouldn’t want to use the recursive version for production code, however, because it will use stack space which is proportional to the length of the lists.  
*/
node* merge(node* a , node* b)
{
    node* result = NULL;
    if(a == NULL)
    {
        return (b);
    }
    else if( b == NULL)
    {
        return (a);
    }
    if(a->data <= b->data)
    {
        result = a;
        result->next = merge(a->next , b);
    }
    else
    {
        result = b;
        result->next = merge(a , b->next);
    }
    return result;
}

/* 
Using Dummy Node
The strategy here uses a temporary dummy node as the start of the result list. The pointer Tail always points to the last node in the result list, so appending new nodes is easy. 

The dummy node gives the tail something to point to initially when the result list is empty. This dummy node is efficient, since it is only temporary, and it is allocated in the stack. The loop proceeds, removing one node from either ‘a’ or ‘b’, and adding it to the tail. When 

We are done, the result is in dummy.next. 
*/

/* pull off the front node of
the source and put it in dest */

void MoveNode(node** destRef, node** sourceRef);

/* Takes two lists sorted in increasing
order, and splices their nodes together
to make one big sorted list which
is returned. */
node* SortedMerge(node* a, node* b)
{
    /* a dummy first node to hang the result on */
    node dummy;
    /* tail points to the last result node */
    node* tail = &dummy;
    /* so tail->next is the place to 
    add new nodes to the result. */
    dummy.next = NULL;
    while (1)
    {
        if (a == NULL)
        {
            /* if either list runs out, use the
            other list */
            tail->next = b;
            break;
        }
        else if (b == NULL)
        {
            tail->next = a;
            break;
        }
        if (a->data <= b->data)
            MoveNode(&(tail->next), &a);
        else
            MoveNode(&(tail->next), &b);
        tail = tail->next;
    }
    return(dummy.next);
}

/* MoveNode() function takes the
node from the front of the source,
and move it to the front of the dest.
It is an error to call this with the
source list empty.
Before calling MoveNode():
source == {1, 2, 3}
dest == {1, 2, 3}
After calling MoveNode():
source == {2, 3}
dest == {1, 1, 2, 3} */
void MoveNode(node** destRef, node** sourceRef)
{
    /* the front source node */
    node* newNode = *sourceRef;
    assert(newNode != NULL);
    /* Advance the source pointer */
    *sourceRef = newNode->next;
    /* Link the old dest off the new node */
    newNode->next = *destRef;
    /* Move dest to point to the new node */
    *destRef = newNode;
}

/*
Using Local References
This method maintains a struct node** pointer, lastPtrRef, that always points to the last pointer of the result list. This solves the same case that the dummy node did — dealing with the result list when it is empty. If you are trying to build up a list at its tail, either the dummy node or the struct node** “reference” strategy can be used
*/
node* sortmerge(node* a , node* b)
{
    node* result = NULL;
    node** lastptrref = &result;

    while(1)
    {
        if(a == NULL)
        {
            *lastptrref = b;
            break;
        }
        else if(b == NULL)
        {
            *lastptrref = a;
            break;
        }
        if(a->data <= b->data)
        {
            MoveNode(lastptrref , &a);
        }
        else
        {
            MoveNode(lastptrref , &b);
        }
        lastptrref = &((*lastptrref)->next);
    }
    return(result);
}

/*
Reversing the List
This idea involves first reversing both the given lists and after reversing, traversing both the lists till the end and then comparing the nodes of both the lists and inserting the node with a larger value at the beginning of the result list. And in this way we will get the resulting list in increasing order.

1) Initialize result list as empty: head = NULL.
2) Let 'a' and 'b' be the heads of first and second list respectively.
3) Reverse both the lists.
4) While (a != NULL and b != NULL)
    a) Find the larger of two (Current 'a' and 'b')
    b) Insert the larger value of node at the front of result list.
    c) Move ahead in the list of larger node. 
5) If 'b' becomes NULL before 'a', insert all nodes of 'a' 
into result list at the beginning.
6) If 'a' becomes NULL before 'b', insert all nodes of 'b' 
into result list at the beginning.  
*/

node* reverselist(node* head)
{
    if(head == NULL)
    {
        return;
    }
    node* rest = reverselist(head->next);
    head->next->next = head;
    head->next = NULL;

    return rest;
}

node* sorted(node* a , node* b)
{
    //Reverse linked list a
    a = reverselist(a);
    //Reverse linked list b
    b = reverselist(b);
    //Initialize head of resultant list
    node* head = NULL;
    node* temp;

    // Traverse both lists while both of them
    // have nodes.
    while (a != NULL && b != NULL) {
        // If a's current value is greater than or equal to
        // b's current value.
        if (a->data >= b->data) {
            // Store next of current Node in first list
            temp = a->next;
            // Add 'a' at the front of resultant list
            a->next = head;
            // Make 'a' - head of the result list
            head = a;
            // Move ahead in first list
            a = temp;
        }
        // If b's value is greater. Below steps are similar
        // to above (Only 'a' is replaced with 'b')
        else {
            temp = b->next;
            b->next = head;
            head = b;
            b = temp;
        }
    }
    // If second list reached end, but first list has
    // nodes. Add remaining nodes of first list at the
    // beginning of result list
    while (a != NULL) {
        temp = a->next;
        a->next = head;
        head = a;
        a = temp;
    }
    // If first list reached end, but second list has
    // nodes. Add remaining nodes of second list at the
    // beginning of result list
    while (b != NULL) {
        temp = b->next;
        b->next = head;
        head = b;
        b = temp;
    }
    // Return the head of the result list
    return head;
}