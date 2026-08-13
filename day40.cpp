/*Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10
30*/

#include <iostream>
#include <string>
using namespace std;

class MinHeap {
    int a[1000];
    int n;

public:
    MinHeap() {
        n = 0;
    }

    void insert(int x) {
        int i = n++;
        a[i] = x;

        while (i > 0) {
            int p = (i - 1) / 2;

            if (a[p] <= a[i])
                break;

            swap(a[p], a[i]);
            i = p;
        }
    }

    int peek() {
        if (n == 0)
            return -1;
        return a[0];
    }

    int extractMin() {
        if (n == 0)
            return -1;

        int x = a[0];
        a[0] = a[n - 1];
        n--;

        int i = 0;

        while (true) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            int s = i;

            if (l < n && a[l] < a[s])
                s = l;

            if (r < n && a[r] < a[s])
                s = r;

            if (s == i)
                break;

            swap(a[i], a[s]);
            i = s;
        }

        return x;
    }
};

int main() {
    int N;
    cin >> N;

    MinHeap h;

    while (N--) {
        string op;
        cin >> op;

        if (op == "insert") {
            int x;
            cin >> x;
            h.insert(x);
        }
        else if (op == "peek") {
            cout << h.peek() << '\n';
        }
        else if (op == "extractMin") {
            cout << h.extractMin() << '\n';
        }
    }
    return 0;
}