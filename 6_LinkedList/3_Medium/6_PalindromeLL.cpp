#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
bool brutePalindrome(ListNode* head){
    // TC: O(2n) = O(n)
    // SC: O(n)
    if(head == nullptr || head->next == nullptr) return true;
    ListNode* temp = head;
    stack<int> st;
    while(temp){
        st.push(temp->val);
        temp = temp->next;
    }
    temp = head;
    while(temp){
        if(st.top() != temp->val) return false;
        st.pop();
        temp = temp->next;
    }
    return true;
}
bool optimalPalindrome(ListNode* head){
    // TC: O(n/2 + n/2 + n/2) = O(n)
    // SC: O(1)
    if(head == nullptr || head->next == nullptr) return true;
    ListNode* slow = head;
    ListNode* fast = head->next; // ensures slow is at the true middle (odd) or end of first half (even)
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* temp = slow->next; // reverse the linkedlist from mid+1 to end
    ListNode* prev = nullptr;
    while(temp){
        ListNode* ahead = temp->next;
        temp->next = prev;
        prev = temp;
        temp = ahead;
    } // prev will point at the head of the reversed linkedlist
    ListNode* initial = head;
    while(prev){
        if(prev->val != initial->val) return false;
        prev = prev->next;
        initial = initial->next;
    }
    return true;
}
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    // head->next->next->next->next = new ListNode(1);

    cout << brutePalindrome(head) << endl;
    cout << optimalPalindrome(head) << endl; // the con of the optimal solution is that we will have half of our linkedlist reversed which modifies the input, so in order the fix that we will have to reverse that half of the linkedlist again

    return 0;
}