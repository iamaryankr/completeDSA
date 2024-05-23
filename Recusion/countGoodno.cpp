#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int modulo = 1e9+7;
    long long power(long long x, long long y){
        if(y==0) return 1;
        if(y%2==0){
            return power(x*x%modulo, y/2)%modulo;
        }
        return x*power(x*x%modulo, (y-1)/2)%modulo;
    }
    int countGoodNumbers(long long n) {
        long long evenPlaces = n%2 + n/2;
        long long oddPlaces = n/2;
        long long ans1 = power(5, evenPlaces);
        long long ans2 = power(4, oddPlaces);

        return (int)ans1*ans2%modulo;
    }
};