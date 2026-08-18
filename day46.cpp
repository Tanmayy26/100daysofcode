/*Problem Statement:
Find the height (maximum depth) of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print the height of the tree

Example:
Input:
7
1 2 3 4 5 -1 -1

Output:
3*/

#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    int x;
    cin >> x;

    if (x == -1) {
        cout << 0;
        return 0;
    }

    Node* root = new Node(x);
    queue<Node*> q;
    q.push(root);

    int count = 1;

    while (!q.empty() && count < n) {
        Node* cur = q.front();
        q.pop();

        cin >> x;
        count++;

        if (x != -1) {
            cur->left = new Node(x);
            q.push(cur->left);
        }

        if (count < n) {
            cin >> x;
            count++;

            if (x != -1) {
                cur->right = new Node(x);
                q.push(cur->right);
            }
        }
    }

    q.push(root);
    int height = 0;

    while (!q.empty()) {
        int size = q.size();
        height++;

        while (size--) {
            Node* cur = q.front();
            q.pop();

            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }

    cout << height;
    return 0;
}