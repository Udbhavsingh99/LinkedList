#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
};


bool detectloop(node* head)
{
    node* slow = head;
    node* fast = head;
    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            removeloop(slow , head);
        }
        else
        {
            return 1;
        }
    }
}

/*Write Remove Loop function*/
