#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node* prev;
};

/*
sortedInsert(head_ref, newNode)
    if (head_ref == NULL)
    head_ref = newNode
        
    else if head_ref->data >= newNode->data
        newNode->next = head_ref
    newNode->next->prev = newNode
    head_ref = newNode    
        
    else
    Initialize current = head_ref
    while (current->next != NULL and
            current->next->data < newNode->data)
        current = current->next
        
    newNode->next = current->next
    if current->next != NULL
        newNode->next->prev = newNode
            
        current->next = newNode
    newNode->prev = current
*/

void sortedInsert(node** headref ,node* newnode)
{
    node* current;

    if((*headref) == NULL)
    {
        *headref = newnode;
    }
    else if((*headref)->data >= newnode->data)
    {
        newnode->next = (*headref);
        newnode->next->prev = newnode;
        (*headref) = newnode;
    }
    else
    {
        current = *headref;
        while(current->next != NULL && current->next->data < newnode->data)
        {
            current = current->next;
        }
        newnode->next = current->next;
        if (current->next != NULL)
        {
            newnode->next->prev = newnode;
        }
        current->next = newnode;
        newnode->prev = current;
    }


}