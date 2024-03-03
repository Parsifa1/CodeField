#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;
};

node* create(int n) {
    node *head, *tail;    //头指针，尾指针
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
    return head;
}

node* reverse(node* head) {
    // node *head2 = NULL;
    auto p = head;
    auto q = head->next;
    while(q) {
        p->next = q->next;
        q->next = head;
        head = q;
        q = p->next;
    }
    p = NULL;
    return head;
}

void print(node* head) {
    node* t = head;
    while (t != NULL) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

int main() {
    int n; cin >> n;
    auto x = create(n);
    print(x);
    print(reverse(x));

}
