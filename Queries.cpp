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

void insertHead(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insertTail(Node*& head, int val) {
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

void deleteAtIndex(Node*& head, int index) {
    if (head == NULL) return;
    if (index == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    for (int i = 0; temp != NULL && i < index - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) return;
    Node* next = temp->next->next;
    delete temp->next;
    temp->next = next;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int Q;
    cin >> Q;
    Node* head = NULL;
    while (Q--) {
        int X, V;
        cin >> X >> V;
        if (X == 0) {
            insertHead(head, V);
        } else if (X == 1) {
            insertTail(head, V);
        } else if (X == 2) {
            deleteAtIndex(head, V);
        }
        printList(head);
    }
    return 0;
}
