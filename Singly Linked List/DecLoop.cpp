#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* link;
};

//Floyd's Cycle Finding Algorithm
/*Steps :
Traverse linked list using two pointers.
Move one pointer(slow_p) by one and another pointer(fast_p) by two.
If these pointers meet at the same node then there is a loop. If pointers do not meet then linked list doesn’t have a loop.*/

int decloop(node* head)
{
    //Initiate 2 nodes slowptr & fastptr to head
    node* slowptr = head;
    node* fastptr = head;
    //while slowptr , fastptr & the node next to fastptr are not NULL
    while(slowptr && fastptr && fastptr->link)
    {
        //We move slowptr to the next node ie. one node forward
        slowptr = slowptr->link;
        //We move fastptr to the next of next node ie. two node forward
        fastptr = fastptr->link->link;
        //If slowptr is equal to fastptr
        if(slowptr == fastptr)
        {
            //Then loop exists & so we need to return 1
            return 1;
        }
    }
    //In all other cases we need to return 0
    return 0;
}