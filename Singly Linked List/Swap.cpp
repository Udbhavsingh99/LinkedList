#include<iostream>
using namespace std;

class node
{
    public:
    node* next;
    int data;
};

/*The idea is to first search x and y in the given linked list. If any of them is not present, then return. While searching for x and y, keep track of current and previous pointers. First change next of previous pointers, then change next of current pointers. */
void swapNodes(node** head_ref, int x, int y)
{
    // Nothing to do if x and y are same
    if (x == y)
        return;
    // Search for x (keep track of prevX and CurrX
    node *prevX = NULL, *currX = *head_ref;
    while (currX && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }
    // Search for y (keep track of prevY and CurrY
    node *prevY = NULL, *currY = *head_ref;
    while (currY && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }
    // If either x or y is not present, nothing to do
    if (currX == NULL || currY == NULL)
        return;
    // If x is not head of linked list
    if (prevX != NULL)
        prevX->next = currY;
    else // Else make y as new head
        *head_ref = currY;
    // If y is not head of linked list
    if (prevY != NULL)
        prevY->next = currX;
    else // Else make x as new head
        *head_ref = currX;
    // Swap next pointers
    node* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}

//Above program can be optimized to search for x & y in single traversal using 2 loops
void swapnodes(node** head_ref, int x, int y)
{
    // Nothing to do if x and y are same
    if (x == y)
        return;
    node **a = NULL, **b = NULL;
    // search for x and y in the linked list
    // and store their pointer in a and b
    while (*head_ref) {
        if ((*head_ref)->data == x) {
            a = head_ref;
        }
        else if ((*head_ref)->data == y) {
            b = head_ref;
        }
        head_ref = &((*head_ref)->next);
    }
    // if we have found both a and b
    // in the linked list swap current
    // pointer and next pointer of these
    if (a && b) {
        swap(*a, *b);
        swap(((*a)->next), ((*b)->next));
    }
}