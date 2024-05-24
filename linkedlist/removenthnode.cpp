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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr = head;
        int counter =0;
        while(ptr!=NULL)
        {
            counter++;
            ptr = ptr->next;
        }
        if(head ==NULL || head->next == NULL)
        {
            return NULL;
        }
        if(counter - n == 0){
           return head->next;
        }
        ListNode* temp=head;
        ListNode* slow=head;
        for(int i=0;i<counter-n;i++)
        {
            slow = temp;
            temp = temp->next;
        }
        slow->next = temp->next;
        delete temp;
        return head;  
    }
};