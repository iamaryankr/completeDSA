#include<bits/stdc++.h>
using namespace std;

// //problem1
// int main(){
//     int t; cin>>t;
//     while(t--){
//         int x, y;
//         cin>>x>>y;
       
//         int q = y/2 + y%2;
//         int cnt = 0;
//         if(y==1){
//             if(x<=11) cout<<q<<endl;
//             else{
//                 x = x-11;
//                 if(x%15==0) cout<< q + x/15 <<endl;
//                 else cout<< q + x/15 + 1<<endl;
//             }   
//         }
//         else{
//             for(int i=0; i<q; i++){
//                 if(x>7){
//                     x = x-7;
//                     cnt++;
//                 }   
//                 break;
//             }
//             if(cnt<q) cout<<q<<endl; 
//             else{
//                 if(x%15==0) cout<<q + x/15<<endl;
//                 else cout<< q + x/15 + 1 <<endl; 
//             }
//         }
        
//     }
// }

//problem2
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         vector<int> a(n);
//         for(int i=0; i<n ;i++){
//             cin>>a[i];
//         }
//         int triplets = n-3+1;
//         int ans = 0;
//         for(int i=0; i<n-3; i++){
//             int cnt = 0;
//             if(a[i]!=a[i+1]) cnt++;
//             if(a[i+1]!=a[i+2]) cnt++;
//             if(a[i+2]!=a[i+3]) cnt++;
//             if(cnt==1) ans++;
//         }
//         cout<<ans<<endl;
//     }
// }

//problem3
int main(){
    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;
        string b;
        cin>>b;
        string c = b;
        set<char> s;
        for(int i=0; i<n; i++){
            s.insert(b[i]);
        }
        vector<char> a(s.begin(), s.end());
        sort(a.begin(), a.end());
        set<char> s2(a.begin(), a.end());
        
        for(int i=0; i<n; i++){
            auto it = s2.find(b[i]);
            int a = distance(s2.begin(), it);
            auto x = s2.begin();
            advance(x, s2.size()-a-1);
            char ch = *x;
            c[i] = ch;
        }
        cout<<c<<endl;
    }
}

// //problem4
// int main(){
//     int t; cin>>t;
//     while(t--){

//     }
// }

// //problem5
// int main(){
//     int t; cin>>t;
//     while(t--){

//     }
// }