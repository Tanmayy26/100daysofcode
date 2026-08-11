/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[1000];
    int size = 0;

    for (int i=0; i<n; i++) {
        string op;
        cin >> op;

        if (op == "insert") {
            int x;
            cin >> x;
            a[size] = x;
            size++;
        }
        else if (op == "delete") {
            if (size == 0) {
                cout << -1 << endl;
            }
            else {
                int pos = 0;

                for (int j=1; j < size; j++) {
                    if (a[j] < a[pos])
                        pos = j;
                }

                cout << a[pos] << endl;

                for (int j = pos; j < size - 1; j++)
                    a[j] = a[j + 1];

                size--;
            }
        }
        else if (op == "peek") {
            if (size == 0) {
                cout << -1 << endl;
            }
            else {
                int pos = 0;

                for (int j=1; j < size; j++) {
                    if (a[j] < a[pos])
                        pos = j;
                }

                cout << a[pos] << endl;
            }
        }
    }
    return 0;
}