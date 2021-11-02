#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* link;
};
//Given Input : refernce to head pointer
void deletelinklist(node* headref)
{
    //Initialize a node current that stores the dereferenced pointer
    node* current = headref;
    //Initialize next to NULL
    node* next = NULL;
    //Traverse through the linked list node by node
    while(current != NULL)
    {
        //Assign next the node next to the current node ie. the node that is being pointed towards by the current node link part
        next = current->link;
        //Delete current node
        delete current;
        //Now make the next node as current & repeat till all nodes are deleted
        current = next;
    }
    //Assign reference to head as value NULL , this means the list is now completely deleted
    headref = NULL;
}