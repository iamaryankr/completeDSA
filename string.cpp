#include<bits/stdc++.h>
using namespace std;
void Bitwise()
    {//bitwise operations on characters

    //left shifting
     char H=1;
     H=H<<1;
     H=H<<5;

    //bits anding and bits oring use of masking and merging
    char a=10;
    char b=6;
    a&b;  a|b;
    }
void Duplicate(){  
    char A[]="finding";
    long int h=0,x=0;
    for(int i=0;A[i]!='\0';i++){
        x=1;
        x=x<<(A[i]-97);
        if((x&h)>0) cout<<"duplicate "<<A[i]<<endl;
        else h=x|h;
    }
}
void anagrams(){ \
    //checking anagrams using hash table
    char A[]="decimal";
    char B[]="medical";
    int H[26]={};
    for(int i=0;A[i]!='\0';i++){
        H[A[i]-97]++;
    }
    for(int i=0;B[i]!='\0';i++){
         H[A[i]-97]--;
         if(H[A[i]-97]<0){
            cout<<"not anagram";
            break;
         }
         if(B[i]=='\0') cout<<"anagram";
    }
    
}
void Permutation1(char S[],int k){
    static int A[10]={0};
    static char Res[10];
    int i;
    if(S[k]=='\0'){
        Res[k]='\0'; cout<<Res;
    }
    else{
        for(i=0;S[i]!='\0';i++){
            if(A[i]==0){
                Res[k]=S[i];
                A[i]=1;
                Permutation1(S,k+1);
                A[i]=0;
            }
        }
    }
}
void Permutation2(char S[],int l,int h){
    if(l==h){ cout<<S<<" ";}
    else{
        for(int i=0;i<=h;i++){
            swap(S[l],S[i]);
            l++;
            Permutation2(S,l,h);
            swap(S[l],S[i]);
        }
    }
}


int main(){
    char A[]="decimal";
    char B[]="medical";
    int H[26]={};
    for(int i=0;A[i]!='\0';i++){
        H[A[i]-97]++;
    }
    for(int i=0;B[i]!='\0';i++){
         H[A[i]-97]--;
         if(H[A[i]-97]<0){
            cout<<"not anagram";
            break;
         }
         if(B[i]=='\0') cout<<"anagram";
    }
}