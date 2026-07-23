#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
int lenOfLL(ListNode* head){
    // TC: O(n)
    int cnt = 0;
    ListNode* temp = head;
    while(temp){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    cout << lenOfLL(head) << endl;
    return 0;
}