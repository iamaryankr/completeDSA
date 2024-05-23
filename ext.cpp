#include<iostream>
using namespace std;
int main(){

    int n=10;
    int A[n]={1,2,4,5,6,7,-1,9,3,11};
    int min=A[0]; int max=A[0];
    for(int i=0;i<n;i++){
        if(A[i]>max) max=A[i];
        if(A[i]<min) min=A[i];
    }
    cout<<max<<" "<<min;

}