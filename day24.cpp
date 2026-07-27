/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

int main() {
    int n, x, key;
    cin >> n;

    Node *head = NULL;
    Node *last = NULL;
    Node *newnode;

    for(int i=0; i<n; i++) {
        cin >> x;

        newnode = new Node;
        newnode->data = x;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            last = newnode;
        }
        else {
            last->next = newnode;
            last = newnode;
        }
    }

    cin >> key;

    Node *temp = head;
    Node *prev = NULL;

    while(temp != NULL) {
        if(temp->data == key) {
            if(prev == NULL) {
                head = temp->next;
            }
            else {
                prev->next = temp->next;
            }
            delete temp;
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    temp = head;

    while(temp != NULL) {
        cout << temp->data;

        if(temp->next != NULL)
            cout << " ";

        temp = temp->next;
    }
    return 0;
}