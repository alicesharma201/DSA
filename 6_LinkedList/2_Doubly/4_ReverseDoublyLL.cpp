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
Node* bruteReverseDoublyLL(Node* head){
    // TC: O(2n)
    // SC: O(n)
    Node* temp = head;
    stack<int> st;
    while(temp){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}
Node* optimalReverseDoublyLL(Node* head){
    // TC: O(n)
    // SC: O(1)
    if(head == nullptr || head->next == nullptr) return head;
    Node* temp = head;
    Node* tempPtr = nullptr;
    while(temp){
        tempPtr = temp->back;
        temp->back = temp->next;
        temp->next = tempPtr;
        temp = temp->back; // the next becomes the back
    }
    /*
        [ ]-[ ]-[ ]-[ ]
                 |
              tempPtr
    we will return tempPtr->back as head because pointers have been reversed
    */
    return tempPtr->back;
}
int main(){
    Node* head = new Node(1, nullptr, nullptr);
    head->next = new Node(2, nullptr, head);
    head->next->next = new Node(3, nullptr, head->next);
    head->next->next->next = new Node(4, nullptr, head->next->next);

    // head = bruteReverseDoublyLL(head);
    // print(head);

    head = optimalReverseDoublyLL(head);   
    print(head);

    return 0;
}