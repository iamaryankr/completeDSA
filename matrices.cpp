#include<iostream>
using namespace std;

//Diagonal matrix
class Diagonal{
    private:
         int n;int *A;
    public:
         Diagonal(int n){
            this->n=n;
            A=new int [n];
         }
         void Set(int i,int j,int x);
         int Get(int i,int j);
         void Display();
         ~Diagonal(){
            delete []A;
         }
};
void Diagonal::Set(int i,int j,int x){
    if(i==j) A[i-1]=x;
}
int Diagonal::Get(int i ,int j){
    if(i==j) return A[i-1];
    else return 0;
}
void Diagonal::Display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) cout << A[i-1];
            else cout<<"0";
        }
        cout<<endl;
    }
}

//LowerTriangular matrix
class LTMatrix{
    private:
        int n;
        int *A;
    public:
        LTMatrix(int n){
            this->n=n;
            A= new int [n*(n+1)/2];
        }
        void Display(bool row=true);
        void SetRowMajor(int i,int j,int x);
        void SetColumnMajor(int i,int j,int x);
        int GetRowMajor(int i,int j);
        int GetColumnMajor(int i,int j);
        ~LTMatrix(){
            delete []A;
        }

};
void LTMatrix:: SetRowMajor(int i,int j,int x){
    if(i>=j){
        int index = ((i*(i-1))/2)+ (j-1);
        A[index]=x;
    }
}
int LTMatrix:: GetRowMajor(int i,int j){
    if(i>=j){
        int index = ((i*(i-1))/2)+ j-1;
        return A[index];
    }
    else{
        return 0;
    }
}

void LTMatrix:: SetColumnMajor(int i,int j,int x){
    if(i>=j){
        int index = n*(j-1)-(((j-2)*(j-1))/2-(i-j));
        A[index]=x;
    }
}
int LTMatrix:: GetColumnMajor(int i,int j){
    if(i>=j){
        int index = n*(j-1)-(((j-2)*(j-1))/2-(i-j));
        return A[index];
    }
    else{
        return 0;
    }
}
void LTMatrix:: Display(bool row){
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (i >= j){
                if (row){
                    cout << GetRowMajor(i, j) << " ";
                } else {
                    cout << GetColumnMajor(i, j) << " ";
                }
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
 }

//Tri diagonal Matrix
 class TriDiagonalMatrix{
    private: 
       int n;
       int *A;
    public:
        TriDiagonalMatrix(int n){
            this->n=n;
            A=new int [3*n-2];
         }
         void Set(int i,int j,int x);
         int Get(int i,int j);
         void Display();
         ~TriDiagonalMatrix(){
            delete []A;
         }    
 };
 void TriDiagonalMatrix:: Set(int i,int j,int x){
     if(i-j==1){
        int index = i-1;
        A[index]=x;
    }
     if(i-j==0){
        int index = n+i-2;
        A[index]=x;
    }
     if(i-j==-1){
        int index = 2*n+i-2;
        A[index]=x;
    }
 }
 int TriDiagonalMatrix:: Get(int i,int j){
    if(i-j==1){    //lower diagonal
        int index = i-1;
        return A[index];
    }
    if(i-j==0){    //main diagonal
        int index = n+i-2;
        return A[index];
    }
    if(i-j==-1){   //upper diagonal
        int index = 2*n+i-2;
        return A[index];
    }
    else{
        return 0;
    }
 }
 void TriDiagonalMatrix:: Display(){
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (i-j==1) cout<<A[i-1];
            if (i-j==0) cout<<A[n+i-1];
            if (i-j==-1) cout<<A[2*n+i-1];
            else       cout << 0 << " ";
        cout << endl;
    }
 }
 }

//Toeplitz Matrix
class Toeplitz{
    private:
         int n;
         int *A;
    public:
         Toeplitz(int n){
            this->n=n;
            A=new int [2*n-1];
         }
         void Set(int i,int j,int x);
         int Get(int i,int j);
         void Display();
         ~Toeplitz(){
            delete []A;
         } 
       
};
void Toeplitz::Set(int i,int j,int x){
    if(i<=j){
        int index= j-1;
        A[index]=x;
    }
    else{
        int index= n+i-j-1;
        A[index]=x;
    }
}
int Toeplitz:: Get(int i,int j){
    if(i<=j){
        int index= j-1;
        return A[index];
    }
    else{
        int index= n+i-j-1;
        return A[index];
    }
}
void Toeplitz:: Display(){
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if(i<=j) cout<<A[j-1];
            else cout<<A[n+i-j+1];
        }
    }     
}

