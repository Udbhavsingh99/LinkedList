#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* link;
};

//Given Input : reference to head & position at which the node is to be deleted
int delepos(node** headref , int pos)
{
    //If headref is equal to NULL exit the function
    if(*headref == NULL)
    {
        return;
    }
    //Dereference headref into current
    node* current = *headref;
    //If pos passed to function is 0
    if (pos == 0)
    {
        //Move headref to the node thats pointed by the link part of current node ie. move headref to point to the node next to current node 
        *headref = current->link;
        //Delete current node
        free(current);            
        return;
    }

    //Run a loop from 0 to pos-1 & keep incrementing the loop variable i , we also have to check that current is not NULL
    for(int i = 0; current != NULL && i < pos - 1; i++)
    {
        //If the loop conditions are satisfied we keep on moving current to the next node
        current = current->link;
    }
    //If current is nULL or the node pointed by link part of current ie. next node of current is NULL we exit the function
    if (current == NULL || current->link == NULL)
    {    
        return;
    }
    //We create a new node next which is the next of next of the present current node 
    node *next = current->link->link;
    //We then delete the node next to present current
    free(current->link); 
    //We then make the link part of current to point to next node
    current->link = next;
}