#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;
    node *prev;
};

/*Naive Method :
This is the simplest way where two loops are used. The outer loop is used to pick the elements one by one and the inner loop compares the picked element with the rest of the elements. 
*/
// Function to delete a node in a Doubly Linked List.
// head_ref --> pointer to head node pointer.
// del  -->  pointer to node to be deleted.
void deletenode(node* head , node* del)
{
    //base case
    if((head) == NULL || del == NULL)
    {
        return;
    }
    // If node to be deleted is head node
    if((head) == del)
    {
        (head) = del->next;
    }
    // Change next only if node to be deleted
    // is NOT the last node
    if(del->next != NULL)
    {
        del->next->prev = del->prev;
    }
    // Change prev only if node to be deleted
    // is NOT the first node
    if(del->prev != NULL)
    {
        del->prev->next = del->next;
    }
    // Finally, free the memory occupied by del
    free(del);
}

// function to remove duplicates from
// an unsorted doubly linked list
void removeduplicates(node* head , int x)
{
    
    // if DLL is empty or if it contains only
    // a single node
    if((head == NULL) || (head->next == NULL))
    {
        return;
    }
    node* curr;
    node* nextval;

    // pick elements one by one
    for(curr = head ; curr != NULL ; curr = curr->next)
    {
        nextval = curr->next;

        // Compare the picked element with the
        // rest of the elements
        while(nextval != NULL)
        {
            // if duplicate, then delete it
            if(curr->data == nextval->data)
            {
                //Store pointer to node next to nextval
                node* pointnext = nextval->next;
                //Delete node pointed to be nextval
                deletenode(head , nextval);
                //Update nextval
                nextval = pointnext;

            }
            else
            {
                //Simple move to next node
                nextval = nextval->next;
            }
        }
    }
}

/* Sorting Method :
Following are the steps: 

Sort the elements of the doubly linked list using Merge Sort. Refer this post.
Remove duplicates in linear time using the algorithm to remove duplicates from a sorted doubly linked list.
*/

/*Using Hashing
Complete this method after learning hashing data 
*/

