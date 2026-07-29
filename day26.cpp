/*Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.*/
#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
    node *prev;
};

int main() {
    int n;
    cin >> n;

    node *head = NULL;
    node *last = NULL;

    for(int i=0; i<n; i++) {
        node *p = new node;

        cin >> p->data;
        p->next = NULL;
        p->prev = NULL;

        if(head == NULL) {
            head = p;
            last = p;
        }
        else {
            last->next = p;
            p->prev = last;
            last = p;
        }
    }

    node *t = head;

    while(t != NULL) {
        cout << t->data << " ";
        t = t->next;
    }
    return 0;
}