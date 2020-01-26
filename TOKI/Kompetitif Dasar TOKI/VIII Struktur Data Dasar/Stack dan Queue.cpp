#include <bits/stdc++.h>
using namespace std;
typedef struct node {
    int val;
    node * NextPtr, *PrevPtr;
}Node;
typedef Node * NodePtr;
NodePtr head = NULL, tail = NULL;
bool isEmpty() {
    return head == NULL;
}
void push_front(int n) {
    if(isEmpty()) {
        head = new Node;
        head->val = n;
        head->NextPtr = NULL;
        head->PrevPtr = NULL;
        tail = head;
        return;
    }
    NodePtr newNode = new Node;
    newNode->val = n;
    newNode->NextPtr = head;
    newNode->PrevPtr = NULL;
    head->PrevPtr = newNode;
    head = newNode;
}
void pop_front() {
    if(!isEmpty()) {
        NodePtr tmp = head;
        if(tail == head) {
            head = NULL;
            tail = NULL;
            delete tmp;
            return;
        }
        head = head->NextPtr;
        delete tmp;
    }
}
void push_back(int n) {
    if(isEmpty()) {
        head = new Node;
        head->val = n;
        head->NextPtr = NULL;
        head->PrevPtr = NULL;
        tail = head;
        return;
    }
    NodePtr newNode = new Node;
    newNode->val = n;
    newNode->NextPtr = NULL;
    newNode->PrevPtr = tail;
    tail->NextPtr = newNode;
    tail = newNode;
}
void pop_back() {
    if(!isEmpty()) {
        NodePtr tmp = tail;
        if(tail == head) {
            head = NULL;
            tail = NULL;
            delete tmp;
            return;
        }
        tail = tail->PrevPtr;
        delete tmp;
    }
}
void print() {
    if(!isEmpty()) {
        if(head == tail)
            cout<<head->val<<'\n';
        else {
            NodePtr curr = head;
            while(1) {
                cout<<curr->val<<'\n';
                if(curr == tail) break;
                curr = curr->NextPtr;
            }
        }
    }
}

int main() {
    int n;
    cin>>n;
    while(n--) {
        string cmd;
        cin>>cmd;
        if(cmd == "push_front") {
            int tmp;
            cin>>tmp;
            push_front(tmp);
        } else if(cmd == "pop_front")
            pop_front();
        else if(cmd == "push_back") {
            int tmp;
            cin>>tmp;
            push_back(tmp);
        } else
            pop_back();
    }
    print();
    return 0;
}