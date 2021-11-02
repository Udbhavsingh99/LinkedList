#include<iostream>
using namespace std;

class node
{
    public:
    node* next;
    int data;
};

//Using 2 loops
/*This is the simple way where two loops are used. Outer loop is used to pick the elements one by one and the inner loop compares the picked element with the rest of the elements. */

void removeDuplicates(node* start)
{
    node *ptr1, *ptr2, *dup;
    ptr1 = start;
    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
        /* Compare the picked element with rest
           of the elements */
        while (ptr2->next != NULL) {
            /* If duplicate then delete it */
            if (ptr1->data == ptr2->next->data) 
            {
                /* sequence of steps is important here */
                ptr2->next = ptr2->next->next;
                delete (dup);
            }
            else /* This is tricky */
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

//Use Sorting
/*In general, Merge Sort is the best-suited sorting algorithm for sorting linked lists efficiently. 
1) Sort the elements using Merge Sort. We will soon be writing a post about sorting a linked list. O(nLogn) 
2) Remove duplicates in linear time using the algorithm for removing duplicates in sorted Linked List. O(n) 
Please note that this method doesn’t preserve the original order of elements.*/

//Use Hashing
/*We traverse the link list from head to end. For every newly encountered element, we check whether it is in the hash table: if yes, we remove it; otherwise we put it in the hash table.*/
void removeDuplicates(node* start)
{
    // Hash to store seen values
    unordered_set<int> seen;
 
    /* Pick elements one by one */
    node* curr = start;
    node* prev = NULL;
    while (curr != NULL) {
        // If current value is seen before
        if (seen.find(curr->data) != seen.end()) {
            prev->next = curr->next;
            delete (curr);
        }
        else {
            seen.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }
}