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
};

Node* createList(int arr[], int n) {
    Node* head = new Node;
    head->data = arr[0];
    head->next = NULL;

    Node* last = head;
    for (int i=1; i<n; i++) {
        Node* temp = new Node;
        temp->data = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
    return head;
}

Node* rotateRight(Node* head, int k, int n) {
    if (!head || k == 0 || k % n == 0) return head;

    Node* tail = head;
    while (tail->next) tail = tail->next;
    tail->next = head;

    int steps = n - (k % n);
    Node* newTail = head;
    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i=0; i<n; i++) 
    cin >> arr[i];

    int k;
    cin >> k;

    Node* head = createList(arr, n);
    head = rotateRight(head, k, n);
    printList(head);

    return 0;
}
