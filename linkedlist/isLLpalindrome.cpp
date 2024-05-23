#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode *reverselist(ListNode *head){
        ListNode *prev= NULL;
        ListNode *next= NULL;
        while(head){
            next= head->next;
            head->next = prev;
            prev= head;
            head= next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return true;
        }

        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverselist(slow->next);
        slow = slow->next;

        while(slow){
            if(head->val != slow->val){
                return false;
            }
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
};