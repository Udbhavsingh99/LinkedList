#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
};

void printlist(node* head)
{
    node*temp = head;
    while(head != NULL)
    {
        do
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        } while (temp != head);
        
    }
}

//Given Input: Pointer to head , data part of new node
void push(node* head , int newdata)
{
    //Allocate memory to new node
    node* newnode = new node();
    //Dereference head value in temp
    node* temp = head;
    //Place the data passed into the data part of newly created node
    newnode->data = newdata;
    //The next part of newly created node should point to the head
    newnode->next = head;

    //If head is not NULL
    if(head != NULL)
    {
        //The node that the next part of temp points to ie. next node is not NULL
        while(temp->next != NULL)
        {
            //Keep on moving temp to the next node
            temp = temp->next;
        }
        //If the node next to temp is NULL ie. we have reached the end of linked list then place newnode next to temp. The next part of temp should point to the newly created node
        temp->next = newnode;
    }
    else
    {
        //If head is NULL , then the put the next part of newnode as newnode
        newnode->next = newnode;
    }
    //Make the newly created node as head of the circular linked list
    head = newnode;
}