#include<iostream>
#include<stack>
using namespace std;

class node
{
    public:
    node* next;
    node* prev; 
    int data;
};

void reverse(node** head)
{
    node* temp = NULL;//Temporary node for swapping algorithm
    node* current = *head;
    /*swap next & prev for all nodes of linked list*/
    while(current != NULL)
    {
        //Basically swapping algorithm where we are swapping the nodes to which prev & next point to
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        //We move the current pointer one place backward
        current = current->prev;
    }
    /* Before changing the head, check for the cases like empty
    list and list with only one node */
    if(temp != NULL)
    {
        *head = temp->prev;
    }
}

/*Reversing using stack*/
/*Steps:

Keep pushing the node’s data in the stack. -> O(n)
The keep popping the elements out and updating the Doubly Linked List
*/

node* head = NULL;
/*
Note about stack stl data type:
1. .push(value) is used to push a value on the stack, the pushed value is always present at the top of the stack
2. .top() is used to access the top value of the stack
3. .pop() us used to pop value from the stack
*/
void reverse()
{
    stack<int> st;
    node* temp = head;
    while(temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    // Added all the elements sequence wise in the st
    temp = head;
    while(temp != NULL)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    // Popped all the elements and the added in the linked list , which are in the reversed order->
}