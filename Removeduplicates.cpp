/*
Algorithm :
removeDuplicates(head_ref, x)
    if head_ref == NULL
        return
    Initialize current = head_ref
    while current->next != NULL
        if current->data == current->next->data
            deleteNode(head_ref, current->next)
        else
            current = current->next
*/

/* The underlying condition is that the nodes that are similar lie next to each other*/
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

void removeduplicates(node** head)
{
    if((*head) == NULL)
    {
        return;
    }
    node* current = (*head);
    node* next;
    while(current->next != NULL)
    {
        if(current->data == current->next->data)
        {
            deletenode(*head , current->next);
        }
        else
        {
            current = current->next;
        }
    }

}