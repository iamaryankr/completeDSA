#include<bits/stdc++.h>
using namespace std;
class ListNode{
    public:
    ListNode *next;
    int val;
    ListNode() : val(0), next(NULL){};
    ListNode(int x) : val(x), next(NULL){};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};
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