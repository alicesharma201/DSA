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
Node* deleteHead(Node* head){
    // TC: O(1)
    if(head == nullptr || head->next == nullptr) return nullptr;

    Node* toDelete = head;
    head = head->next;

    head->back = nullptr;
    toDelete->next = nullptr;

    delete toDelete;
    return head;
}
Node* deleteTail(Node* head){
    // TC: O(n)
    if(head == nullptr || head->next == nullptr) return nullptr;

    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }

    Node* prev = temp->back;
    prev->next = nullptr;
    temp->back = nullptr;

    delete temp;
    return head;
}
Node* deleteK(Node* head, int k){
    // TC: O(n)
    if(head == nullptr) return nullptr;
    int cnt = 0;
    Node* temp = head;
    while(temp != nullptr){
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }
    if(temp == nullptr) return head; // invalid k
    Node* prev = temp->back;
    Node* ahead = temp->next;
    if(prev == nullptr && ahead == nullptr){ // single node
        delete temp;
        return nullptr;
    }
    else if(prev == nullptr){ // delete head
        ahead->back = nullptr;
        temp->next = nullptr;
        delete temp;
        return ahead;
    }
    else if(ahead == nullptr){ // delete tail
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return head;
    }
    prev->next = ahead;
    ahead->back = prev;
    temp->back = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}
int main(){
    Node* head = new Node(1, nullptr, nullptr);
    head->next = new Node(2, nullptr, head);
    head->next->next = new Node(3, nullptr, head->next);
    head->next->next->next = new Node(4, nullptr, head->next->next);
    // head = deleteHead(head);
    // head = deleteTail(head);
    head = deleteK(head, 2);
    print(head);
    return 0;
}