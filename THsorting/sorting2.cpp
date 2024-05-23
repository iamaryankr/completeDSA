#include<bits/stdc++.h>
using namespace std;

template <class T>
void Print(T& vec, int n, string s){
    cout<<s << ": ["<<flush;
    for(int i=0; i<n ; i++){
        cout<< vec[i] << flush;
        if(i < n-1){
            cout<<", "<<flush;
        }
    }
    cout<<"]"<<endl;
}
int Max(int A[], int n){
    int max = INT32_MIN;
    for(int i=0; i<n; i++){
        if(A[i] > max) max = A[i];
    }
    return max;
}

void Swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
//Bin/Bucket sort   //O(n+k)
class Node{
    public:
        int value;
        Node *next;
};
void InsertBin(Node ** ptrBins, int index){
    Node *temp = new Node;
    temp->next = nullptr;
    temp->value = index;
    if(ptrBins[index] == nullptr)
        ptrBins[index] = temp;
    else{
        Node *p = ptrBins[index];
        while(p->next != nullptr){
            p = p->next;
        }
        p->next = temp;
    }
}
int DeleteBin(Node **ptrBins , int index){
    Node *p = ptrBins[index];
    ptrBins[index] = ptrBins[index] -> next;
    int x = p->value;
    delete p;
    return x;
}

void BinSort(int A[], int n){
    int max = Max(A,n);
    Node **Bins = new Node*[max+1];
    for(int i=0; i<max+1; i++){
        Bins[i] = nullptr;
    }
    for(int i=0; i<n; i++){
        InsertBin(Bins, A[i]);
    }
    int i=0, j=0;
    while(i < max+1){
        while(Bins[i] != nullptr){
            A[j++] = DeleteBin(Bins, i);
        }
        i++;
    }

    delete []Bins;
}


//radix sort    O(nlogn)
int CountDigits(int x){
    int count = 0;
    while(x != 0){
        x/=10;
    }
    return count;
}
void initializeBins(Node **p, int n){
    for(int i=0; i<n; i++){
        p[i] = nullptr;
    }
}
void InsertRadix(Node ** ptrBins, int value, int index){
    Node *temp = new Node;
    temp->value = value;
    temp->next = nullptr;
    if(ptrBins[index] == nullptr){
        ptrBins[index] = temp;
    }
    else{
        Node *p = ptrBins[index];
        while(p->next != nullptr)
            p=p->next;
        p->next = temp;
    }
}
int DeleteRadix(Node **ptrBins, int index){
    Node *p = ptrBins[index];
    ptrBins[index] = ptrBins[index]->next;
    int x = p->value;
    delete p;
    return x;
}
int GetbinIndex(int x, int index){
    return (int)(x/pow(10,index))%10;
}
void RadixSort(int A[], int n){
    int max = Max(A,n);
    int nPass = CountDigits(max);
    Node **Bins = new Node*[10];
    initializeBins(Bins, 10);

    for(int pass=0; pass < nPass; pass++){
        for(int i=0; i<n; i++){
            int binIndex = GetbinIndex(A[i], pass);
            InsertRadix(Bins, A[i], binIndex);
        }
        int i=0, j=0;
        while(i < 10){
            while(Bins[i] != nullptr){
                A[j++] = DeleteRadix(Bins, i);
            }
            i++;
        }
        initializeBins(Bins, 10);
    }

    delete []Bins;
}


//shell sort    O(nlogn)
void ShellSort(int A[], int n){
    for(int gap=n/2; gap>=1; gap/=2){
        for(int j=gap; j<n; j++){
            int temp = A[j];
            int i = j-gap;
            while(i>= 0 && A[i] > temp){
                A[i+gap] = A[i];
                i= i-gap;
            }
            A[i+gap] = temp;
        }
    }
}