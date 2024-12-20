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

void removeDuplicates(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* runner = current;
        while (runner->next != NULL) {
            if (runner->next->val == current->val) {
                Node* temp = runner->next;
                runner->next = runner->next->next;
                delete temp;
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
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
    Node* head = NULL;
    int val;
    while (true) {
        cin >> val;
        if (val == -1) {
            break;
        }
        insert(head, val);
    }
    removeDuplicates(head);
    printList(head);

    return 0;
}
