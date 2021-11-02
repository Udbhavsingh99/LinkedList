#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node* prev;
};

/*
Method 1 : Naive
Using three nested loops generate all triplets and check whether elements in the triplet sum up to x or not.
*/
int counttriplets(node* head , int x)
{
    node* ptr1 , * ptr2 , * ptr3;
    int count = 0;
    for(ptr1 = head ; ptr1 != NULL ; ptr1 = ptr1->next)
    {
        for(ptr2 = head ; ptr2 != NULL ; ptr2 = ptr2->next)
        {
            for(ptr3 = head ; ptr3 != NULL ; ptr3 = ptr3->next)
            {
                if(((ptr1->data) + (ptr2->data) + (ptr3->data)) == x)
                {
                    count++;
                }
            }
        }
    }
    return count;
}

/*
Method 2 : Hashing
Create a hash table with (key, value) tuples represented as (node data, node pointer) tuples. Traverse the doubly linked list and store each node’s data and its pointer pair(tuple) in the hash table. Now, generate each possible pair of nodes. For each pair of nodes, calculate the p_sum(sum of data in the two nodes) and check whether (x-p_sum) exists in the hash table or not. If it exists, then also verify that the two nodes in the pair are not same to the node associated with (x-p_sum) in the hash table and finally increment count. Return (count / 3) as each triplet is counted 3 times in the above process.
*/
//Use hashing after learning the data structure for better understanding

/*
Method 3 : 2 Pointer Approach
Traverse the doubly linked list from left to right. For each current node during the traversal, initialize two pointers first = pointer to the node next to the current node and last = pointer to the last node of the list. Now, count pairs in the list from first to last pointer that sum up to value (x – current node’s data) (algorithm described in this post). Add this count to the total_count of triplets. Pointer to the last node can be found only once in the beginning.
*/

int summation(node* first , node* second , int x)
{
    int count = 0;
    while(second->next != NULL)
    {
        second = second->next;
    }
    if(first != second && second->next != first)
    {
        if((first->data) = (second->data) == x)
        {
            count++;
            first = first->next;
            second = second->prev;
        }
        else
        {
            if((first->data) = (second->data) > x)
            {
                second = second->prev;
            }
            else
            {
                first = first->next;
            }
        }
    }
    return count;
}

int counttriplets(node* head , int x)
{
    //If list empty
    if(head == NULL)
    {
        return;
    }
    node *current , *first , *last;
    int count = 0;

    last = head;
    //Move last pointer to the last node of the list
    while(last->next != NULL)
    {
        last = last->next;
    }
    //Traversing Linked List
    for(current = head ; current != NULL ; current = current->next)
    {
        //for each current node
        first = current->next;
        // count pairs with sum(x - current->data) in the range
        // first to last and add it to the 'count' of triplets
        count += summation(first, last, x - current->data);
    }
    //required count of triplets
    return count;
}
