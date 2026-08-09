/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        return 0;
    }

    Node* head = NULL;
    Node* tail = NULL;

    for (int i=0; i<n; i++) {
        int value;
        cin >> value;

        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int k;
    cin >> k;

    k = k % n;

    if (k == 0) {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        return 0;
    }

    tail->next = head;

    int steps = n - k;
    Node* newTail = head;

    for (int i=1; i<steps; i++) {
        newTail = newTail->next;
    }

    head = newTail->next;

    newTail->next = NULL;

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}