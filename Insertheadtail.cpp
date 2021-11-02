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
The task can be accomplished as: 

If Linked list is empty then make both the left and right pointers point to the node to be inserted and make its previous and next field point to NULL.
If node to be inserted has value less than the value of first node of linked list then connect that node from previous field of first node.
If node to be inserted has value more than the value of last node of linked list then connect that node from next field of last node.
If node to be inserted has value in between the value of first and last node, then check for appropriate position and make connections.
*/

void nodeinsetail(node** head , node** tail , int key)
{
    node* newnode = new node();
    newnode->data = key;
    newnode->next = NULL;
    
    if((*head) == NULL)
    {
        (*head) = newnode;
        (*tail) = newnode;
        (*head)->prev = NULL;
        return;        
    }
    if((newnode->data) < ((*head)->data))
    {
        newnode->prev = NULL;
        (*head)->prev = newnode;
        newnode->next = (*head);
        (*head) = newnode;
        return;
    }
    if((newnode->data) > ((*tail)->data))
    {
        newnode->next = NULL;
        (*tail)->next = newnode;
        newnode->prev = (*tail);
        (*tail) = newnode;
        return;
    }
    node* temp = (*head)->next;
    while((temp->data) < newnode->data)
    {
        temp = temp->next;
    }
    temp->prev->next = newnode;
    temp->prev = newnode;
    newnode->prev = temp->prev;
    newnode->next = temp;
}
