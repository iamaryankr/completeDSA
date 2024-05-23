#include<iostream>
using namespace std;
class Array{
     private:
        int *A;
        int size;
        int length;
        void swap(int *x,int *y);
     public:
        Array(){
            size=10;
            length=0;
            A=new int[size];
     }
        Array(int sz){
            size=sz;
            length=0;
            A=new int[size];
     }
        ~Array(){
            delete []A;
     }
        void Display();
        void Append(int x);
        void Insert(int index,int x);
        int Delete(int index);
        int LinearSearch(int key);
        int LBinarySearch(int key);
        int RBinarySearch(int l, int h, int key);
        int Get(int index);
        void Set(int index,int x);
        int Max();
        int Sum();
        void Reverse();
        void Reverse2();
        void Leftshift();
        void RotateArray();
        void InsertSort(int x);
        bool isSorted();
        void Rearrange();
        Array* Merge(Array arr2);
        Array* Union(Array arr2);
        Array* Diff(Array arr2);
        Array* Inter(Array arr2);
};

void Array::Display( ){
         int i;
         cout<<"elements are: ";
         for(i=0;i<length;i++){
         cout<<A[i]<<" ";
    }
}
void Array::swap(int *x,int *y){
         int temp=*x;
         *x=*y;
         *y=temp;
}
void Array::Append(int x){
    if(length<size)
         A[length++]=x;
}
void Array::Insert(int index, int x){
    if(index>=0 && index <=length){
        for(int i=length;i>index;i--){
            A[i]=A[i-1];
            A[index]=x;
            length++;
        }
    }
}
int Array::Delete(int index){
    int x=0;
    int i;
    if(index>=0 && index<length){
        x=A[index];
        for(i=index;i<length-1;i++)
            A[i]=A[i+1];
        length--;
    return x;
    } 
return 0;
}
int Array::LinearSearch(int key){
         int i;
         for(i=0;i<length;i++){
              if(key==A[i]){
                  swap(&A[i],&A[0]);
                  return i;
                 }
         }
    return -1;
}

int Array:: LBinarySearch(int key){
    int l=0;
    int h=length-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(key==A[mid]) return mid;
        else if(key>A[mid]) l=mid+1;
        else h=mid-1;
    }
    return -1;
}

int Array:: RBinarySearch(int l, int h, int key){
     int mid=0;
     while(l<=h){
           mid=(l+h)/2;
           if(key==A[mid])  return mid;
           else if(key<A[mid]) return RBinarySearch(l,mid-1,key);
           else return RBinarySearch(mid+1,h,key);
     }
   return -1;
}
int Array:: Get(int index){
    if(index>=0 && index<length)
         return A[index];
return -1;
}
void Array:: Set(int x, int index){
    if(index>=0 && index<length)
         A[index]=x;   
}
int Array:: Max(){
    int max=A[0];
    for (int i = 0; i<length; i++){
        if(A[i]>max) 
             max=A[i];     
    }
    return max;
}
int Array:: Sum(){
    int sum=0;
    for(int i=0;i<length;i++){
        sum+=A[i];
    }
    return sum;
}
void Array:: Reverse(){
    int *B=new int[length];
    int i,j;
    for(i=length-1,j=0;i>=0,j<length;i--,j++){
        B[j]=A[i];
    }
    for(i=0;i<length;i++)
        A[i]=B[i];

}
void Array:: Reverse2(){
    int i,j;
    for(i=0,j=length-1;i<j;i++,j--){
        swap(&A[i],&A[j]);
    }
}
void Array:: Leftshift(){
    for(int i=0;i<length-1;i++){
        A[i]=A[i+1];
    }
        A[length-1]=0;
}
void Array:: RotateArray(){
    int t;
    t=A[0];
    for(int i=0;i<length-1;i++){
        A[i]=A[i+1];
    }
    A[length-1]=t;

}
void Array::InsertSort(int x){
    int i= length-1;
    if( length== size)
        return;
    while(i>=0 && A[i]>x){
        A[i+1]= A[i];
        i--;
    }
    A[i+1]=x;
    length++;
}
bool Array:: isSorted(){
    for(int i=0;i<length-1;i++){
        if(A[i]>A[i+1])
            return true;
     }
    return false;
}
void Array::Rearrange(){
    int i,j;
    i=0;
    j= length-1;
    while(i<j){
        while( A[i]<0)i++;
        while( A[j]>=0)j--;
        if(i<j)swap(& A[i],& A[j]);
    }
}

Array *Array::Merge(Array arr2){
    int i=0,j=0,k=0;
    Array *arr3=new Array[length+ arr2.length];
    while(i<length && j< arr2.length ){
        if(A[i]<arr2.A[j]) 
             arr3->A[k++]=A[i++];
        else 
             arr3->A[k++]=arr2.A[j++];
    }
    for(;i<length;i++)
             arr3->A[k++]=A[i];
    for(;j<arr2.length;j++)
             arr3->A[k++]=arr2.A[j];
    arr3->length=(length)+(arr2.length);
    arr3->size=10;
return arr3;
}

Array *Array::Union(Array arr2){
    int i=0,j=0,k=0;
    Array *arr3=new Array[length+ arr2.length];
    while(i<length && j<arr2.length){
            if(A[i]<arr2.A[j])
                arr3->A[k++]=A[i++];
            else if(A[i]>arr2.A[j])
                arr3->A[k++]=arr2.A[j++];
            else{
                arr3->A[k++]=A[i++];
                j++;
            }
    }
    for(;i<length;i++)
        arr3->A[k++]=A[i];
    for(;j<arr2.length;j++)
        arr3->A[k++]=arr2.A[j];
        arr3->length=k;
return arr3;

}
Array* Array::Inter(Array arr2){
    int i,j,k;
    i=j=k=0;
    Array *arr3=new Array(length+arr2.length);
    while(i<length && j<arr2.length){
        if(A[i]<arr2.A[j])  i++;
        else if(arr2.A[j]<A[i])  j++;
        else if(A[i]==arr2.A[j]){
            arr3->A[k++]=A[i++];
            j++;
        }
    }
    arr3->length=k;
 return arr3;
}

Array* Array::Diff(Array arr2){
    int i,j,k;
    i=j=k=0;
    Array *arr3=new Array(length+arr2.length);
    while(i<length && j<arr2.length){
        if(A[i]<arr2.A[j])
             arr3->A[k++]=A[i++];
        else if(arr2.A[j]<A[i])
             j++;
        else{
             i++;
             j++;
        }
    }
    for(;i<length;i++)
        arr3->A[k++]=A[i];
    arr3->length=k;
    
    return arr3;
}

int main(){
    Array *arr1;
    int ch,sz;
    int x,index;
    cout<<"Enter Size of Array";
    cin>>sz;
    arr1=new Array(sz);
 




        return 0;
}