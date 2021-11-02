#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node* prev;
};
/*Insertion types -
A node can be added in four ways 
1) At the front of the DLL 
2) After a given node. 
3) At the end of the DLL 
4) Before a given node.
*/

//Insertion :
/*Add a node at the front
Given Input : Pointer to head , data to be entered in newly created node*/
void push(node** head , int newdata)
{
    //Assign memory for the new node
    node* newnode = new node();
    //Enter the data passed to the function into the newly created node
    newnode->data = newdata;
    //The next part of newly created node should point to the head 
    newnode->next = *head;
    //As the newnode is being added to front , the prev should point to NULL. There is no node before the newnode
    newnode->prev = NULL;
    if((*head) != NULL)//If head is not NULL
    {
        //Then we make the prev part of head to point to the newly created newnode ie. newnode is placed before the head
        (*head)->prev = newnode;
    }
    //We make the newly created node the head as its the first node in the list
    (*head) = newnode;
}

/*Add a node after given node*/
void pushaft(node* prevnode , int newdata)
{
    if(prevnode == NULL)
    {
        return;
    }
    node* newnode = new node();
    newnode->next = prevnode->next;
    newnode->prev = prevnode;
    newnode->data = newdata;
    prevnode->next = newnode;
    if(newnode != NULL)
    {
        newnode->next->prev = newnode;
    }
}

/*next is a pointer that points to the memory address at which next node is stored next stores memory address of next node*/
/*prev is a pointer that points to the memory address at which previous node is stored*/
/*node* previous = prevnode 

/*Add a node at the end*/
void pushend(node** head , int newdata)
{
    node* newnode = new node();
    newnode->data = newdata;
    newnode->next = NULL;
    node* last = *head;
    while((*head) == NULL)
    {
        newnode->prev = NULL;
        (*head) = newnode;
        return;
    }
    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = newnode;
    newnode->prev = last;
    return;
}

/*Add a node before a given node*/
void pushbef(node** head , node* nextnode , int newdata)
{
    node* newnode = new node();
    if(nextnode == NULL)
    {
        return;
    }
    newnode->data = newdata;
    nextnode->prev = newnode->prev;
    nextnode->prev = newnode;
    newnode->next = nextnode;
    if(newnode->prev != NULL)
    {
        newnode->prev->next = newnode;
    }
    else
    {
        *head = newnode;
    }
}


/*Steps for adding a node after given node
Let the pointer to this given node be next_node and the data of the new node to be added as new_data. 

Check if the next_node is NULL or not. If it’s NULL, return from the function because any new node can not be added before a NULL
Allocate memory for the new node, let it be called new_node
Set new_node->data = new_data
Set the previous pointer of this new_node as the previous node of the next_node, new_node->prev = next_node->prev
Set the previous pointer of the next_node as the new_node, next_node->prev = new_node
Set the next pointer of this new_node as the next_node, new_node->next = next_node;
If the previous node of the new_node is not NULL, then set the next pointer of this previous node as new_node, new_node->prev->next = new_node
Else, if the prev of new_node is NULL, it will be the new head node. So, make (*head_ref) = new_node.*/


/*Basic concept clearing 
node1.data = This means that node1 is the object & is of datatype node.We can access the object/members of object directly using a .(dot operator)
node2->data = This means that node2 is a pointer that points to an object & is of datatype node* . We use this pointer (node2) to access the object/members of the object that the pointer points to by using a ->(arrow operator).*/
