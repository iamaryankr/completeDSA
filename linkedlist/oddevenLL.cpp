#include<bits/stdc++.h>
using namespace std;
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