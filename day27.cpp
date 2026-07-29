/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/
#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

int main() {
    int n, m;
    cin >> n;

    node *head1 = NULL, *temp1 = NULL;

    for(int i=0; i<n; i++) {
        node *newnode = new node;
        cin >> newnode->data;
        newnode->next = NULL;

        if(head1 == NULL) {
            head1 = newnode;
            temp1 = newnode;
        }
        else {
            temp1->next = newnode;
            temp1 = newnode;
        }
    }

    cin >> m;

    node *head2 = NULL, *temp2 = NULL;

    for(int i=0; i<m; i++) {
        node *newnode = new node;
        cin >> newnode->data;
        newnode->next = NULL;

        if(head2 == NULL) {
            head2 = newnode;
            temp2 = newnode;
        }
        else {
            temp2->next = newnode;
            temp2 = newnode;
        }
    }

    bool flag = false;

    for(temp1 = head1; temp1 != NULL; temp1 = temp1->next) {
        for(temp2 = head2; temp2 != NULL; temp2 = temp2->next) {
            if(temp1->data == temp2->data)
            {
                cout << temp1->data;
                flag = true;
                break;
            }
        }

        if(flag)
            break;
    }

    if(flag == false)
        cout << "No Intersection";

    return 0;
}