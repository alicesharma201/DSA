#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
int bruteLength(ListNode* head){
    // TC: O(n)
    // SC: O(n)
    ListNode* temp = head;
    unordered_map<ListNode*,int> hash;
    int cnt = 0;
    int loopLen = 0;
    while(temp){
        cnt++;
        if(hash.find(temp) != hash.end()){
            loopLen = cnt - hash[temp];
            break;
        }
        hash[temp] = cnt;
        temp = temp->next;
    }
    return loopLen;
}
int optimalLength(ListNode* head){
    // TC: O(n)
    // SC: O(1)
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            int loopLen = 1;
            slow = slow->next;
            while(slow != fast){
                slow = slow->next;
                loopLen++;
            }
            return loopLen;
        }
    }
    return 0;
}
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5, head->next->next);
    
    cout << bruteLength(head) << endl;
    cout << optimalLength(head) << endl;

    return 0;
}