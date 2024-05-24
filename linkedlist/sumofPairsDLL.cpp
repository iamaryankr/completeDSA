#include<bits/stdc++.h>
using namespace std;
class ListNode{
    public:
    ListNode *next, *prev;
    int val;
    ListNode() : val(0), next(NULL), prev(NULL){};
    ListNode(int x) : val(x), next(NULL), prev(NULL){};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};
vector<pair<int, int>> findPairs(ListNode* head, int k){
    ListNode*left=head;
    ListNode*right=head;
    vector<pair<int,int>> v;
    while(right->next!=NULL){
        right=right->next;
    }
    while(left->val<right->val){
        if(left->val+right->val>k){
            right=right->prev;
        }
        else if(left->val+right->val<k){
            left=left->next;

        }
        else{
            v.emplace_back(left->val,right->val);
            left=left->next;
            right=right->prev;
        }
    }
    return v;
}