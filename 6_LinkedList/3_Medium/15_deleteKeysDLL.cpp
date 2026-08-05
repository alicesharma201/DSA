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
// cases: 
// 1. where no key is found
// 2. where any middle keys are deleted
// 3. where head is deleted
// 4. where tail is deleted
// 5. where everything is deleted
Node* selfDeleteKeys(Node* head, int key){
    // TC: O(n)
    // SC: O(1)
    Node* temp = head;
    while(temp){
        if(temp->data == key){
            Node* prev = temp->back;
            Node* ahead = temp->next;
            if(prev == NULL && ahead == NULL){
                delete temp;
                return NULL;
            }
            else if(prev == NULL){
                Node* toDelete = temp;
                temp = temp->next;
                temp->back = nullptr;
                head = temp;
                delete toDelete;
            }
            else if(ahead == NULL){
                Node* toDelete = temp;
                prev->next = nullptr;
                temp = nullptr;
                delete toDelete;
            }
            else{
                Node* toDelete = temp;
                prev->next = temp->next;
                ahead->back = temp->back;
                temp = temp->next;
                delete toDelete;
            }
        } else temp = temp->next;
    }
    return head;
}
Node* deleteKeys(Node* head, int key){
    // TC: O(n)
    // SC: O(1)
    Node* temp = head;
    while(temp){
        Node* prev = temp->back;
        Node* ahead = temp->next;
        if(temp->data == key){
            if(prev) prev->next = ahead;
            else head = ahead;
            if(ahead) ahead->back = prev;
            delete temp;
        }
        temp = ahead; // since we deleted temp, we will use the ahead we stored earlier instead of temp = temp->next 
    }
    return head;
}
int main(){
    Node* head = new Node(1);
    head->next = new Node(1, nullptr, head);
    head->next->next = new Node(3, nullptr, head->next);
    head->next->next->next = new Node(2, nullptr, head->next->next);
    head->next->next->next->next = new Node(1, nullptr, head->next->next->next);

    // print(selfDeleteKeys(head, 1));
    print(deleteKeys(head, 1));

    return 0;
}