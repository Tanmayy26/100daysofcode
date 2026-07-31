/*Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createCircularList(int arr[], int n) {
    Node* head = new Node;
    head->data = arr[0];
    head->next = head;

    Node* last = head;

    for (int i = 1; i < n; i++) {
        Node* temp = new Node;
        temp->data = arr[i];
        temp->next = head;
        last->next = temp;
        last = temp;
        }
    return head;
}

void traverse(Node* head) {
    if (head == NULL) return;

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    Node* head = createCircularList(arr, n);
    traverse(head);

    return 0;
}
