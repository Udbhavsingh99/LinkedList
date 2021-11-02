/*
delAllOccurOfGivenKey(head_ref, x)
    if head_ref == NULL
        return
    Initialize current = head_ref
    Declare next
    while current != NULL
        if current->data == x
            next = current->next
            deleteNode(head_ref, current)
            current = next
        else
            current = current->next
*/
#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node* prev;
};

void deletenode(node* head , node* del)
{
    if(head == NULL || del == NULL)
    {
        return;
    }
    if(head == del)
    {
        head = del->next;
    }
    if(del->next != NULL)
    {
        del->next->prev = del->prev;
    }
    if(del->prev != NULL)
    {
        del->prev->next = del->next;
    }
    free(del);
}

void delalloccurkey(node* head , int x)
{
    if(head == NULL)
    {
        return;
    }
    node* current = head;
    node* next;

    while(current != NULL)
    {
        if(current->data == x)
        {
            next = current->next;
            deletenode(head , current);
            current = next;
        }
        else
        {
            current = current->next;
        }
    }
}