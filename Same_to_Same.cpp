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

void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

bool compare(Node* head1, Node* head2) {
    Node* temp1 = head1;
    Node* temp2 = head2;
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->val != temp2->val) {
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return (temp1 == NULL && temp2 == NULL);
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;
    int val;
    while (true) {
        cin >> val;
        if (val == -1) {
            break;
        }
        insert(head1, val);
    }
    while (true) {
        cin >> val;
        if (val == -1) {
            break;
        }
        insert(head2, val);
    }
    if (compare(head1, head2)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
