/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    stack<int> myStack;
    int current_number;

    for (int i = 0; i < n; ++i) {
        cin >> current_number;
        myStack.push(current_number);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        if (!myStack.empty()) {
            myStack.pop();
        } else {
            break;
        }
    }

    vector<int> result;
    while (!myStack.empty()) {
        result.push_back(myStack.top());
        myStack.pop();
    }
    
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    cout << endl;
    return 0;
}
