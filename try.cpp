#include<iostream>
using namespace std;
void Permutation1(char S[],int k){
    static int A[10]={0};
    static char Res[10];
    int i;
    if(S[k]=='\0'){
        Res[k]='\0'; cout<<Res<<" ";
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
            Permutation2(S,l+1,h);
            swap(S[l],S[i]);
        }
    }
}
int main(){
    char S[]="abc";
    Permutation2(S,0,2);
return 0;
}