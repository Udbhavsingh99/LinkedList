#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* link;
};
//Iterative :

/*To delete a node from the linked list, we need to do the following steps. 
1) Find the previous node of the node to be deleted. 
2) Change the next of the previous node. 
3) Free memory for the node to be deleted.*/

//Given Input : Reference to head node & key to be searched & deleted
int delnode(node** headref , int key)
{
    //Dereference headref to current
    node* current = *headref;
    //Create a new node which is NULL valued
    node* prev = NULL;

    //We check if current is not NULL & the data part of current is the key that we are searching for in order to delete the node
    //that contains the key
    if(current != NULL && current->data == key)
    {
        //headref now points to the node that is being pointed by the link part of current node ie. headref points to the node that is next
        //to the present current
        *headref = current->link;
        //Delete current
        delete current;
        return;
    }
    else
    {
        //If current is not NULL but data part of current is not the key we are looking for 
        while(current != NULL && current->data != key)
        {
            //Then we make prev equal to the current node
            prev = current;
            //The current is then moved to the node that is specified in the link part of current ie. current is now pointing to the node 
            //next to the present current
            current = current->link;
        }
        //If current is NULL then we exit
        if(current == NULL)
        {
            return;
        }
        //Now we set the link part of prev equal to the link part of current ie. prior to deletion the link part of prev pointed to current &
        //the link part of current pointed to the node next to present current but post deletion current is removed from the linked list
        //so we link the prev node to the node next to current (the node that was pointed by the link part of current) to complete the 
        //linked list
        prev->link = current->link;
        //After this we delete current
        delete current;

    }
}
//Recursive implementation
//Recursive :
/*To delete a node of a linked list recursively we need to do the following steps.

1.We pass node* (node pointer) as a reference to the function (as in node* &head)

2.Now since current node pointer is derived from previous node’s next (which is passed by reference) so now if the value of the current node pointer is changed, previous next node’s value also gets changed which is the required operation while deleting a node (i.e points previous node’s next to current node’s (containing key) next).

3.Find the node containing the given value.

4.Store this node to deallocate it later using free() function.

5.Change this node pointer so that it points to it’s next and by performing this previous node’s next also get properly linked.*/

//Given input : Reference to head & key to be deleted
void delnoderec(node* &head , int key)
{
    //We check that head is NULL or not
    if(head == NULL)
    {
        //If head is NULL return
        return;
    }
    //If the data part of the head is equal to the key we are looking for
    if(head->data == key)
    {
        //Dereference head in temp 
        node* temp = head;
        //Move head to the next node ie. the node pointed to in the link part of head
        head = head->link;
        //Delete temp
        delete(temp);
        return;
    }
    //Recursively call delnoderec function with : node next to present node & the key
    delnoderec(head->link , key);
}