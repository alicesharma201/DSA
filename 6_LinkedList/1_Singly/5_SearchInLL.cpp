#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
bool isPresent(ListNode* head, int num){
    // TC: O(n)
    ListNode* temp = head;
    while(temp){
        if(temp->val == num) return true;
        temp = temp->next;
    }
    return false;
}
int main(){
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(5);
    head->next->next->next = new ListNode(1);
    cout << (isPresent(head, 2) ? "True\n" : "False\n"); 
    return 0;
}