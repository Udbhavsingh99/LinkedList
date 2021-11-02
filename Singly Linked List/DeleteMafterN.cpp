#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
};

/*The main part of problem is to maintain proper link between nodes & make sure all the corner cases are handled*/
void skipMdeleteN(node* head, int M, int N)
{
    node* current = head;
    node* temp;
    int count;

    //Main loop that traverses through the whole list
    while(current)
    {
        //Skip M nodes
        for(count = 1; count<=M && current != NULL ; count++)
        {
            current = current->next;
        }
        //If we reach end of list , then return
        if(current == NULL)
        {
            return;
        }
        //Start from next node & delete N nodes
        temp = current->next;
        for(count = 1; count<=N && temp != NULL ; count++)
        {
            node* t = temp;
            temp = temp->next;
            free(t);
        }
        //Link the previous list with remaining nodes
        current->next = temp;
        //Set current pointer for next iteration
        current = temp;
    }

}