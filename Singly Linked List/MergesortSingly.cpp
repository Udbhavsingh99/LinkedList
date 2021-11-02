/*
MergeSort(headRef)
1) If the head is NULL or there is only one element in the Linked List 
    then return.
2) Else divide the linked list into two halves.  
    FrontBackSplit(head, &a, &b); a and b are two halves 
3) Sort the two halves a and b.
    MergeSort(a);
    MergeSort(b);
4) Merge the sorted a and b (using SortedMerge() discussed here) 
and update the head pointer using headRef.
*headRef = SortedMerge(a, b); */

#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
};

node* sortedmerge(node* a , node* b);
void frontbacksplit(node* source, node** frontRef, node** backRef);

void mergesort(node** headref)
{
    node* head = *headref;
    node* a;
    node* b;
    
    if(head == NULL || head->next == NULL)
    {
        return;
    }

    frontbacksplit(head , &a , &b);

    mergesort(&a);
    mergesort(&b);
    *headref = sortedmerge(a,b);
}

node* sortedmerge(node* a , node* b)
{
    node* result = NULL;
    if(a == NULL)
    {
        return b;
    }
    else if(b == NULL)
    {
        return a;
    }
    if(a->data <= b->data)
    {
        result = a;
        result->next = sortedmerge(a->next , b);
    }
    else{
        result = b;
        result->next = sortedmerge(a , b->next);
    }
    return result;
}

void frontbacksplit(node* source , node** frontRef , node** backRef)
{
    node* fast;
    node* slow;
    slow = source;
    fast = source->next;
    while(fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}