#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* back;
    Node(int data1) : data(data1), next(nullptr), back(nullptr) {}
    Node(int data1, Node* next1, Node* back1) : data(data1), next(next1), back(back1) {}
};
void print(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node* insertBeforeHead(Node* head, int val){
    if(head == nullptr) return new Node(val, nullptr, nullptr);
    Node* newHead = new Node(val, head, nullptr);
    head->back = newHead;
    return newHead;
}
Node* insertBeforeTail(Node* head, int val){
    if(head == nullptr) return new Node(val, nullptr, nullptr);
    if(head->next == nullptr){
        Node* temp = new Node(val, head, nullptr);
        head->back = temp;
        return temp;
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* insert = new Node(val, temp, prev);
    prev->next = insert; 
    temp->back = insert;
    return head;
}
Node* insertBeforeKth(Node* head, int k, int val){
    // TC: O(n)
    if(k == 1){
        Node* temp = new Node(val, head, nullptr);
        head->back = temp;
        return temp;
    }
    if(head == nullptr) return nullptr;
    Node* temp = head;
    int cnt = 0;
    while(temp){
        cnt++;
        if(cnt == k){
            break;
        }
        temp = temp->next;
    }
    if(temp == nullptr) return head; // invalid k
    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}
void insertBeforeGivenNode(Node* temp, int val){
    // constraint: given node can't be head
    // TC: O(1)
    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
}
int main(){
    Node* head = new Node(1, nullptr, nullptr);
    head->next = new Node(2, nullptr, head);
    head->next->next = new Node(3, nullptr, head->next);
    head->next->next->next = new Node(4, nullptr, head->next->next);

    head = insertBeforeHead(head, 100);
    print(head);

    head = insertBeforeTail(head, 50);
    print(head);

    head = insertBeforeKth(head, 5, 300);
    print(head);

    insertBeforeGivenNode(head->next->next, 77);
    print(head);

    return 0;
}