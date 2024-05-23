#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> findPairs(Node* head, int k){
    Node*left=head;
    Node*right=head;
    vector<pair<int,int>> v;
    while(right->next!=NULL){
        right=right->next;
    }
    while(left->data<right->data){
        if(left->data+right->data>k){
            right=right->prev
        }
        else if(left->data+right->data<k){
            left=left->next;

        }
        else{
            v.emplace_back(left->data,right->data);
            left=left->next;
            right=right->prev;
        }
    }
    return v;
}