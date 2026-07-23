#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int data1) : data(data1), next(nullptr){}
    Node(int data1, Node* next1) : data(data1), next(next1){}
};
void print(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node* insertHead(Node* head, int val){
    // TC: O(1)
    return new Node(val, head);
}
Node* insertTail(Node* head, int val){
    // TC: O(n)
    if(head == nullptr) return new Node(val);
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = new Node(val);
    return head;
}
Node* insertK(Node* head, int val, int k){
    // TC: O(n)
    if(k == 1) return new Node(val, head);
    if(head == nullptr) return nullptr;
    Node* temp = head;
    int cnt = 0;
    while(temp != nullptr){
        cnt++;
        if(cnt == k-1){ // stop at k-1
            Node* x = new Node(val, temp->next);
            temp->next = x;
            return head;
        }
        temp = temp->next;
    }
    return head;
}
Node* insertBeforeVal(Node* head, int val, int insert){
    // TC: O(n)
    // given that val is a guarenteed node
    if(head == nullptr) return nullptr;
    if(head->data == val) return new Node(insert, head); // if val is head
    Node* temp = head;
    while(temp->next != nullptr){
        if(temp->next->data == val){
            Node* x = new Node(insert, temp->next);
            temp->next = x;
            return head;
        }
        temp = temp->next;
    }
    return head;
}
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    print(head);
    cout << "Insert at head: "; head = insertHead(head, 5);
    print(head);
    cout << "Insert at head: "; head = insertTail(head, 7);
    print(head);
    cout << "Insert at tail: "; head = insertK(head, 8, 3);
    print(head);
    cout << "Insert before Value: "; head = insertBeforeVal(head, 8, 10);
    print(head);
    return 0;
}