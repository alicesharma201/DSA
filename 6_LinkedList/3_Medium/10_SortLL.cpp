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
ListNode* bruteSortLL(ListNode* head){
    // TC: O(2n + nlogn) = O(nlogn)
    // SC: O(n)
    vector<int> nums;
    ListNode* temp = head;
    while(temp){
        nums.push_back(temp->val);
        temp = temp->next;
    }
    sort(nums.begin(), nums.end());
    temp = head;
    for(int i : nums){
        temp->val = i;
        temp = temp->next;
    }
    return head;
}
ListNode* findMiddle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode* mergeLL(ListNode* leftHead, ListNode* rightHead){ 
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy; 
    while(leftHead && rightHead){
        if(leftHead->val <= rightHead->val){
            temp->next = leftHead;
            temp = leftHead;
            leftHead = leftHead->next;
        }
        else{
            temp->next = rightHead;
            temp = rightHead;
            rightHead = rightHead->next;
        }
    }
    if(leftHead) temp->next = leftHead;
    else temp->next = rightHead;
    return dummy->next;
}
ListNode* optimalSortLL(ListNode* head){
    // TC: O((n/2 + n)*logn) = O(nlogn)
    // SC: O(1) but O(logn) for recursive stack
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* middle = findMiddle(head); // O(n/2)
    ListNode* leftHead = head; ListNode* rightHead = middle->next;
    middle->next = nullptr; // breaking the two lists
    leftHead = optimalSortLL(leftHead);
    rightHead = optimalSortLL(rightHead);
    return mergeLL(leftHead, rightHead); // O(n)
}
int main(){
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(1);

    // head = bruteSortLL(head);
    head = optimalSortLL(head);
    print(head);

    return 0;
}