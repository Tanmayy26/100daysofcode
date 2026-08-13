/*Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int x) {
        Node* temp = new Node(x);

        if (rear == NULL) {
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }

    void dequeue() {
        if (front == NULL) {
            cout << -1 << endl;
            return;
        }

        Node* temp = front;
        cout << front->data << endl;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
    }
};

int main() {
    int n;
    cin >> n;

    Queue q;

    while (n--) {
        string op;
        cin >> op;

        if (op == "enqueue") {
            int x;
            cin >> x;
            q.enqueue(x);
        }
        else if (op == "dequeue") {
            q.dequeue();
        }
    }
    return 0;
}