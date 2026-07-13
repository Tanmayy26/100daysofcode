/*Problem: Given an array of integers, count the frequency of each distinct element and print the result.

Input:
- First line: integer n (size of array)
- Second line: n integers

Output:
- Print each element followed by its frequency in the format element:count

Example:
Input:
5
1 2 2 3 1

Output:
1:2 2:2 3:1*/
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;

    int arr[n];

    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for (int i=0; i<n; i++) {
        int flag = 0;
        for (int j=0; j<i; j++) {
            if (arr[i] == arr[j]) {
                flag = 1;
                break;
            }
        }

        if (flag == 1)
            continue;
            int count = 0;
            for (int j=0; j<n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        cout << arr[i] << ":" << count << " ";
    }
    return 0;
}