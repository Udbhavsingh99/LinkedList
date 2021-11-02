#include<iostream>
using namespace std;

class node
{
    public:
    node*next;
    int data;
};

/*Implementation of insertion
To implement a circular singly linked list, we take an external pointer that points to the last node of the list. If we have a pointer last pointing to the last node, then last -> next will point to the first node. 
The pointer last points to node Z and last -> next points to node P.

For the insertion of a node at the beginning, we need to traverse the whole list. Also, for insertion at the end, the whole list has to be traversed. If instead of start pointer, we take a pointer to the last node, then in both cases there won’t be any need to traverse the whole list. So insertion at the beginning or at the end takes constant time, irrespective of the length of the list.*/

/*Insertion Methods
A node can be added in three ways: 

Insertion in an empty list
Insertion at the beginning of the list
Insertion at the end of the list
Insertion in between the nodes
*/

/*Insertion in an empty list
1.Initially, when the list is empty, the last pointer will be NULL. 
2.After insertion, T is the last node, so the pointer last points to node T. And Node T is the first and the last node, so T points to itself. */
node *addToEmpty(node *last, int data)
{
    // This function is only for empty list
    if (last != NULL)
    return last;
    // Creating a node dynamically.
    node *temp =
        (node*)malloc(sizeof(node));
    // Assigning the data.
    temp-> data = data;
    last = temp;
    // Note : list was empty. We link single node
    // to itself.
    temp-> next = last;
    return last;
}

/*Insertion at the beginning of the list
To insert a node at the beginning of the list, follow these steps: 
1. Create a node, say T. 
2. Make T -> next = last -> next. 
3. last -> next = T. */
node *addBegin(node *last, int data)
{
if (last == NULL)
    return addToEmpty(last, data);
  // Creating a node dynamically.
     node *temp
        = (node *)malloc(sizeof(node));
  // Assigning the data.
temp-> data = data;
  // Adjusting the links.
temp-> next = last-> next;
last-> next = temp;
return last;
}

/*Insertion at the end of the list
To insert a node at the end of the list, follow these steps: 
1. Create a node, say T. 
2. Make T -> next = last -> next; 
3. last -> next = T. 
4. last = T. */
node *addEnd(node *last, int data)
{
if (last == NULL)
    return addToEmpty(last, data);

  // Creating a node dynamically.
  node *temp =
        (node*)malloc(sizeof(node));
  // Assigning the data.
temp -> data = data;
  // Adjusting the links.
temp -> next = last -> next;
last -> next = temp;
last = temp;
return last;
}

/*Insertion in between the nodes
To insert a node in between the two nodes, follow these steps: 
1. Create a node, say T. 
2. Search for the node after which T needs to be inserted, say that node is P. 
3. Make T -> next = P -> next; 
4. P -> next = T.*/


node *addAfter(node *last, int data, int item)
{
    if (last == NULL)
    return NULL;
    node *temp, *p;
    p = last -> next;
    // Searching the item.
    do
    {
        if (p ->data == item)
        {
            // Creating a node dynamically.
            temp = (node *)malloc(sizeof(node));
            // Assigning the data.
            temp -> data = data;
            // Adjusting the links.
            temp -> next = p -> next;
            // Adding newly allocated node after p.
            p -> next = temp;
            // Checking for the last node.
            if (p == last)
                last = temp;
            return last;
        }
        p = p -> next;
    } while (p != last -> next);
    cout << item << " not present in the list." << endl;
    return last;
}

/*All code
struct Node *addToEmpty(struct Node *last, int data)
{
    // This function is only for empty list
    if (last != NULL)
    return last;
    // Creating a node dynamically.
    struct Node *temp =
        (struct Node*)malloc(sizeof(struct Node));
    // Assigning the data.
    temp -> data = data;
    last = temp;
    // Creating the link.
    last -> next = last;
    return last;
}
struct Node *addBegin(struct Node *last, int data)
{
    if (last == NULL)
        return addToEmpty(last, data);
    struct Node *temp =
            (struct Node *)malloc(sizeof(struct Node));
    temp -> data = data;
    temp -> next = last -> next;
    last -> next = temp;
    return last;
}
struct Node *addEnd(struct Node *last, int data)
{
    if (last == NULL)
        return addToEmpty(last, data);
    
    struct Node *temp =
        (struct Node *)malloc(sizeof(struct Node));
    temp -> data = data;
    temp -> next = last -> next;
    last -> next = temp;
    last = temp;
    return last;
}
struct Node *addAfter(struct Node *last, int data, int item)
{
    if (last == NULL)
        return NULL;
    struct Node *temp, *p;
    p = last -> next;
    do
    {
        if (p ->data == item)
        {
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp -> data = data;
            temp -> next = p -> next;
            p -> next = temp;
            if (p == last)
                last = temp;
            return last;
        }
        p = p -> next;
    }  while(p != last -> next);
    cout << item << " not present in the list." << endl;
    return last;
}
void traverse(struct Node *last)
{
    struct Node *p;
    // If list is empty, return.
    if (last == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    // Pointing to first Node of the list.
    p = last -> next;
    // Traversing the list.
    do
    {
        cout << p -> data << " ";
        p = p -> next;
    }
    while(p != last->next);
} */