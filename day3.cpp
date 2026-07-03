/*Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"

Example:
Input:
5
10 20 30 40 50
30

Output:
Found at index 2
Comparisons = 3

Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons)*/
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[100];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    int compare = 0;

    for (int i = 0; i < n; i++) {
        compare++;

        if (arr[i] == k) {
            cout << "Found at index " << i << endl;
            cout << "Comparisons = " << compare;
            return 0;
        }
    }

    cout << "Not Found" << endl;
    cout << "Comparisons = " << compare;

    return 0; 
}
