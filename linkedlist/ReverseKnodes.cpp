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
    ListNode* reversedLL(ListNode* head){
        ListNode* currNode= head;
        ListNode* prevNode= NULL;
        ListNode* nextNode;
        while(currNode){
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        return prevNode;
    }
    ListNode* getKthNode(ListNode* temp, int k){
        k = k-1;
        while(temp && k>0){
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k){
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        ListNode* nextNode = NULL;
        while(temp){
            ListNode* kthNode = getKthNode(temp, k);
            if(kthNode == NULL){
                if(prevNode != NULL) prevNode->next = temp;
                break;
            }
            nextNode = kthNode->next;
            kthNode->next = NULL;
            reversedLL(temp);
            if(temp==head){
                head = kthNode;
            }
            else prevNode->next = kthNode;
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};