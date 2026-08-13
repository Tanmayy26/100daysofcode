/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    queue<int> q;
    stack<int> s;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}