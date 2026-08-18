/*Problem Statement:
Perform inorder, preorder, and postorder traversals of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print inorder, preorder, and postorder traversals

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4 2 5 1 6 3 7
1 2 4 5 3 6 7
4 5 2 6 7 3 1*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n) || n == 0) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (a[0] == -1) return 0;

    Node* root = new Node(a[0]);
    queue<Node*> q;
    q.push(root);

    int idx = 1;
    while (!q.empty() && idx < n) {
        Node* curr = q.front();
        q.pop();

        if (idx < n) {
            if (a[idx] != -1) {
                curr->left = new Node(a[idx]);
                q.push(curr->left);
            }
            idx++;
        }

        if (idx < n) {
            if (a[idx] != -1) {
                curr->right = new Node(a[idx]);
                q.push(curr->right);
            }
            idx++;
        }
    }

    inorder(root);
    cout << "\n";

    preorder(root);
    cout << "\n";

    postorder(root);
    cout << "\n";

    return 0;
}
