#include<iostream>
using namespace std;

class node 
{
    public:
    int data;
    node* link;
};

//Method 1 :
/*Traverse the whole linked list and count the no. of nodes. Now traverse the list again till count/2 and return the node at count/2. */

//Method 2 :
/*Traverse linked list using two pointers. Move one pointer by one and the other pointers by two. When the fast pointer reaches the end slow pointer will reach the middle of the linked list.*/

int midelement(node* head)
{
    node* fastptr = head;
    node* slowptr = head;

    while(head != NULL)
    {
        
        while (fastptr != NULL && fastptr->link != NULL)
        {
            slowptr = slowptr->link;
            fastptr = fastptr->link->link;
        }
        cout<<slowptr->data;
    }
}

//Method 3 :
/*Initialize mid element as head and initialize a counter as 0. Traverse the list from head, while traversing increment the counter and change mid to mid->next whenever the counter is odd. So the mid will move only half of the total length of the list. */

int midelement2(node* head)
{
    int cnt = 0;
    node* current = head;
    while(head != NULL)
    {
        if (cnt & 1)
            current = current->link;
        ++cnt;
        head = head->link;
    }
    if(current != NULL)
    {
        cout<<current->data;
    }
}