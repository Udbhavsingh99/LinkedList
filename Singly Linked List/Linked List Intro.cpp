#include<iostream>
using namespace std;

class node 
{
    public:
    int data;
    node* link;
};

int main()
{
    /*We first initialize all the nodes to NULL value*/
    node* head = NULL;
    node* one = NULL;
    node* two = NULL;

    /*Further we assign each node memory in the memory heap using the new operator*/
    head = new node();
    one = new node();
    two = new node();

    /*We enter data part of the first node (type : integer) & link the first node to the second node (ie. one)*/
    head->data = 1;
    head->link = one;

    /*We enter data part of the second node (type : integer) & link the second node to the third node (ie. two)*/
    one->data = 2;
    one->link = two;

    /*We enter data part of the third node (type : integer) & link the third node to NULL. This is because this is the last node in the list*/
    two->data = 3;
    two->link = NULL;

    return 0;
}