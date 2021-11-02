#include<iostream>
using namespace std;

class node
{
    public:
    node* next;
    int data;
};

//Iterative
//Start from the head node and traverse the list. While traversing swap data of each node with its next node’s data. 
void pairWiseSwap(node* head)
{
    node* temp = head;
    /* Traverse further only if 
    there are at-least two nodes left */
    while (temp != NULL && temp->next != NULL) {
        /* Swap data of node with 
           its next node's data */
        swap(temp->data,temp->next->data);
        /* Move temp by 2 for the next pair */
        temp = temp->next->next;
    }
}