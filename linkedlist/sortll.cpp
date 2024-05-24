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
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        if(!left)
            return right;
        if(!right)
            return left;
        
        ListNode* temp = new ListNode(-1);
        ListNode* ans = temp;

        while(left && right){
            if(left->val < right->val){
                temp->next = left;
                temp = temp->next;
                left = left->next;
            } else {
                temp->next = right;
                temp = temp->next;
                right = right->next;
            }
        }

        while(left) {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        while(right) {
            temp->next = right;
            temp = right;
            right = right->next;
        }
        return ans->next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;

        // Finding the mid of the linked list
        ListNode* mid = findMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;

        // breaking the list into two halfs
        left = sortList(left);
        right = sortList(right);

        // merging the list
        ListNode* result = merge(left, right);
        return result;
    }
};