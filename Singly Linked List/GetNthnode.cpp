#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* link;
};

//Iterative :
/*1. Initialize count = 0
2. Loop through the link list
    a. if count is equal to the passed index then return current
        node
    b. Increment count
    c. change current to point to next of the current.*/

int getnthnode(node* head , int pos)
{
    node* current = head;
    int count = 0;
    while(current != NULL)
    {
        count++;
        current = current->link;
        if(count == pos)
        {
            return (current->data);
        }
    }
    return;
}

//Recursive :
/*getnth(node,n)
1. Initialize count = 0
2. if count==n
return node->data
3. else
    return getnth(node->next,n-1)*/

int getnthnoderec(node* head , int pos)
{
    if(head == NULL)
    {
        return;
    }
    if(pos == 0)
    {
        return (head->data);
    }
    return getnthnoderec(head->link , pos);
}