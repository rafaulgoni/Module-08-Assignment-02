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

int findIndex(Node* head, int X) {
    int index = 0;
    while (head != nullptr) {
        if (head->val == X) {
            return index;
        }
        head = head->next;
        index++;
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node* head = nullptr;
        Node* tail = nullptr;
        int val;
        while (cin >> val && val != -1) {
            Node* newNode = new Node(val);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        int X;
        cin >> X;
        cout << findIndex(head, X) << endl;
    }
    return 0;
}
