//While Traversing the node we keep on incrementing the counter variable & move to the next node
#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
};



int countNodes(node* head)
{
    node* temp = head;
    int result = 0;
    if (head != NULL) {
        do {
            temp = temp->next;
            result++;
        } while (temp != head);
    }
    return result;
}