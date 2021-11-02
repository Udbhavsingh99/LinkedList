#include<iostream>
#include<stack>
using namespace std;

class node
{
    public:
    node* next;
    int data;
};

//Stack 
/*A simple solution is to use a stack of list nodes. This mainly involves three steps.
Traverse the given list from head to tail and push every visited node to stack.
Traverse the list again. For every visited node, pop a node from the stack and compare data of popped node with the currently visited node.
If all nodes matched, then return true, else false.*/

// Function to check if the linked list
// is palindrome or not
bool isPalindrome(node* head){
        // Temp pointer
        node* slow= head;
        // Declare a stack
        stack <int> s;
        // Push all elements of the list
        // to the stack
        while(slow != NULL){
                s.push(slow->data);
                // Move ahead
                slow = slow->next;
        }
        // Iterate in the list again and
        // check by popping from the stack
        while(head != NULL ){
            // Get the top most element
            int i=s.top();
             // Pop the element
            s.pop();
             // Check if data is not
             // same as popped element
            if(head -> data != i){
                return false;
            }
            // Move ahead
        head=head->next;
        }
return true;
}

//Reversing List
/*This method takes O(n) time and O(1) extra space. 
1) Get the middle of the linked list. 
2) Reverse the second half of the linked list. 
3) Check if the first half and second half are identical. 
4) Construct the original linked list by reversing the second half again and attaching it back to the first half*/

// Function to check if given linked list is
// palindrome or not
bool isPalindrome(node* head)
{
    node *slow_ptr = head, *fast_ptr = head;
    node *second_half, *prev_of_slow_ptr = head;
    // To handle odd size list
    node* midnode = NULL;
    // initialize result
    bool res = true;
    if (head != NULL && head->next != NULL)
    {
        // Get the middle of the list. Move slow_ptr by 1
        // and fast_ptr by 2, slow_ptr will have the middle
        // node
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            // We need previous of the slow_ptr for
            // linked lists with odd elements
            prev_of_slow_ptr = slow_ptr;
            slow_ptr = slow_ptr->next;
        }
        // fast_ptr would become NULL when there
        // are even elements in list. And not NULL
        // for odd elements. We need to skip the
        // middle node for odd case and store it
        // somewhere so that we can restore the
        // original list
        if (fast_ptr != NULL)
        {
            midnode = slow_ptr;
            slow_ptr = slow_ptr->next;
        }
        // Now reverse the second half and
        // compare it with first half
        second_half = slow_ptr;
        // NULL terminate first half
        prev_of_slow_ptr->next = NULL;
        // Reverse the second half
        reverse(&second_half);
        // compare
        res = compareLists(head, second_half);
        // Construct the original list back
        reverse(&second_half); // Reverse the second half again
        // If there was a mid node (odd size case)
        // which was not part of either first half
        // or second half.
        if (midnode != NULL)
        {
            prev_of_slow_ptr->next = midnode;
            midnode->next = second_half;
        }
        else
            prev_of_slow_ptr->next = second_half;
    }
    return res;
}
// Function to reverse the linked list
// Note that this function may change
// the head
void reverse(node** head_ref)
{
    node* prev = NULL;
    node* current = *head_ref;
    node* next;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
// Function to check if two input
// lists have same data
bool compareLists(node* head1, node* head2)
{
    node* temp1 = head1;
    node* temp2 = head2;

    while (temp1 && temp2)
    {
        if (temp1->data == temp2->data)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
            return 0;
    }
    // Both are empty return 1
    if (temp1 == NULL && temp2 == NULL)
        return 1;
    // Will reach here when one is NULL
    // and other is not
    return 0;
}

// Push a node to linked list. Note
// that this function changes the head
void push(node** head_ref, int new_data)
{
    // Allocate node
    node* new_node = (node*)malloc(
        sizeof(node));
    // Put in the data
    new_node->data = new_data;
    // Link the old list off the new node
    new_node->next = (*head_ref);
    // Move the head to char to the new node
    (*head_ref) = new_node;
}

// A utility function to print a given linked list
void printList(node* ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL" << "\n";
}

//Recursion 
/*Use two pointers left and right. Move right and left using recursion and check for following in each recursive call. 
1) Sub-list is a palindrome. 
2) Value at current left and right are matching.

If both above conditions are true then return true.

The idea is to use function call stack as a container. Recursively traverse till the end of list. When we return from last NULL, we will be at the last node. The last node to be compared with first node of list.

In order to access first node of list, we need list head to be available in the last call of recursion. Hence, we pass head also to the recursive function. If they both match we need to compare (2, n-2) nodes. Again when recursion falls back to (n-2)nd node, we need reference to 2nd node from the head. We advance the head pointer in the previous call, to refer to the next node in the list.
However, the trick is identifying a double-pointer. Passing a single pointer is as good as pass-by-value, and we will pass the same pointer again and again. We need to pass the address of the head pointer for reflecting the changes in parent recursive calls.*/

// Initial parameters to this function are &head and head
bool isPalindromeUtil(struct node** left, struct node* right)
{
    /* stop recursion when right becomes NULL */
    if (right == NULL)
        return true;
    /* If sub-list is not palindrome then no need to
    check for current left and right, return false */
    bool isp = isPalindromeUtil(left, right->next);
    if (isp == false)
        return false;
    /* Check values at current left and right */
    bool isp1 = (right->data == (*left)->data);
    /* Move left to next node */
    *left = (*left)->next;
    return isp1;
}
// A wrapper over isPalindromeUtil()
bool isPalindrome(struct node* head)
{
    isPalindromeUtil(&head, head);
}
/* Push a node to linked list. Note that this function
changes the head */
void push(struct node** head_ref, char new_data)
{
    /* allocate node */
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    /* put in the data */
    new_node->data = new_data;
    /* link the old list off the new node */
    new_node->next = (*head_ref);
    /* move the head to char to the new node */
    (*head_ref) = new_node;
}

