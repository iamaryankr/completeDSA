#include<iostream>
#include<vector>
using namespace std;

//Two pointer approach problem
vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        int sum=0,i=0,j=0;
        while(j<=n){
            if(s==0) return {-1};
            else if (sum==s) return {i+1,j};
            else if(sum<s) { sum+=arr[j]; j++; }
            else { sum-=arr[i]; i++; }
        }
        return {-1};
    }