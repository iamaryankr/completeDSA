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
    int len(ListNode* &head){
        int len =0;
        ListNode* temp =head;
        while(temp){
            temp=temp->next;
            len++;
        }
        return len;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        if(head==NULL) return NULL;
        int length =len(head);
        int modk = (k%length);
        if(modk==0) return head;

        int stop = length - modk -1;

        ListNode* temp = head;
        for(int i=0;i<stop;i++){
            temp = temp->next;
        }

        ListNode* newhead = temp->next;
        temp->next=NULL;
        ListNode* newtemp =newhead;

        while(newtemp->next){
            newtemp=newtemp->next;
        }
        newtemp->next=head;
        return newhead;    
    }
};