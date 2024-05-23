#include<bits/stdc++.h>
vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> stk;
    stk.push(A[0]);
    int n = A.size();
    vector<int> res(n, -1);
    for(int i=1; i<n; i++){
        int curr = A[i];
        if(stk.top() < curr){
            res[i] = stk.top();
            stk.push(A[i]);
        }
        else{
            while(!stk.empty() && stk.top()>=A[i]) stk.pop();
            
            if(!stk.empty()) res[i] = stk.top();
            
            stk.push(A[i]);
        }
    }
    return res;
}
