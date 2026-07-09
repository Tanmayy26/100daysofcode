/*Problem: You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.

Input:
- First line: two integers r and c representing the number of rows and columns
- Next r lines: c integers each representing the matrix elements

Output:
- Print all visited elements in the order of traversal, separated by spaces

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
1 2 3 6 9 8 7 4 5

Explanation:
The traversal begins along the top row, proceeds down the rightmost column, then moves across the bottom row in reverse, and finally goes up the leftmost column. The same pattern repeats for the inner submatrix.

Test Cases:

Test Case 1:
Input:
2 3
1 2 3
4 5 6
Output:
1 2 3 6 5 4

Test Case 2:
Input:
3 1
7
8
9
Output:
7 8 9*/
#include <iostream>
using namespace std;
int main() {
    int r, c;
    cin >> r >> c;

    int arr[100][100];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }

    int t = 0, b = r - 1;
    int l = 0, rt = c - 1;

    while (t <= b && l <= rt) {

        // Top
        for (int col = l; col <= rt; col++) {
            cout << arr[t][col] << " ";
        }
        t++;

        // Right
        for (int row = t; row <= b; row++) {
            cout << arr[row][rt] << " ";
        }
        rt--;

        // Bottom
        if (t <= b) {
            for (int col = rt; col >= l; col--) {
                cout << arr[b][col] << " ";
            }
            b--;
        }

        // Left
        if (l <= rt) {
            for (int row = b; row >= t; row--) {
                cout << arr[row][l] << " ";
            }
            l++;
        }
    }
    return 0;
}