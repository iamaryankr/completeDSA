#include<iostream>
#include<stack>
using namespace std;

class Queue{
    private:
        stack <int> stk1;
        stack <int> stk2;
    public:
        Queue(){};
        ~Queue(){};
        void enqueue(int x);
        int dequeue();
};

void Queue:: enqueue(int x){
    stk1.push(x);
}
int Queue:: dequeue(){
    int x=-1;
    if(stk2.empty()){
        if(stk1.empty()){
            cout<<"queue underflow! "<<endl;
            return x;
        }
        else{
            while(!stk1.empty()){
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
    }
    x= stk2.top();
    stk2.pop();
    return x;
}

int main() {
 
    int A[] = {1, 3, 5, 7, 9};
 
    Queue q;
 
    cout << "Enqueue: " << flush;
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.enqueue(A[i]);
        cout << A[i] << flush;
        if (i < sizeof(A)/sizeof(A[0])-1){
            cout << " <- " << flush;
        }
    }
    cout << endl;
 
    cout << "Dequeue: " << flush;
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cout << q.dequeue() << flush;
        if (i < sizeof(A)/sizeof(A[0])-1){
            cout << " <- " << flush;
        }
    }
 
    return 0;
}