#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int>& arr){ // returns the address of the first node
    Node* head = new Node(arr[0]); // head points to first node
    Node* mover = head; // another pointer
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int lengthOfLL(Node* head){
    // TC: O(n)
    int cnt = 0;
    Node* temp = head;
    while(temp){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

bool checkIfPresent(Node* head, int val){
    // TC: O(n)
    Node* temp = head;
    while(temp){
        if(temp->data == val) return true;
        temp = temp->next;
    }
    return false;
}

int main(){
    vector<int> arr = {2, 5, 8, 7};

    Node x = Node(2, nullptr);
    Node* y = &x;
    cout << y << endl;
    cout << x.data << endl;
    cout << x.next << endl << endl;

    Node* z = new Node(arr[0], nullptr); // new gives a pointer to the memory allocation (new returns the address)
    cout << new Node(arr[0], nullptr) << endl;
    cout << z << endl;
    cout << (*z).data << endl;
    cout << z->next << endl << endl;
    
    cout << "Array to LinkedList: ";
    Node* head = convertArr2LL(arr);
    cout << head->data << endl << endl;

    cout << "Traversal of LinkedList: ";
    Node* temp = head;
    while(temp){ // TC: O(n)
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl << endl;

    cout << "Length of LinkedList: " << lengthOfLL(head) << endl << endl;

    cout << "Check if Element is Present in LinkedList: " << checkIfPresent(head, 8) << endl;

    return 0;
}