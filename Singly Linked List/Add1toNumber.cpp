#include<iostream>
using namespace std;

class node
{
    public:
    node* next;
    int data;
};

/*Algorithm 
Reverse the Linked List so that we can start with least significant bit right away
Start traversing from leftmost node & add 1 to it. If there is carry move to next node. Move to next node till there is carry.When we add one there are 2 scenarios : 1.The number was smaller than 9 in which case when we add one the number gets incremented by one. 2.The number is 9 , so adding one to it makes it 10 & so we need to carry 1 to the next number & keep carrying it.
Reverse modififed linked list & return
*/

//When we add a number addition starts from the least significant bit ie. last number

/*Print function*/
void printlist(node* head)
{
    node* temp = head;
    while(head != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

node* reverse(node* head)
{
    node* current = head;
    node* prev = NULL;
    node* next = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

node* newNode(int newdata)
{
    node* newnode = new node();
    newnode->data = newdata;
    newnode->next = NULL;
    return newnode;
}
/*Adds one to linked list & returns the resultant linked list*/
node* addoneUtil(node* head)
{
    node* res = head;
    node* temp  , *prev = NULL;
    int carry = 1 , sum;
    while(head != NULL)
    {
        sum = carry + (head? head->data : 0);
        carry = (sum >= 10?1 : 0);
        //We divide the sum variable by 10 as we have already stored the carry inside carry variable
        sum = sum%10;
        //We store the sum value in head
        head->data = sum;
        //We make temp equal to head
        temp = head;
        //We make head point to the next node
        head = head->next;
    }
    if(carry > 0)
    {
        temp->next = newNode(carry);
    }
        return res;
}

node* addone(node* head)
{
    //Reverse Linked List
    head = reverse(head);

    //Add one from left to right of linked list
    head = addoneUtil(head);

    //Reverse the modified list
    return reverse(head);
}

/* Recursive implementation*/
node* addonerec(node* head)
{
    //Carry is returned only when we have a new digit generated ex. number goes from 2 to 3 digit
    int carry = addWithCarry(head);

    //If carry is generated we create a new node to store the extra value
    if(carry)
    {
        node* newnode = new node();
        newnode->next = NULL;
        newnode->data = carry;
        return newnode;
    }
    return head;
}

int addWithCarry(node* head)
{
    //If head is null ie. we are at last node
    if(head == NULL)
    {
        return 1;
    }
    //If head is not NULL 
    int res = head->data + addWithCarry(head->next);
    head->data = res%10;
    return (res)/10;

}