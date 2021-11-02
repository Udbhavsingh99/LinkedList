#include<iostream>
using namespace std;

class node
{
    public:
    int data; 
    node* next;
    node* prev;
};

node* split(node* head);

node* merge(node* first , node* second)
{
    if(!first)
    {
        return second;
    }
    else if(!second)
    {
        return first;
    }
    if(first->data <= second->data)
    {
        first->next = merge(first->next , second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = merge(first , second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

node* mergesort(node* head)
{
    if(head || head->next)
    {
        return head;
    }
    node* second = split(head);
    head = mergesort(head);
    second = mergesort(second);

    return merge(head , second);
}

node* split(node* head)
{
    node* fast = head;
    node* slow = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node* temp = slow->next;
    slow->next = NULL;
    return temp; 
}