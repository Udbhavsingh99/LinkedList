/*The idea is to traverse the singly linked list and check if the node is the last node or not. If the node is the last node i.e pointing to NULL then make it point to the starting node i.e head node. Below is the implementation of this approach.*/

#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
};

node* circular(node* head)
{
    // declare a node variable start and
    // assign head node into start node.
    node* start = head;
    // check that while head->next not equal
    // to NULL then head points to next node.
    while (head->next != NULL)
        head = head->next;
    // if head->next points to NULL then
    // start assign to the head->next node.
    head->next = start;
    return start;
}