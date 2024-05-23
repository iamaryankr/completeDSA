#include<bits/stdc++.h>
using namespace std;

class LDSubset{
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n= arr.size();
        sort(arr.begin(), arr.end());
        vector<int> dp(n,1);
        vector<int> hash(n,1);  
        for(int i=0; i<=n-1; i++){ 
            hash[i] = i; 
            for(int prev = 0; prev <=i-1; prev ++){
                
                if(arr[i]%arr[prev]==0 && 
                1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
        }
        int ans = -1;
        int lastIndex =-1;
        
        for(int i=0; i<=n-1; i++){
            if(dp[i]> ans){
                ans = dp[i];
                lastIndex = i;
            }
        }
        vector<int> temp;
        temp.push_back(arr[lastIndex]);
        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            temp.push_back(arr[lastIndex]);    
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};