#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;
};

int n;
node *head, *tail;     //头指针，尾指针

void create() {
    node* t = new node;
    cin >> t->data, t->next = NULL;
    head = t, tail = t;
    for(int i = 1; i < n; i++) {
        node* p = new node;
        cin >> p->data;
        p->next = NULL;
        tail->next = p;
        tail = p;
    }
}

void insert(int x) {
    node* t = head;
    while (t != NULL) {
        if (t->next->data >= x) {
            node* p = new node;
            p->data = x;
            p->next = t->next;
            t->next = p;
            break;
        }
        t = t->next;
    }
}

void print() {
    node* t = head;
    while (t != NULL) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

int main() {
    cin >> n;
    create();
    print();
    insert(4);
    print();
}