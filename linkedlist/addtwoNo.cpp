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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        int carry = 0;
        ListNode* curr = dummy;
        while(l1 || l2 || carry!=0){
            int sum = 0;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            ListNode *node = new ListNode(sum%10);
            carry = sum/10;
            curr->next = node;
            curr = curr->next;
        }
        return dummy->next;
    }
};