/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    int n;
    cin >> n;

    Node* front = NULL;
    Node* rear = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = NULL;

        if (front == NULL) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    rear->next = front;

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        front = front->next;
    }

    Node* temp = front;

    for (int i = 0; i < n; i++) {
        cout << temp->data;

        if (i < n - 1)
            cout << " ";

        temp = temp->next;
    }

    return 0;
}