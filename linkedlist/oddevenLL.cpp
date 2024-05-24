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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL){
            return head;
        } 
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenStart = head->next;
        while(odd->next && even->next){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenStart;
        return head;
    }
};