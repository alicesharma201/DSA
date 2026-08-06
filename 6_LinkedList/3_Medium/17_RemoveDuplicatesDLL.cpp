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
Node* selfRemoveDuplicates(Node* head){
    // delete duplicate nodes one by one
    // TC: O(n)
    // SC: O(1)
    if(head == nullptr) return nullptr;
    Node* temp = head;
    while(temp){
        Node* prev = temp->back;
        Node* ahead = temp->next;
        if(prev && prev->data == temp->data){
            prev->next = ahead;
            if(ahead) ahead->back = prev;
            delete temp;
        }
        temp = ahead;
    }
    return head;
}
Node* removeDuplicates(Node* head){
    // skip and delete consecutive duplicate nodes and link to the next non duplicate node
    // TC: O(n)
    // SC: O(1)
    if(head == nullptr) return nullptr;
    Node* temp = head;
    while(temp && temp->next){
        Node* nextNode = temp->next;
        while(nextNode != nullptr && nextNode->data == temp->data){
            Node* toDelete = nextNode;
            nextNode = nextNode->next;
            delete toDelete;
        }
        temp->next = nextNode;
        if(nextNode) nextNode->back = temp;
        temp = temp->next;
    }
    return head;
}
int main(){
    Node* head = new Node(1);
    head->next = new Node(1, nullptr, head);
    head->next->next = new Node(1, nullptr, head->next);
    head->next->next->next = new Node(2, nullptr, head->next->next);
    head->next->next->next->next = new Node(3, nullptr, head->next->next->next);
    head->next->next->next->next->next = new Node(3, nullptr, head->next->next->next->next);
    head->next->next->next->next->next->next = new Node(4, nullptr, head->next->next->next->next->next);

    // print(selfRemoveDuplicates(head));
    print(removeDuplicates(head));

    return 0;
}