#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
       int n,m;
       cin>>n>>m;
       string a, b;
       cin>>a;
       cin>>b;
       int ans = 0;
       for(int i=0; i<m; i++){
            if(a[ans] == b[i]) ans++;
       }
       cout<<ans<<endl;
    }
    return 0;
}