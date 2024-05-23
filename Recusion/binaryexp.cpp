#include<bits/stdc++.h>
using namespace std;

int binaryExponentiation(int x,int n) {
    if(n==0) return 1;
    //n is even
    else if(n%2 == 0)        
        return binaryExponentiation(x*x,n/2);
    //n is odd
    else                             
        return x*binaryExponentiation(x*x,(n-1)/2);
}