#include<bits/stdc++.h>
using namespace std;
vector<string> ans;
void func(string &str, int n, int N){
    if(N==0){
        ans.push_back(str);
        return ;
    }
    if(n==2){
        str.push_back('0');
        func(str, n, N-1);
        str.pop_back();
        
        str.push_back('1');
        func(str, n-1, N-1);
        str.pop_back();
    }
    if(n==1){
        str.push_back('0');
        func(str, n+1, N-1);
        str.pop_back();
    }
}
vector<string> generateString(int N) {
    string str = "";
    func(str, 2, N);
    return ans;
}