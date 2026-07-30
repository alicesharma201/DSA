#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
ListNode* bruteStartingPoint(ListNode* head){
    // TC: O(n)
    // SC: O(n)
    ListNode* temp = head;
    unordered_map<ListNode*,int> hash;
    while(temp){
        if(hash.find(temp) != hash.end()) return temp;
        hash[temp]++;
        temp = temp->next;
    }
    return nullptr;
}
ListNode* optimalStartingPoint(ListNode* head){
    // TC: O(n)
    // SC: O(1)
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5, head->next->next);
    
    // ListNode* ptr = bruteStartingPoint(head);
    ListNode* ptr = optimalStartingPoint(head);
    if(ptr == nullptr) cout << "There is no loop.\n";
    else cout << "The starting point of loop is " << ptr->val << endl; 

    return 0;
}