/*Problem Statement:
Construct a Binary Tree from the given level-order traversal.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers (-1 represents NULL)

Output Format:
- Print inorder traversal of the constructed tree

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
4 2 5 1 3 6*/

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

    return 0;
}
