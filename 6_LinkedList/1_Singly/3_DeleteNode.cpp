#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int data1) : data(data1), next(nullptr) {}
};
Node* arr2LL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void print(Node* head){
    for(Node* temp = head; temp != nullptr; temp = temp->next){
        cout << temp->data << " ";
    }
    cout << endl;
}
Node* deleteHead(Node* head){
    // TC: O(1)
    if(head == nullptr) return head;
    Node* temp = head;
    head = head->next;
    delete temp; 
    return head;
}
Node* deleteTail(Node* head){
    // TC: O(n)
    if(head == nullptr || head->next == nullptr) return nullptr;
    Node* temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}
Node* deleteK(Node* head, int k){
    Node* temp = head;
    if(head == nullptr)
        return head;
    if(k == 1){ // to detele head
        head = head->next;
        delete temp;
        return head;
    }
    int cnt = 0;
    Node* prev = nullptr;
    while(temp != nullptr){ // TC: O(N)
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            delete temp;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    // this also handles the edge case of deleting the last element because it will become prev->next = nullptr
    return head;
}
int main(){
    vector<int> arr = {1, 2, 3, 4};
    Node* head = arr2LL(arr);
    // head = deleteHead(head);
    // head = deleteTail(head);
    head = deleteK(head, 2);
    print(head);
    return 0;
}