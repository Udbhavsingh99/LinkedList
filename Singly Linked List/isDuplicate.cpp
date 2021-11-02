#include<iostream>
#include<map>
using namespace std;

class node
{
    public:
    node* next;
    int data;
};
//Given Input : pointer to head
//Removes duplicates from Linked List
int delrepeat(node* head)
{
    //Pointer to traverse the Linked List.Current pointer points to head node
    node* current = head;
    //Pointer to store the next pointer of the node to be deleted
    node* next;
    //Check if current is NULL
    if(current == NULL)
    {
        //Exit function if condition is true
        return;
    }
    //If the node next to current is not NULL
    while(current->next != NULL)
    {
            //If data of current node is same as that of next node
            if(current->data == current->next->data)
            {
                //Move the next pointer to point to node next to next of current node ie. node to be deleted
                next = current->next->next;
                //Delete the node being pointed to by current
                delete(current);
                //Make the next part of current node to point to next
                current->next = next;
            }
            else
            {
                //In all other cases continue traversing the Linked List
                current = current->next;
            }
    }
}

//Recursion 
/* The function removes duplicates
from a sorted list */
void removeDuplicates(node* head)
{
    /* Pointer to store the pointer of a node to be deleted*/
    node* to_free;
    /* do nothing if the list is empty */
    if (head == NULL)
        return;
    /* Traverse the list till last node */
    if (head->next != NULL)
    {
        /* Compare head node with next node */
        if (head->data == head->next->data)
        {
            /* The sequence of steps is important. to_free pointer stores the next of head pointer which is to be deleted.*/   
            to_free = head->next;
        head->next = head->next->next;
        free(to_free);
        removeDuplicates(head);
        }
        else /* This is tricky: only
        advance if no deletion */
        {
            removeDuplicates(head->next);
        }
    }
}

//Two Pointer Approach
/*Create a pointer that will point towards the first occurrence of every element and another pointer temp which will iterate to every element and when the value of the previous pointer is not equal to the temp pointer, we will set the pointer of the previous pointer to the first occurrence of another node.*/
// Function to remove duplicates
// from the given linked list
node *removeduplicate(node *head)
{
    // Two references to head
    // temp will iterate to the
    // whole Linked List
    // prev will point towards
    // the first occurrence of every element
    node *temp = head,*prev=head;
    // Traverse list till the last node
    while (temp != NULL)
    {
       // Compare values of both pointers
    if(temp->data != prev->data)
    {
        /* if the value of prev is  not equal to the value oftemp that means there are nomore occurrences of the prev data->So we can set the next of prev to the temp node->*/
        prev->next = temp;
        prev = temp;
    }
        /*Set the temp to the next node*/
        temp = temp->next;
    }
/*This is the edge case if there
are more than one occurrences
of the last element*/
if(prev != temp)
{
        prev->next = NULL;
}
return head;
}

//Using Maps
//The idea is to push all the values in a map and printing its keys.
void removeDuplicates(node* head)
{
    unordered_map<int, bool> track;
    node* temp = head;
    while (temp) {
        if (track.find(temp->data) == track.end()) {
            cout << temp->data << " ";
        }
        track[temp->data] = true;
        temp = temp->next;
    }
}