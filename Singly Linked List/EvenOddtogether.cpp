/*
Cases to handle
Empty Linked List
Linked List with one node
Linked List with only two nodes
Linked List with Odd number of nodes
Linked List with Even number of nodes
*/
/*
We will maintain 2 pointers odd & even for current nodes for odd & even positions respectively
We will store first node of even linked list so that we can attach the even list at the end of the odd list after all odd & even nodes are connected together in two different lists
*/
#include<iostream>
using namespace std;

class node
{
    public:
    int data; 
    node* next;
};

node* rearrangeevenodd(node* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    //We declare odd pointing to head , first node of linked list
    node* odd = head;
    //We declare even on the position next to head , second node of linked list
    node* even = head->next;
    //We declare evenFirst to first occurrence of even , same value as even
    node* evenFirst = even;
    while(1)
    {
        /*No more elements to be added to linked list & so we add evenFirst next to odd linked list & in this way we connect the even linked list with the odd linked list as evenFirst acts as the head of the even linked list*/
        if(!odd||!even||!even->next)
        {
            //We place evenFirst(& the corresponding even linked list) next to the last odd element of odd linked list
            odd->next = evenFirst;
            break;
        }
        /*The next pointer of even needs to be at an odd position & so we assign the next pointer of odd the value of next pointer of even so that it moves to the next odd position.This will connect the odd to the pointer next to even (which is at odd position)*/
        odd->next = even->next;
        /*We now move the odd pointer to the position next of even  ie. the next odd position*/
        odd = even->next;
        /*If the next of odd is NULL*/
        if(odd->next == NULL)
        {
            /*Then we update the next of even as NULL.This is because we know that there is no even element if odd element next is NULL*/
            even->next = NULL;
            /*Then we join both the odd & even linked list*/
            odd->next = evenFirst;
            break;
        }
        /*If next of odd is not NULL , then the next pointer of odd needs to point to an even position & so we assign the next pointer of even  the value of next pointer of odd so that it moves to next even position.This will connect the even pointer to pointer next to odd(which is even)*/
        even->next = odd->next;
        /*we now move the even pointer to position next of odd ie. next even position*/
        even=odd->next;
    }
    return head;
}