#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a, b, n;
        cin>>a>>b>>n;
        int x[n];
        for(int i=0; i<n; i++){
            cin>>x[i];
        }
        int timer = b;
        int sec = 0;
        while(timer--){
            for(int i=0; i<n; i++){
                if(timer + x[i] <= a) timer = timer+x[i];
                if(timer + x[i] > a) timer = a;
            }
        }
    }
    return 0;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, k;
        cin>>n>>m>>k;
        vector<int> a(n), b(m);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        for(int i=0; i<m; i++){
            cin>>b[i];
        }
        
        for(int i=1; i<=k; i++){
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            if(a[0]>=b[m-1]) break;
            swap(a[0], b[m-1]);
        }
        int sum=0; 
        for(auto it: a) sum+= it;

        return sum;
    }
    return 0;
}