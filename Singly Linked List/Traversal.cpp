#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* link;
};
//Given Input : reference to head node
void printlist(node* head)
{
    //Dereferencing head into current
    node* current = head;
    //Checking condition for current not NULL ie. Linked List is not empty
    while(current != NULL)
    {
        //If condition is true , display the data stored in data part of current 
        cout<<current->data<<"\n";
        //Move current to the next node using the address specified in the link part of current node
        current = current->link;
    }
}
int main()
{
    node* head = NULL;
    node* one = NULL;
    node* two = NULL;

    head = new node();
    one = new node();
    two = new node();
    
    head->data = 1;
    head->link = one;

    one->data = 2;
    one->link = two;

    two->data = 3;
    two->link = NULL;

    printlist(head);
    return 0;
}