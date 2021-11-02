//Intersection point of two linked lists
#include<iostream>
using namespace std;

class node
{
    public:
    node* next;
    int data;
};

//1.Simply Use 2 loops
/*Use 2 nested for loops. The outer loop will be for each node of the 1st list and inner loop will be for 2nd list. In the inner loop, check if any of nodes of the 2nd list is same as the current node of the first linked list. The time complexity of this method will be O(M * N) where m and n are the numbers of nodes in two lists.*/

//2.Mark Visited Nodes
/*This solution requires modifications to basic linked list data structure. Have a visited flag with each node. Traverse the first linked list and keep marking visited nodes. Now traverse the second linked list, If you see a visited node again then there is an intersection point, return the intersecting node. This solution works in O(m+n) but requires additional information with each node. A variation of this solution that doesn’t require modification to the basic data structure can be implemented using a hash. Traverse the first linked list and store the addresses of visited nodes in a hash. Now traverse the second linked list and if you see an address that already exists in the hash then return the intersecting node.*/

//3.Using Difference of Node counts
/*Get count of the nodes in the first list, let count be c1.
Get count of the nodes in the second list, let count be c2.
Get the difference of counts d = abs(c1 – c2)
Now traverse the bigger list from the first node till d nodes so that from here onwards both the lists have equal no of nodes
Then we can traverse both the lists in parallel till we come across a common node. (Note that getting a common node is done by comparing the address of the nodes)*/
/* function to get the intersection point of two linked
lists head1 and head2 */
int getIntesectionNode(node* head1, node* head2)
{
    // Count the number of nodes in
    // both the linked list
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d;
    // If first is greater
    if (c1 > c2) {
        d = c1 - c2;
        return _getIntesectionNode(d, head1, head2);
    }
    else {
        d = c2 - c1;
        return _getIntesectionNode(d, head2, head1);
    }
}
/* function to get the intersection point of two linked
lists head1 and head2 where head1 has d more nodes than
head2 */
int _getIntesectionNode(int d, node* head1, node* head2)
{
    // Stand at the starting of the bigger list
    node* current1 = head1;
    node* current2 = head2;
    // Move the pointer forward
    for (int i = 0; i < d; i++) {
        if (current1 == NULL) {
            return -1;
        }
        current1 = current1->next;
    }
    // Move both pointers of both list till they
    // intersect with each other
    while (current1 != NULL && current2 != NULL) {
        if (current1 == current2)
            return current1->data;
        // Move both the pointers forward
        current1 = current1->next;
        current2 = current2->next;
    }
    return -1;
}

//4.Make Circle in First List
/*1. Traverse the first linked list(count the elements) and make a circular linked list. (Remember the last node so that we can break the circle later on). 
2. Now view the problem as finding the loop in the second linked list. So the problem is solved. 
3. Since we already know the length of the loop(size of the first linked list) we can traverse those many numbers of nodes in the second list, and then start another pointer from the beginning of the second list. we have to traverse until they are equal, and that is the required intersection point. 
4. remove the circle from the linked list. */

//5.Reverse the First List & make equations
/*1) Let X be the length of the first linked list until intersection point.
   Let Y be the length of the second linked list until the intersection point.
   Let Z be the length of the linked list from the intersection point to End of
   the linked list including the intersection node.
   We Have
        X + Z = C1;
        Y + Z = C2;
2) Reverse first linked list.
3) Traverse Second linked list. Let C3 be the length of second list - 1. 
    Now we have
        X + Y = C3
    We have 3 linear equations. By solving them, we get
    X = (C1 + C3 – C2)/2;
    Y = (C2 + C3 – C1)/2;
    Z = (C1 + C2 – C3)/2;
    WE GOT THE INTERSECTION POINT.
4)  Reverse first linked list.*/

//6.Traverse both lists & compare addresses of last nodes
/*This method is only to detect if there is an intersection point or not. (Thanks to NeoTheSaviour for suggesting this)  

1) Traverse the list 1, store the last node address
2) Traverse the list 2, store the last node address.
3) If nodes stored in 1 and 2 are same then they are intersecting.*/

//7.Use Hashing
/*Basically, we need to find a common node of two linked lists. So we hash all nodes of the first list and then check the second list. 
1) Create an empty hash set. 
2) Traverse the first linked list and insert all nodes’ addresses in the hash set. 
3) Traverse the second list. For every node check if it is present in the hash set. If we find a node in the hash set, return the node.*/

//8.2-pointer Technique
/*Using Two pointers : 

Initialize two pointers ptr1 and ptr2  at the head1 and  head2.
Traverse through the lists,one node at a time.
When ptr1 reaches the end of a list, then redirect it to the head2.
similarly when ptr2 reaches the end of a list, redirect it the head1.
Once both of them go through reassigning, they will be equidistant from 
the collision point
If at any node ptr1 meets ptr2, then it is the intersection node.
After second iteration if there is no intersection node it returns NULL.*/

// A utility function to return  intersection node
node* intersectPoint(node* head1, node* head2)
{
    // Maintaining two pointers ptr1 and ptr2
    // at the head of A and B,
    node* ptr1 = head1;
    node* ptr2 = head2;
    // If any one of head is NULL i.e
    // no Intersection Point
    if (ptr1 == NULL || ptr2 == NULL)
    {
        return NULL;
    }
    // Traverse through the lists until they
    // reach Intersection node
    while (ptr1 != ptr2) 
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        // If at any node ptr1 meets ptr2, then it is
        // intersection node.Return intersection node.
        if (ptr1 == ptr2) 
        {
            return ptr1;
        }
        /* Once both of them go through reassigning,
        they will be equidistant from the collision point.*/
        // When ptr1 reaches the end of a list, then
        // reassign it to the head2.
        if (ptr1 == NULL) 
        {
            ptr1 = head2;
        }
        // When ptr2 reaches the end of a list, then
        // redirect it to the head1.
        if (ptr2 == NULL) 
        {
            ptr2 = head1;
        }
    }
    return ptr1;
}