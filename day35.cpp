/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/
#include <iostream>
#include <sstream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void push(Node*& top, int x) {
    Node* n = new Node;
    n->data = x;
    n->next = top;
    top = n;
}

int pop(Node*& top) {
    int x = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return x;
}

int main() {
    Node* top = NULL;
    string line;

    getline(cin, line);
    stringstream ss(line);
    string s;

    while (ss >> s) {
        if (s[0] >= '0' && s[0] <= '9') {
            push(top, stoi(s));
        }
        else {
            int b = pop(top);
            int a = pop(top);
            int ans;

            if (s == "+")
                ans = a + b;
            else if (s == "-")
                ans = a - b;
            else if (s == "*")
                ans = a * b;
            else if (s == "/")
                ans = a / b;

            push(top, ans);
        }
    }

    cout << pop(top);
    return 0;
}