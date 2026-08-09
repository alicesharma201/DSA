#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node* random;
    Node(int x) : val(x), next(nullptr), random(nullptr) {}
    Node(int x, Node* next, Node* random) : val(x), next(next), random(random) {}
};
void printNextAndRandom(Node* head){
    for(Node* temp = head; temp != nullptr; temp = temp->next){
        cout << temp->val << " ";
    }
    cout << endl;
    for(Node* temp = head; temp != nullptr; temp = temp->random){
        cout << temp->val << " ";
    }
    cout << endl;
}
Node* bruteClone(Node* head){
    // TC: O(2n)
    // SC: O(2n) for hashmap & cloned LL
    unordered_map<Node*,Node*> hash;
    Node* temp = head;
    while(temp){
        hash[temp] = new Node(temp->val);
        temp = temp->next;
    }
    temp = head;
    while(temp){
        Node* clone = hash[temp];
        clone->next = hash[temp->next];
        clone->random = hash[temp->random];
        temp = temp->next;
    }
    return hash[head];
}
Node* optimalClone(Node* head){
    // TC: O(3n)
    // SC: O(n) for cloned LL

    Node* temp = head;
    Node* clone = nullptr;

    // insert copied nodes in between
    while(temp){
        clone = new Node(temp->val);
        clone->next = temp->next;
        temp->next = clone;
        temp = temp->next->next;
    }

    // connect random pointers
    temp = head;
    while(temp){
        clone = temp->next;
        if(temp->random) clone->random = temp->random->next;
        else clone->random = nullptr;
        temp = temp->next->next;
    }

    // connect next pointers
    Node* dummy = new Node(-1);
    Node* move = dummy;
    temp = head;
    while(temp){
        move->next = temp->next;
        temp->next = temp->next->next;
        move = move->next;
        temp = temp->next;
    }

    return dummy->next;
}
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->random = head->next->next; // 1 -> 3
    head->random->random = head->next->next->next; // 3 -> 4
    head->random->random->random = head->next; // 4 -> 2
    head->random->random->random->random = head->next->next->next->next; // 2 -> 5

    // head = bruteClone(head);
    head = optimalClone(head);
    printNextAndRandom(head);

    return 0;
}