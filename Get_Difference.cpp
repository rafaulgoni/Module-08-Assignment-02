#include <bits/stdc++.h>
using namespace std;

class Node {
    public: 
        int val;
        Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

int findDifference(Node* head) {
    // if (head == NULL) return 0;
    int maxVal = head->val;
    int minVal = head->val;
    Node* current = head;
    while (current != NULL) {
        if (current->val > maxVal) {
            maxVal = current->val;
            }
        if (current->val < minVal) {
            minVal = current->val;
        }
        current = current->next;
    }
    return maxVal - minVal;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int val;
    while (cin >> val && val != -1) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    cout << findDifference(head) << endl;
    return 0;
}
