/*Problem: Create and Traverse Singly Linked List

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
    int n;
    cin >> n;

    Node *head = NULL;
    Node *last = NULL;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;

        Node *p = new Node;

        (*p).data = num;
        (*p).next = NULL;

        if(head == NULL) {
            head = p;
            last = p;
        }
        else {
            (*last).next = p;
            last = p;
        }
    }

    Node *cur = head;

    while(cur != NULL) {
        cout << (*cur).data;

        if((*cur).next != NULL)
            cout << " ";

        cur = (*cur).next;
    }
    return 0;
}