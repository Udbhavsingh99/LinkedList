#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node* prev;
};
/*Algorithm
Let the node to be deleted be del.
If node to be deleted is head node, then change the head pointer to next current head.
if headnode == del then
    headnode =  del.nextNode
Set next of previous to del, if previous to del exists.
if del.nextNode != none 
    del.nextNode.previousNode = del.previousNode 
Set prev of next to del, if next to del exists.
if del.previousNode != none 
    del.previousNode.nextNode = del.next
*/
//Given input :
/* Function to delete a node in a Doubly Linked List.
head_ref --> pointer to head node pointer.
del --> pointer to node to be deleted. */
void deletenode(node** head , node* del)
{
    //If the head of the linked list is NULL or the pointer to the node passed to be deleted is NULL
    if(*head == NULL || del == NULL)
    {
        //Then return
        return;
    }
    //If head points to the node to be deleted
    if(*head == del)
    {
        //Make head point to the node next to present del ie. make head point to the node next to where presently head points to
        (*head) = del->next;
    }
    //Check if the next pointer of del points to NULL ie. we ensure that we are not at the end of the linked list
    if(del->next != NULL)
    {
        /*Then we change the location/node to which the previous pointer of the node next to present del points to , to the location where the previous pointer of del node points to ie. we link the prev pointer of node next to present del to the node that prev pointer of del points to*/
        del->next->prev = del->prev;
    }
    //If the prev pointer of del is not NULL ie. prev pointer of del points to some node which implies that del is not the first node
    if (del->prev != NULL)
    {
        /*Then we change the location/node to which the next pointer of the node previos to the present del points to , to the location where the next pointer of del points to ie. we link the the next pointer of node before the present del to the node that next pointer of del points to (ie. the next node of present del)*/
        del->prev->next = del->next;
    }
    //We free the memory allocated to del
    free(del);
    return;
}


/*The deletion of a node in a doubly-linked list can be divided into three main categories: 
After the deletion of the head node. 
After the deletion of the middle node. 
After the deletion of the last node.
All three mentioned cases can be handled in two steps if the pointer of the node to be deleted and the head pointer is known. 
1.If the node to be deleted is the head node then make the next node as head.
2.If a node is deleted, connect the next and previous node of the deleted node.*/
