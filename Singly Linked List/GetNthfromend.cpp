#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* link;
};

//Use length of Linked List
/*
1) Calculate the length of Linked List. Let the length be len. 
2) Print the (len – n + 1)th node from the beginning of the Linked List. 
Double pointer concept : First pointer is used to store the address of the variable and second pointer used to store the address of the first pointer. If we wish to change the value of a variable by a function, we pass pointer to it. And if we wish to change value of a pointer (i. e., it should start pointing to something else), we pass pointer to a pointer.*/

void printnthfromend(struct node* head, int n)
{
    int len = 0, i;
    node* temp = head;
    while (temp != NULL) {
        temp = temp->link;
        len++;
    }
    if (len < n)
        return;
    temp = head;
    for (i = 1; i < len - n + 1; i++)
        temp = temp->link;
    cout << temp->data;
    return;
}

//Use 2 pointers
/*Maintain two pointers – reference pointer and main pointer. Initialize both reference and main pointers to head. First, move the reference pointer to n nodes from head. Now move both pointers one by one until the reference pointer reaches the end. Now the main pointer will point to nth node from the end. Return the main pointer.*/

void printNthFromLast(node *head, int n)
{
  node *main_ptr = head;
  node *ref_ptr = head;

int count = 0;
if(head != NULL)
{
    while( count < n )
    {
        if(ref_ptr == NULL)
        {
            return;
        }
        ref_ptr = ref_ptr->link;
        count++;
    } /* End of while*/
    if(ref_ptr == NULL)
    {
        head = head->link;
        if(head != NULL)
            cout<<main_ptr->data;
    }
    else
    {
        while(ref_ptr != NULL)
    {
        main_ptr = main_ptr->link;
        ref_ptr  = ref_ptr->link;
    }
        cout<<main_ptr->data;
    }
}
}