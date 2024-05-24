#include<bits/stdc++.h>
using namespace std;
class ListNode{
    public:
    ListNode *next;
    int val;
    ListNode() : val(0), next(NULL){};
    ListNode(int x) : val(x), next(NULL){};
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        ListNode *fast=head, *slow=head;

        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow) return true;
        }
        return false;
    }
};
//finding the starting point of the loop
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                slow = head;
                while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};