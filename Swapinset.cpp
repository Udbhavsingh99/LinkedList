#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next; 
    node* prev;
};

void push(node** headref , node* newnode)
{
    newnode->prev = NULL;
    newnode->next = (*headref);
    if((*headref) != NULL)
        (*headref)->prev = newnode;
    (*headref) = newnode;
}
node* revlistsize(node* head , int k)
{
    node* current = head;
    node* newhead = NULL;
    node* next = NULL;
    int count = 0;
    while(current != NULL & count < k)
    {
        next = current->next;
        push(&newhead, current);
        current = next;
        count++;
    }
    if(next != NULL)
    {
        head->next = revlistsize(next, k);
        head->next->prev = head;
    }
    return newhead;
}

/*
Simplified Implementation
*/
// function to Reverse a doubly linked list
// in groups of given size
node* reverseByN(node* head, int k)
{
    if (!head)
        return NULL;
    head->prev = NULL;
    node *temp, *curr = head, *newHead;
    int count = 0;
    while (curr != NULL && count < k) {
        newHead = curr;
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
        count++;
    }
    // checking if the reversed LinkedList size is
    // equal to K or not
    // if it is not equal to k that means we have reversed
    // the last set of size K and we don't need to call the
    // recursive function
    if (count >= k) {
        node* rest = reverseByN(curr, k);
        head->next = rest;
        if (rest != NULL)
            // it is required for prev link otherwise u wont
            // be backtrack list due to broken links
            rest->prev = head;
    }
    return newHead;
}