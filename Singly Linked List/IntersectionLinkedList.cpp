//Intersection of two sorted linked list
#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
};

//Using Dummy Node
/*The idea is to use a temporary dummy node at the start of the result list. The pointer tail always points to the last node in the result list, so new nodes can be added easily. The dummy node initially gives the tail a memory space to point to. This dummy node is efficient, since it is only temporary, and it is allocated in the stack. The loop proceeds, removing one node from either ‘a’ or ‘b’ and adding it to the tail. When the given lists are traversed the result is in dummy. next, as the values are allocated from next node of the dummy. If both the elements are equal then remove both and insert the element to the tail. Else remove the smaller element among both the lists. */
/*This solution uses the temporary
 dummy to build up the result list */
node* sortedIntersect(node* a, node* b)
{
    node dummy;
    node* tail = &dummy;
    dummy.next = NULL;
    /* Once one or the other
    list runs out -- we're done */
    while (a != NULL && b != NULL) {
        if (a->data == b->data) {
            push((&tail->next), a->data);
            tail = tail->next;
            a = a->next;
            b = b->next;
        }
        /* advance the smaller list */
        else if (a->data < b->data)
            a = a->next;
        else
            b = b->next;
    }
    return (dummy.next);
}

//Use Local References
/*This solution is structurally very similar to the above, but it avoids using a dummy node Instead, it maintains a struct node** pointer, lastPtrRef, that always points to the last pointer of the result list. This solves the same case that the dummy node did — dealing with the result list when it is empty. If the list is built at its tail, either the dummy node or the struct node** “reference” strategy can be used. */
node* sortedIntersect(node* a, node* b)
{
    node* result = NULL;
    node** lastPtrRef = &result;
    /* Advance comparing the first nodes in both lists. When one or the other list runs out, we're done. */
    while (a != NULL && b != NULL) {
        if (a->data == b->data) {
            /* found a node for the intersection */
            push(lastPtrRef, a->data);
            lastPtrRef = &((*lastPtrRef)->next);
            a = a->next;
            b = b->next;
        }
        else if (a->data < b->data)
            a = a->next; /* advance the smaller list */
        else
            b = b->next;
    }
    return (result);
}

//Recursive Solution
/*The recursive approach is very similar to the the above two approaches. Build a recursive function that takes two nodes and returns a linked list node. Compare the first element of both the lists. 
If they are similar then call the recursive function with the next node of both the lists. Create a node with the data of the current node and put the returned node from the recursive function to the next pointer of the node created. Return the node created.
If the values are not equal then remove the smaller node of both the lists and call the recursive function.*/
node* sortedIntersect(node* a,node* b)
{
    // base case
    if (a == NULL || b == NULL)
        return NULL;
    /* If both lists are non-empty */
    /* Advance the smaller list and
       call recursively */
    if (a->data < b->data)
        return sortedIntersect(a->next, b);
    if (a->data > b->data)
        return sortedIntersect(a, b->next);
    // Below lines are executed only
    // when a->data == b->data
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = a->data;
    // Advance both lists and call recursively
    temp->next = sortedIntersect(a->next,b->next);
    return temp;
}

//Use Hashing
