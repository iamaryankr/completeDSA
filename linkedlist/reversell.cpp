#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //iterative soln
    ListNode* reverseList(ListNode* head) {
        ListNode *p = head;
        ListNode *q = nullptr, *r = nullptr;
        while(p){
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        head = q;
        return head;
    }
    //recursive
    ListNode* reverseList(ListNode* head) {
        if( head == NULL || head->next == NULL) return head;

        ListNode* prev = NULL;
        ListNode* h = reverseList(head->next);
        head->next->next = head;
        head->next=prev;
        return h; 
    }

};