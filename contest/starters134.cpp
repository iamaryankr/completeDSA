#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int maxi = 1;
    int cnt = 1;
    int num = s[0];
    int ind = 0;
    for(int i=0; i<n; i++){
        if(num==s[i]){
            cnt++;
        }
        if(cnt > maxi){
            ind = i;
            maxi = cnt;
        }
        cnt = 1;
        num = s[i];
    }
    cout<< num <<" "<< maxi<<endl;
}