//Sparse Matrix
//use of 3 column representation and compressed sparse row
class Element{
    public:
      int i; int j; int x;
};
class Sparse{
    private:
      int m; int n; int num;
      Element *ele;
    public:
      Sparse(int m,int n,int num){
        this-> m = m;
        this-> n = n;
        this-> num = num;
        ele=new Element[this->num];
      }
      Sparse operator+(Sparse &s);
      friend istream & operator >>(istream & is, Sparse &s);
      friend ostream & operator <<(ostream & os, Sparse &s);
      ~Sparse(){
        delete [] ele;
      }    
};
Sparse Sparse:: operator+(Sparse &s){
    int i=0, j=0, k=0;
    if(m!=s.m || n!=s.n)  return Sparse(0,0,0);
    Sparse *sum = new Sparse(m,n,num+s.num);
    
    while(i<num && j<s.num){
        if(ele[i].i < s.ele[j].i){
            sum->ele[k++]=ele[i++];
        }
        else if(ele[i].i>s.ele[j].i){
            sum->ele[k++]=s.ele[j++];
        }
        else{
            if(ele[i].j<s.ele[j].j) 
                sum->ele[k++]=ele[i++];
            else if(ele[i].j>s.ele[j].j)
                sum->ele[k++]=s.ele[j++];
            else{
            sum->ele[k]=ele[i]; //for matrix
            sum->ele[k++].x=ele[i++].x+s.ele[j++].x; //for array
            }
        }
    }
    for(;i<num;i++) sum->ele[k++]=ele[i];
    for(;j<s.num;j++) sum->ele[k++]=s.ele[j];

    sum->num=k;
    return *sum;

}
istream &operator >> (istream &is, Sparse &s){
    cout<<"Enter non zero elements";
    for(int i=0;i<s.num;i++){
        cin>>s.ele[i].i>>s.ele[i].j>>s.ele[i].x;
    }
    return is;
}
ostream &operator << (ostream &os, Sparse &s){
    int k=0;
    for(int i=0;i<s.m;i++){
        for(int j=0;j<s.n;j++){
            if(s.ele[k].i==i && s.ele[k].j==j)
                 cout<<s.ele[k++].x<<" ";
            else 
                 cout<<"0 ";
        }
        cout<<endl;
    }
    return os;
}


int main(){
    Diagonal d(4);
    d.Set(1,1,3);
    d.Set(2,2,5);
    d.Set(3,3,4);
    d.Set(0,0,7);
    d.Display();

     LTMatrix rm(4);
    rm.SetRowMajor(1, 1, 1);
    rm.SetRowMajor(2, 1, 2);
    rm.SetRowMajor(2, 2, 3);
    rm.SetRowMajor(3, 1, 4);
    rm.SetRowMajor(3, 2, 5);
    rm.SetRowMajor(3, 3, 6);
    rm.SetRowMajor(4, 1, 7);
    rm.SetRowMajor(4, 2, 8);
    rm.SetRowMajor(4, 3, 9);
    rm.SetRowMajor(4, 4, 10);
 
    rm.Display();
    cout << endl;
 
    LTMatrix cm(4);
    cm.SetColumnMajor(1, 1, 1);
    cm.SetColumnMajor(2, 1, 2);
    cm.SetColumnMajor(2, 2, 3);
    cm.SetColumnMajor(3, 1, 4);
    cm.SetColumnMajor(3, 2, 5);
    cm.SetColumnMajor(3, 3, 6);
    cm.SetColumnMajor(4, 1, 7);
    cm.SetColumnMajor(4, 2, 8);
    cm.SetColumnMajor(4, 3, 9);
    cm.SetColumnMajor(4, 4, 10);
 
    cm.Display(false);

    Sparse s1(5,5,5);
    Sparse s2(5,5,5);
    cin>>s1;
    cin>>s2;
    Sparse sum=s1+s2;
    cout<<"First Matrix"<<endl<<s1;
    cout<<"Second MAtrix"<<endl<<s2;
    cout<<"Sum Matrix"<<endl<<sum;
    return 0;
 

}