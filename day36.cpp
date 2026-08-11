/*Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.*/
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

    for (int i=0; i<n; i++) {
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

    Node* temp = front;

    while (temp != NULL) {
        cout << temp->data;

        if (temp->next != NULL)
            cout << " ";

        temp = temp->next;
    }
    return 0;
}