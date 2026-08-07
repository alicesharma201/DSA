#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
void print(ListNode* head){
    for(ListNode* temp = head; temp != nullptr; temp = temp->next){
        cout << temp->val << " ";
    }
    cout << endl;
}
void reverseLL(ListNode* head){
    ListNode* temp = head;
    ListNode* prev = nullptr;
    while(temp){
        ListNode* ahead = temp->next;
        temp->next = prev;
        prev = temp;
        temp = ahead;
    }
}
ListNode* findKth(ListNode* temp, int k){
    ListNode* Kth = temp;
    while(Kth){
        k--;
        if(k == 0) return Kth;
        Kth = Kth->next;
    }
    return nullptr;
}
ListNode* reverseKNodes(ListNode* head, int k){
    ListNode* temp = head;
    ListNode* nextNode = nullptr; // this will become Kth after reversal will get stored at temp
    ListNode* prevNode = nullptr; // this will become temp after reversal and point to Kth Node
    while(temp){
        ListNode* Kth = findKth(temp, k);
        if(Kth == nullptr){
            prevNode->next = temp;
            break;
        }
        nextNode = Kth->next;
        Kth->next = nullptr;
        reverseLL(temp);
        if(temp == head) head = Kth;
        else prevNode->next = Kth;
        prevNode = temp;
        temp = nextNode;
    }
    return head;
}
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);

    head = reverseKNodes(head, 3);
    print(head);

    return 0;
}