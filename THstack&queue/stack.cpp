#include<bits/stdc++.h>
using namespace std;
class Stack{
    private:
        int size;
        int top;
        int *s;
    public:
        Stack(int size);
        ~Stack();
        void Push(int x);
        int Pop();
        int Peek(int index);
        int isFull();
        int isEmpty();
        void Display();
        int StackTop();
};

Stack:: Stack(int size){
    this->size= size;
    top=-1;
    s = new int [size];
}

Stack:: ~Stack(){
    delete []s;
}

void Stack:: Push(int x){
    if(isFull()){
        cout<<"stack overflow! "<<endl;
    }
    else{
        top++;
        s[top]=x;
    }
}

int Stack:: Pop(){
    int x=-1;
    if(isEmpty()){
        cout<<"stack Underflow! "<<endl;
    }
    else{
        x=s[top];
        top--;
    }
    return x;
}

int Stack:: Peek(int index){    //index starts from the top while array from bottom
    int x=-1;
    if(top-index+1 < 0 || top-index+1 == size){
        cout<<"invalid Position! "<<endl;
    }
    else{
        x= s[top-index+1];
    }
}

int Stack:: isEmpty(){
    if(top==-1) return 1;
    else return 0;
}

int Stack:: isFull(){
    if(top==size-1) return 1;
    else return 0;
}

void Stack:: Display(){
    for(int i=top;i>=0;i--){
        cout<<s[i]<<" | "<<flush;
    }
    cout<<endl;
}

int Stack:: StackTop(){
    if(isEmpty()){
        return -1;
    }
    else{
        return s[top];
    }
}

//stack using LinkedList
class Node{
    public:
        int data;
        Node *next;
};
class StackLL{
    private: 
        Node *top;
    public:
        StackLL();
        ~StackLL();
        void Push(int x);
        int Pop();
        int Peek(int index);
        int isEmpty();
        int isFull();
        int StackTop();
};
StackLL:: StackLL(){
    top=nullptr;
}
StackLL:: ~StackLL(){
    Node *p = top;
    while(top){
        top = top->next;
        delete p;
        p=top; 
    }
}

void StackLL:: Push(int x){
    Node *t=new Node;
    if(t==nullptr){
        cout<<"stack overflow! "<<endl;
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

int StackLL:: Pop(){
    Node* p;
    int x=-1;
    if(top==nullptr){
        cout<<"stack underflow! "<<endl;
    }
    else{
        p=top;
        x=p->data;
        top=top->next;
        delete p;
    }
    return x;
}

int StackLL:: isEmpty(){
    return top?0:1;
}

int StackLL:: isFull(){
    Node *t= new Node;
    int r=t?1:0;
    delete t;
    return r;
}

int StackLL:: StackTop(){
    if(top){ 
        return top->data;
    }
    return -1;
}

int StackLL:: Peek(int index){
    if(isEmpty())
        return -1;
    else{
        Node *p=top;
        for(int i=0; p!=nullptr && i<index-1 ;i++){
            p->next;
        }
        if(p!=NULL){
            return p->data;
        }
        else{
            return -1;
        }
    } 
}
int isBalanced(char *exp){
    StackLL st;
    for(int i=0;i<strlen(exp);i++){
        if(exp[i]=='('){
            st.Push(exp[i]);
        }
        else if(exp[i]==')'){
            if(st.isEmpty()){
                return false;
            }
            else{
                st.Pop();
            }
        }
    }
}

int main(){
    int A[] = {1, 3, 5, 7, 9};
 
    StackLL stk;
 
    // Populate stack
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        stk.Push(A[i]);
    }
 
    cout << "Stack peek at 3rd: " << stk.Peek(3) << endl;
    cout << "Stack peek at 10th: " << stk.Peek(10) << endl;
    cout << "Stack top: " << stk.StackTop() << endl;
    cout << "Stack full: " << stk.isFull() << endl;
    cout << "Stack empty: " << stk.isEmpty() << endl;
 
    // Pop out elements from stack
    cout << "Popped: " << flush;
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cout << stk.Pop() << ", " << flush;
    }
    cout << endl;
 
    // Underflow
    cout << stk.Pop() << endl;
 
    return 0;
}