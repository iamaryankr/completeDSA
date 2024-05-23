#include<iostream>
using namespace std;
void ExplainHashmethod(){
        int n=7;
        int A[n]={1,4,5,6,7,10,13};
        int l=1,h=13;

        int H[h+1]={};
        for(int i=0;i<n;i++){
            H[A[i]]++;
        }
        for(int i=l;i<=h;i++){
            if(H[i]==0) cout<<i<<" ";
        }
}
void Duplicatesinunsorted(){
    int A[10]={8,3,6,4,6,5,6,8,2,7};
    int n=10;
    for(int i =0;i<n-1;i++){
        int count =1;
        if(A[i]!=-1){
             for(int j=i+1;j<n;j++){
                 if(A[i]==A[j]){
                     count++;
                     A[j]=-1;
            }
        }
        if(count>1) cout<<A[i]<<" "<<count;
    }
    }

    //using hash table
    int A[10]={8,3,6,4,6,5,6,8,2,7};
    int n=10;
    int l=2,h=8;
    int H[h+1]={};
    for(int i=0;i<n;i++){
        H[A[i]]++;
     }
    for(int i=l;i<=h;i++){
        if(H[i]>1) cout<<i<<" "<<H[i];
    }
}
void sumAlgo(){
    int n=10;
    int A[n]={1,2,4,5,6,7,8,9,3,11};
    int K=6;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(A[i]+A[j]==K) cout<<i<<" "<<j<<endl;
        }
    }

    //use of hash table
    int n=10;
    int A[n]={1,2,4,5,6,7,8,9,3,11};
    int K=6;
    int h=11,l=1;
    int H[h+1]={};
    for(int i=0;i<n;i++){
        if(H[K-A[i]]!=0 && K-A[i]>0) cout<<A[i]<<" "<<K-A[i]<<" "<<K<<endl;
        H[A[i]]++;
    }
}

void FindingMax(){
    int n=10;
    int A[n]={1,2,4,5,6,7,-1,9,3,11};
    int min=A[0]; int max=A[0];
    for(int i=0;i<n;i++){
        if(A[i]>max) max=A[i];
        if(A[i]<min) min=A[i];
    }
}