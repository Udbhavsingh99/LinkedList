#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* link;
};

//Iterative :
/*1. Initialize count as zero.
2. Loop through each element of linked list:
    a) If element data is equal to the passed number then
        increment the count.
3. Return count.*/

int countint(node* head , int m)
{
    node* current = head;
    int s = 0;
    while(current != NULL)
    {
            if(current->data == m)
            {
                s++;
            }
        current = current->link;
    }
    return s;
}

//Recursive :
/*count(head, key);
if head is NULL
return frequency
if(head->data==key)
increase frequency by 1
count(head->next, key)*/
int countintrec(node* head , int m)
{
    int s = 0;
    if(head == NULL)
    {
        return s;
    }
    if(head->data == m)
    {
        s++;
    }
    countintrec(head->link , m);
}
