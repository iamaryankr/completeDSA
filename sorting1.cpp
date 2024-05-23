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
void Swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

//bubble sort   //O(n^2)
void Bubblesort(int A[],int n){
    int flag = 0;   //use of flag to make it adaptive
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(A[j] > A[j+1]){
                Swap(&A[j], &A[j+1]);
                flag = 1;
            }
        }
        if (flag == 0) return ;
    }
}

//insertion sort    //O(n^2)
void Insertionsort(int A[], int n){
    for(int i=1; i<n; i++){
        int j= i-1;
        int x= A[i];
        while(j>-1 && A[j]>x){
            A[j+1] = A[j];
            j--;
        }
        A[j+1]=x;
    }
}

//selection sort   //O(n^2)
void SelectionSort(int A[],int n){
    for(int i=0; i<n-1; i++){
        int j; int k ;
        for(j=k=1; j<n; j++){
            if(A[j] < A[k]) {
                k=j;
            }
        }
        Swap(&A[i], &A[k]);
    }
}

//Quick Sort 2 methods  // O(nlogn)
int PartitionReursion(int A[],int low, int high){
    int pivot = A[low];
    int i = low; int j = high;
    do{
        do{
            i++;
        }
        while(A[j] <= pivot);
        do{
            j--;
        }
        while(A[j] > pivot);

        if(i < j){ Swap(&A[i], &A[j]);  }
    }
    while(i < j);

    Swap(&A[low], &A[j]);
    return j;
}

void QuickSortRecursion(int A[], int low, int high){
    if(low < high){
        int j = PartitionReursion(A,low,high);
        QuickSortRecursion(A,low,j);
        QuickSortRecursion(A,j+1,high);
    }
}


int partition(int A[], int low, int high){
    int pivot = A[low];
    int i = low+1;
    int j = high;

    while(true){
        while(i <= j && A[i] <= pivot){
            i++;
        }
        while(i <= j && A[i] >= pivot){
            j--;
        }
        if(j < i) break;
        else Swap(&A[i], &A[j]);
    }
    Swap(&A[low], &A[j]);
    return j;
}

void QuickSort(int A[], int low, int high){
    if(low < high){
        int p = partition(A, low, high);
        QuickSort(A, low, p-1);
        QuickSort(A, p+1, high);
    }
}
//merge of single array for mergesort
void Merge(int A[], int low, int mid, int high){
    int i = low; int j = mid+1; int k = low;
    int B[high+1];
    while(i <= mid && j <= high){
        if(A[i] < A[j]){
            B[k++] = A[i++];
        }
        else{
            B[k++] = A[j++];
        }
    }
    while(i <= mid){
        B[k++] = A[i++];
    }
    while(j <= high){
        B[k++] = A[j++];
    }
    for(int i=low; i<=high; i++){
        A[i] = B[i];
    }
}
void RecursiveMergeSort(int A[], int low, int high){
    if(low < high){
        int mid = low+(high-low)/2;

        RecursiveMergeSort(A, low, mid);
        RecursiveMergeSort(A, mid+1, high);

        Merge(A, low, mid, high);
    }
}
void IterativeMergeSort(int A[], int n){  //o(nlogn)
    int p;
    for(p=2; p<=n; p=p*2){
        for(int i=0; i+p-1<n; i=i+p){
            int low = i;
            int high = i+p-1;
            int mid = (low+high)/2;
            Merge(A, low, mid, high);
        }
    }
    if(p/2 < n){
        Merge(A, 0, p/2-1, n-1);
    }
}


//countSort O(m+n)
int Max(int A[], int n){
    int max = INT32_MIN;
    for(int i=0; i<n; i++){
        if(A[i] > max) max = A[i];
    }
    return max;
}

void CountSort(int A[], int n){
    int max = Max(A,n);
    int *count = new int[max+1];
    for(int i=0; i<max+1; i++){
        count[i]=0;
    }
    for(int i=0; i<n; i++){
        count[A[i]]++;
    }
    int i=0, j=0;
    while(j < max+1){
        if(count[j] > 0){
            A[i++] = j;
            count[j]--;
        }
        else j++;
    }

    delete []count;
}





int main() {
 
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n = sizeof(A)/sizeof(A[0]);
    Print(A, n, "\t\tA");
 
    Bubblesort(A, n);
    Print(A, n, " Sorted A");
 
    return 0;
}