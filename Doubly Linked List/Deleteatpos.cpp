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
Get the pointer to the node at position n by traversing the doubly linked list up to the nth node from the beginning.
Delete the node using the pointer obtained in Step 1
*/

void deletenode(node* head , node* del)
{
    //1.Check for base case. If the node passed to the function or node to be deleted are null , return
    if(head == NULL || del == NULL)
    {
        return;
    }
    //2.If the node to be deleted is the head
    if(head == del)
    {
        //Move head to the node next to the node to be deleted
        head = del->next;
    }
    //3.Check if del is not the last node to be deleted
    if(del->next != NULL)
    {
        //Then change the previous (prev pointer) of the node next to the present del & make it equal to the previous (prev pointer) of the present del ie. we create a link between  the node before the present del & the node next to the present del using the prev pointers
        del->next->prev = del->prev;
    }
    //If the node before the del is not null ie. we are not at beginning node
    if(del->prev != NULL)
    {
        //Then change the next pointer of the node before the present del & make it equal to the next pointer of the present del ie. we create a link between the node before the presemt del & the node next to the present del using the next pointers
        del->prev->next = del->next;
    }
    //Free the memory used by del
    free(del);
}