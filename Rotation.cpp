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
Algorithm
1. To rotate the Doubly linked list, first, we need to traverse through the linked list and find the address of the last node. 

2. Then make it a circular linked list.

3. Then move the head as well as a temp by n nodes.

4. Then make the linked list as un-circular.
*/

void inserthead(node* head , int newdata)
{
    node* newnode = new node();
    newnode->data = newdata;
    if(head == NULL)
    {
        head = newnode;
        return;
    }
    newnode->next = head;
    newnode->prev = NULL;
    head->prev = newnode;
    head = newnode;
}

void inserttail(node* head , int newdata)
{
    node* newnode = new node();
    node* last = head;
    newnode->data = newdata;
    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = newnode;
    newnode->next = NULL;
    newnode->prev = last;
    last = newnode;
}
//Solution 1
void rotaten(node* head , int pos)
{
    //If pos is 0 , return list without any change
    if(pos == 0)
    {
        return;
    }
    //Finding last node
    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    //Making the list circular
    temp->next = head;
    head->prev = temp;
    //Move head & temp by the given position
    int cnt = 1;
    while(cnt <= pos)
    {
        temp = temp->next;
        head = head->next;
        cnt++;
    }
    //Make the list uncircular 
    temp->next = NULL;
    head->prev = NULL;
}
//Solution 2
void inserthead(node* head, int newdata)
{
    node* newnode = new node();
    newnode->data = newdata;
    if(head == NULL)
    {
        head = newnode;
        return;
    }
    newnode->next = head;
    head->prev = newnode;
    newnode->prev = NULL;
    head = newnode;
}
void insetail(node* head , int newdata)
{
    node* newnode = new node();
    newnode->data = newdata;
    if(head == NULL)
    {
        inserthead(head , newdata);
        return;
    }
    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = NULL;
    temp = newnode;
}

void rotateByN(node *&head, int pos)
{
    if (pos == 0)
        return;
    node *curr = head;
    while (pos)
    {
        curr = curr->next;
        pos--;
    }
    node *tail = curr->prev;
    node *newHead = curr;
    tail->next = NULL;
    curr->prev = NULL;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = head;
    head->prev = curr;
    head = newHead;
}