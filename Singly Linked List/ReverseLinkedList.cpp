//Reverse a linked list
#include<iostream>
#include<stack>
using namespace std;

class node
{
    public:
    node* next;
    int data;
};

//Iterative Method
/*Initialize three pointers prev as NULL, curr as head and next as NULL.
Iterate through the linked list. In loop, do following. 
// Before changing next of current, 
// store next node 
next = curr->next
// Now change next of current 
// This is where actual reversing happens 
curr->next = prev 
// Move prev and curr one step forward 
prev = curr 
curr = next*/

struct LinkedList 
{
    node* head;
    LinkedList() { head = NULL; }
    /* Function to reverse the linked list */
    void reverse()
    {
        // Initialize current, previous and
        // next pointers
        node* current = head;
        node *prev = NULL, *next;
        while (current != NULL) 
        {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }
}

//Recursive
/*1) Divide the list in two parts - first node and 
    rest of the linked list.
2) Call reverse for the rest of the linked list.
3) Link rest to first.
4) Fix head pointer*/
struct LinkedListrec 
{
    node* head;
    LinkedListrec()
    {
        head = NULL;
    }
    node* reverse(node* head)
    {
        if(head == NULL || head->next == NULL)
            return head;
        /* reverse the rest list and put
          the first element at the end */
        node* rest = reverse(head->next);
        head->next->next = head;
        /* tricky step -- see the diagram */
        head->next = NULL;
        /* fix the head pointer */
        return rest;
    }
}

//Tail recursive implementation
void reverseUtil(node* curr, node* prev, node** head);
// This function mainly calls reverseUtil()
// with prev as NULL
void reverse(node** head)
{
    if (!head)
        return;
    reverseUtil(*head, NULL, head);
}
// A simple and tail-recursive function to reverse
// a linked list.  prev is passed as NULL initially.
void reverseUtil(node* curr, node* prev, node** head)
{
    /* If last node mark it head*/
    if (!curr->next) {
        *head = curr;
        /* Update next to prev node */
        curr->next = prev;
        return;
    }
    /* Save curr->next node for recursive call */
    node* next = curr->next;
    /* and update next ..*/
    curr->next = prev;
    reverseUtil(next, curr, head);
}

//Using Stack
/*Store the nodes(values and address) in the stack until all the values are entered.
Once all entries are done, Update the Head pointer to the last location(i.e the last value).
Start popping the nodes(value and address) and store them in the same order until the stack is empty.
Update the next pointer of last Node in the stack by NULL.*/

void reverseLL(node** head)
{  
    // Create a stack "s"
    // of Node type
    stack<node*> s;
    node* temp = *head;
    while (temp->next != NULL)
    {
        // Push all the nodes
        // in to stack
        s.push(temp);
        temp = temp->next;
    }
    *head = temp;
    while (!s.empty())
    {
        // Store the top value of
        // stack in list
        temp->next = s.top();
        // Pop the value from stack
        s.pop();
        // update the next pointer in the
        // in the list
        temp = temp->next;
    }
    temp->next = NULL;
}

//Using Array
/*1. Create a linked list.

2. Then, make a count(head) function to count the number of nodes.

3. Initialize an array with the size of the count.

4. and start a while(p->next!=NULL) loop and store all the node’s data into the array.

5. and then print the array from the last index to the first.*/

int count(node* head) // code to count the no. of nodes
{
  node* p=head;
  int k=1;
  while(p!=NULL)
  {
    p=p->next;
    k++;
  }
  return k;
}
 
node *ll_reverse(node* head)  // to reverse the linked list
{
  node* p=head;
  long int i=count(head),j=1;
  long int arr[i];
  while(i && p!=NULL)
  {
    arr[j++]=p->val;
    p=p->next;
    i--;
  }
  j--;
  while(j) // loop will break as soon as j=0
  {
    cout<<arr[j--]<<" ";
  }
   
  return head;
}
 
node* insert_end(node* head,int data)  //code to insert at end of ll
{
  node* q=head,*p=(node*)malloc(sizeof(node));
  p->data=data;
  while(q->next!=NULL)
  {
    q=q->next;
  }
  q->next=p;
  p->next=NULL;
  return head;
}
 
node *create_ll(node* head,int data)  //create ll
{
  node* p=(node*)malloc(sizeof(node));
  p->data=data;
  if(head==NULL)
  {
    head=p;
    p->next=NULL;
    return head;
  }
  else
  {
    head=insert_end(head,data);
    return head;
  }
}