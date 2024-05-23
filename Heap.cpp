#include<iostream>
#include<vector>
using namespace std;

template <class T>
void Print(T& vec, int n){
    cout<<"Max heap: ["<<flush;
    for(int i=0; i<n; i++){
        cout<<vec[i] << flush;
        if(i< n-1){
            cout<<", "<<flush;
        }
    }
    cout<<"]"<<endl;
}

void InsertA(int A[],int n){
    int i=n;
    int temp = A[n];
    while( i>0 && temp > A[i%2 == 0 ? (i/2)-1 : i/2]){
        A[i] = A[i%2 == 0 ? (i/2)-1 : i/2];
        i = i%2 == 0 ? (i/2)-1 : i/2;
    }
    A[i] = temp;
}
//using stl
void Insert(vector<int> &vec, int key){
    auto i = vec.size();  //inserting at end
    vec.emplace_back(key);
    //rearranging the elements
    while(i>0 && key> vec[i%2 == 0 ? i/2-1: i/2]){
        vec[i] = vec[i%2 == 0 ? i/2-1: i/2];
        i = i%2 == 0 ? i/2-1: i/2;
    }
    vec[i] = key;
}

void CreateHeap(vector<int> &vec, int A[], int n){
    for(int i=0; i<n; i++){
        Insert(vec,A[i]);
    }
}

//for heapify
void Swap(int A[], int i, int j){
    int temp= A[i];
    A[i] = A[j];
    A[j] = temp;
}
int Delete(int A[], int n){
    int x= A[0];
    A[0] = A[n-1];
    int i=0; int j= 2*i+1;

    while(j < n-1){
        if(A[j] < A[j+1]){  //compare left and right child
            j+=1;
        }
        if(A[j] < A[j]){   //compare parent and largest child
            Swap(A, i, j);
            i= j;
            j= 2*i + 1;
        }
        else{
            break;
        }
    }
    return x;
}
void Heapify(int A[], int n){
    for(int i=(n/2)-1; i>=0; i--){  //no of leaf elements and index
        int j = 2*i + 1;  //left child
        while(j < n-1){   //compare left and right child
            if(A[j] < A[j+1])  j = j+1;

            if(A[i] < A[j]){  //parent and child comparision
                Swap(A, i, j);
                i= j;
                j= 2*i + 1;
            }
            else{ break; }
        }
    }
}

int main(){
    int a[] = {45, 35, 15, 30, 10, 12, 6, 5, 20, 50};
    InsertA(a, 9);
    Print(a, sizeof(a)/sizeof(a[0]));
    cout << endl;
 
    // STL based
    vector<int> v = {45, 35, 15, 30, 10, 12, 6, 5, 20};
    Print(v, v.size());
    v.reserve(15);  // Reserve space for 15 elements
 
    Insert(v, 50);
    Print(v, v.size());

    cout << "Create Heap" << endl;
    int b[] = {10, 20, 30, 25, 5, 40, 35};
    Print(b, sizeof(b)/sizeof(b[0]));
 
    vector<int> vec;
    CreateHeap(vec, b, sizeof(b)/sizeof(b[0]));
    Print(vec, vec.size());

    Heapify(b, sizeof(b)/sizeof(b[0]));
    Print(b, sizeof(b)/sizeof(b[0]));
 
    return 0;
}