#include<iostream>
using namespace std;

class node 
{
    public:
    int data;
    node* link;
};

//Iterative:

/*1) Initialize a node pointer, current = head.
2) Do following while current is not NULL
    a) current->key is equal to the key being searched return true.
    b) current = current->next
3) Return false*/

//Given input : Reference to node , element to be searched
bool searchelement(node* head , int y)
{
    node*current = head;
    while(current != NULL)
    {
        if(current->data == y)
        {
            return true;
            current = current->link;
        }
    }
    return false;
}

//Recursive :

/*bool search(head, x)
1) If head is NULL, return false.
2) If head's key is same as x, return true;
3) Else return search(head->next, x) */

bool searchelementrec(node* head , int y)
{
    node* current = head;
    while(current != NULL)
    {
        if(current->data == y)
        {
            return true;
        }
    }
    return searchelementrec(current->link , y);
}