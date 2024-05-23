#include<bits/stdc++.h>
using namespace std;

int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at, at+n);
    sort(dt, dt+n);
    //[900, 940, 950, 1100, 1500, 1800]
    //[910, 1120, 1130, 1200, 1900, 2000]
    int i=1, j=0;
    int maxi = 1;
    int cnt  = 1;
    while(i<n && j<n){
        if(at[i] > dt[j]){
            j++;
            cnt--;
        }
        i++; cnt++;
        maxi = max(maxi, cnt);
    }
    return maxi;
}