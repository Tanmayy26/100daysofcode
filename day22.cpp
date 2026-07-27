/*Problem: Count Nodes in Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

int main() {
    int n, x;
    cin >> n;

    Node *head = NULL;
    Node *newnode, *temp;

    for(int i=0; i<n; i++) {
        cin >> x;

        newnode = new Node;
        newnode->data = x;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
        }
        else {
            temp = head;

            while(temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newnode;
        }
    }

    int count = 0;
    temp = head;

    while(temp != NULL) {
        count++;
        temp = temp->next;
    }

    cout << count;
    return 0;
}