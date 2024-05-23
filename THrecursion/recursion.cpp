#include<iostream>
using namespace std;
void func(int n){  
    if(n>0){
        func(n-1);
        cout<<n<<endl; //prints while returning (head recursion)
    }
}
int fun1(int n){
    if(n>0) return fun1(n-1)+n;
    return 0;
}
//use of static or global variables
int fun2(int n){
    static int x=0;  //code maintains a single copy of it
    if(n>0) {
        x++;
        return fun1(n-1)+x;
    }
    return 0;
}
void fun3(int n){
    if(n>0){
        cout<<n;
        fun3(n-1);
        fun3(n-1); //tree recursion
    }
}
//indirect recursion
void funB(int n);
void funA(int n){
    if(n>0){cout<<n; funB(n-1);}
}
void funB(int n){
    if(n>1){cout<<n; funA(n/2);}
}
//nested recursion
int fun4(int n){
    if(n>100) return n-10;
    else return fun4(fun4(n+11));
}
int sumn(int n){
    if(n==0) return 0;
    else return sumn(n-1)+n;
}
int pow(int m,int n){
    if(n==0) return 1;
    else return pow(m,n-1)*m;
}

int erec(int x, int n){  //taylors series using recursion
    static int p=1,f=1;
    int r ;
    if(n==0) return 1;
    else {
        r=erec(x,n-1);
        p=p*x;
        f=f*n;
        return r+p/f ;
    }
}
int eloop(int x, int n){ //taylors using horners rule or loops
    int s=1;
    while(n>0){
         s= 1+(x/n)*s ;
         n--;
     }
    return s;
}
int fibr(int n){
    if(n==1) return 0;
    if(n==2) return 1;
    else return fibr(n-1)+fibr(n-2);
}
int F[10]; //fibonacci using a global array also called as memoization:
int fib(int n){
    if(n<=1){
        F[n]=n;
        return n;
    }
    else{
        if(F[n-2]==-1) F[n-2]=fib(n-2);
        if(F[n-1]==-1) F[n-1]=fib(n-1);
        return F[n-1]+F[n-2];
    }
}
void TOH(int n, int A,int B, int C){  //tower of hanoi problem 
    if(n>0){ 
        TOH(n-1,A,C,B);
        cout<<A<<" "<<C<<endl;
        TOH(n-1,B,A,C);
    }
}

int main(){
    //func(7);
    //cout<<fun1(7)<<endl<<fun2(7);
    //fun3(6);
    //funA(5);
    //cout<<fun4(95);
    //cout<<sumn(10);
    //cout<<pow(3,4);
    //cout<<eloop(6 ,3);
    //cout<<eloop(6,3);
    //cout<<fib(5);
    //for(int i=0;i<10;i++) F[i]=-1;
    //cout<<fib(6);
    TOH(3,1,2,3);
}