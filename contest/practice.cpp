#include<bits/stdc++.h>
using namespace std;

int main(){
    int x1, x2, x3;
    cin>>x1>>x2>>x3;

    vector<int> v = {x1, x2, x3};
    sort(v.begin(), v.end());
    int mini = INT_MAX;
    for(int i=v[0]; i<=v[2]; i++){
        int dist = abs(i-x1) + abs(i-x2) + abs(i-x3);
        mini = min(dist, mini);
    }
    cout<<mini<<endl;
}