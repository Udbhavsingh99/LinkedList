#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* link;
};

//Iterative :

/*To delete a node of a linked list recursively we need to do the following steps.

1.We pass node* (node pointer) as a reference to the function (as in node* &head)

2.Now since current node pointer is derived from previous node’s next (which is passed by reference) so now if the value of the current node pointer is changed, previous next node’s value also gets changed which is the required operation while deleting a node (i.e points previous node’s next to current node’s (containing key) next).

3.Find the node containing the given value.

4.Store this node to deallocate it later using free() function.

5.Change this node pointer so that it points to it’s next and by performing this previous node’s next also get properly linked.*/

int findlength(node *headref)
{
    node* current = headref;
    int cnt = 0;
    while(current != NULL)
    {
        cnt++;
        current = current->link;
    } 
    return cnt;
}

//Recursive solution

/*int getCount(head)
1) If head is NULL, return 0.
2) Else return 1 + getCount(head->next) */

int findlenrec(node* headref)
{
    if(headref == NULL)
    {
        return;
    }
    else
    {
        return 1+findlenrec(headref->link);
    }
}