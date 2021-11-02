#include<iostream>
using namespace std;

class node 
{
    public:
    node* link;
    int data;
};

/*Given Input : Reference to head & data for new node*/
void pushatfront(node** head , int x)
{
    //Create a new memory in heap using using new operator& assign it no newnode 
    node* newpush = new node();
    //Enter the data passed to the function inside the data part of newly created node
    newpush->data = x;
    //Link the newly created node to the head of the node ie. the link part of newly created node should point to the head
    newpush->link = (*head);
    //The newly created node is the new head of the linked list
    *head = newpush;

}

/*Given Input : Previos node reference & data for new node*/
void pushinbetween(node* prev , int x)
{
    //Check if the node passed to function points to NULL , if it does exit the function
    if(prev == NULL)
    {
        return;
    }
    //Assign memory in heap using new operator & assign it to new node
    node* newpush = new node();
    //Enter the data passed to the function inside the data part of newly created node
    newpush->data = x;
    /*The link part of the newly created node should be same as that of the previos node which was pointing to the node that is next to 
    the newly created node*/
    newpush->link = prev->link;
    /*The link part of previous node should now point to the newly created node to link the newly created node to the linked list in the 
    desired position*/
    prev->link  = newpush;
}
/*Given Input : Reference to head & data for new node*/
int pushend(node** headref , int x)
{
    //Assign memory in the heap using new operator & assign it to a new node
    node* endnode = new node();
    //Assign head reference to a node
    node* last = *headref;
    //Enter the data passed to the function inside the data part of newly created node
    endnode->data = x;
    //The link part of newly created node should point to NULL as it will be the last node in the linked list
    endnode->link == NULL;
    /*If headred is NULL , then list is empty. The headref should then be equal to the endnode as it will be the only node in the linked list
    and so we make the newly created node as head*/
    if(*headref == NULL)
    {
        *headref = endnode;
    }
    //Traverse the linked list one by one till we reach the last node
    while(last->link != NULL)
    {
        last = last->link;
    }
    //Link the last node to the newly created node , the newly created node (endnode) is the new last node
    last->link = endnode;
    return;
    
}