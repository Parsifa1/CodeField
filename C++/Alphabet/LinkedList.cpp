#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *next;
};

    int n; 
    node *head,*q;

void create() {
    head = NULL;
    q = NULL;
    for(int i=0;i<n;i++) {
        node* p = new node;
        cin>>p->data;
        p->next = NULL;
        if(head == NULL) {
            head = p;
        } else {
            q->next = p;
        }
        q = p;
    }
    
}

void insert(int x) {
    node* t = head;
    while(t!=NULL) {
        if(t->next->data > x) {
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
    node *t = head;
    while(t!=NULL) {
        cout<<t->data<<" ";
        t = t->next;
    }
    cout<<endl;
}

int main() {
    cin>>n;
    create();
    print();
    insert(6);
    print();
}   