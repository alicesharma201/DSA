#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
bool bruteDetectLoop(ListNode* head){
    // TC: O(n)
    // SC: O(n)
    ListNode* temp = head;
    unordered_map<ListNode*,int> hash;
    while(temp){
        if(hash.find(temp) != hash.end()) return true; 
        // if(hash[temp] > 0) return true;
        hash[temp]++;
        temp = temp->next;
    }
    return false;
}
bool optimalDetectLoop(ListNode* head){
    // TC: O(n)
    // SC: O(1)
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next = new ListNode(5, head->next->next);
    
    cout << (bruteDetectLoop(head) ? "Loop Exists\n" : "Loop doesn't Exist\n");
    cout << (optimalDetectLoop(head) ? "Loop Exists\n" : "Loop doesn't Exist\n");

    return 0;
}