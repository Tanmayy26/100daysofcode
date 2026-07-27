/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

int main() {
    int n, m, x;
    cin >> n;

    Node *head1 = NULL;
    Node *temp1 = NULL;
    Node *newnode;

    for(int i = 0; i < n; i++) {
        cin >> x;

        newnode = new Node;
        newnode->data = x;
        newnode->next = NULL;

        if(head1 == NULL) {
            head1 = newnode;
            temp1 = newnode;
        }
        else {
            temp1->next = newnode;
            temp1 = newnode;
        }
    }

    cin >> m;

    Node *head2 = NULL;
    Node *temp2 = NULL;

    for(int i=0; i<m; i++) {
        cin >> x;

        newnode = new Node;
        newnode->data = x;
        newnode->next = NULL;

        if(head2 == NULL) {
            head2 = newnode;
            temp2 = newnode;
        }
        else {
            temp2->next = newnode;
            temp2 = newnode;
        }
    }

    while(head1 != NULL && head2 != NULL) {
        if(head1->data < head2->data)
        {
            cout << head1->data << " ";
            head1 = head1->next;
        }
        else {
            cout << head2->data << " ";
            head2 = head2->next;
        }
    }

    while(head1 != NULL) {
        cout << head1->data << " ";
        head1 = head1->next;
    }

    while(head2 != NULL) {
        cout << head2->data << " ";
        head2 = head2->next;
    }

    return 0;
}