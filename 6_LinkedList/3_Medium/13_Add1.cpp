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
ListNode* reverseLL(ListNode* head){
    ListNode* prev = nullptr;
    ListNode* temp = head;
    while(temp){
        ListNode* ahead = temp->next;
        temp->next = prev;
        prev = temp;
        temp = ahead;
    }
    return prev;
}
ListNode* selfAddOne(ListNode* head){
    // this won't work if the question changes from add-One to add-K, that is why brute approach is preferred

    // TC: O(3n)
    // SC: O(1)
    head = reverseLL(head);
    head->val += 1;
    ListNode* current = head;
    while(current->val == 10){
        current->val = 0;
        if(current->next == nullptr){
            ListNode* newNode = new ListNode(0);
            current->next = newNode;
        }
        current = current->next;
        current->val += 1;
    }
    return reverseLL(head);
}
ListNode* iterativeAddOne(ListNode* head){
    // TC: O(3n)
    // SC: O(1)
    head = reverseLL(head);
    ListNode* current = head;
    int carry = 1;
    while(current && carry){
        int sum = current->val + carry;
        current->val = sum % 10;
        carry = sum / 10;
        if(!current->next && carry){
            current->next = new ListNode(carry);
            carry = 0;
        }
        current = current->next;
    }
    return reverseLL(head);
}
int helper(ListNode* temp){
    if(temp == nullptr) return 1;
    int carry = helper(temp->next);
    temp->val += carry;
    if(temp->val < 10) return 0;
    temp->val = 0;
    return 1;
}
ListNode* recursiveAddOne(ListNode* head){
    // TC: O(n)
    // SC: O(n) recursive stack space
    int carry = helper(head);
    if(carry == 1){
        ListNode* newNode = new ListNode(1);
        newNode->next = head;
        return newNode;
    }
    return head;
}
int main(){
    ListNode* head = new ListNode(9);
    head->next = new ListNode(9);
    head->next->next = new ListNode(9);

    // head = selfAddOne(head);
    // head = iterativeAddOne(head);
    head = recursiveAddOne(head);
    print(head);

    return 0;
}