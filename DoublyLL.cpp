#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        Node* prev;
        int data;
        Node* next;
};

class DoublyLL{
    private:
        Node *head;
    public:
        DoublyLL();
        DoublyLL(int *A,int n);
        ~DoublyLL();
        void Display();
        int length();
        void insert(int index,int x);
        int Delete(int index);
        void Reverse();
};
DoublyLL:: DoublyLL(){
    head=new Node;
    head->prev=nullptr;
    head->data=0;
    head->next=nullptr;
}
DoublyLL:: DoublyLL(int *A,int n){
    head=new Node;
    head->prev=nullptr;
    head->data=A[0];
    head->next=nullptr;
    Node *tail=head;
    for(int i=1;i<n;i++){
        Node *t= new Node;
        t->prev=tail;
        t->data=A[i];
        t->next=tail->next;
        tail->next=t;
        tail= t;
    }
}
void DoublyLL::Display(){
    Node *p=head;
    while(p){
        cout<< p->data << flush;
        p=p->next;
        if(p){
            cout<<" <-> "<<flush;
        }
    }
    cout<<endl;
}
int DoublyLL:: length(){
    int len=0;
    Node* p;
    p=head;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}
void DoublyLL:: insert(int index,int x){
    if(index<0 || index>length()){ return ;}
    Node *p=head;
    Node *t=new Node;
    t->data=x;
    if(index==0){
        t->prev=nullptr;
        t->next=head;
        head->prev=t;
        head=t;
    }
    else{
        for(int i=0;i<index-1;i++)
            p=p->next;
        t->prev=p;
        t->next=p->next;
        if(p->next)
            p->next->prev=t;
        p->next=t;
    }
}
int DoublyLL:: Delete(int index){
    int x=-1;
    Node *p=head;
    if(index<0 || index>length())  return x;

    if(index==1){
        head=head->next;
        if(head){
            head->prev=nullptr;
        }
        x=p->data;
        delete p;
    }
    else{
        for(int i=0;i<index-1;i++)
            p=p->next;
        p->prev->next=p->next;
        if(p->next){
            p->next->prev= p->prev;
        }
        x=p->data;
        delete p;
    }
    return x;
}
void DoublyLL:: Reverse(){
    Node *p=head;
    Node *temp;
    while(p){
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
    }
    //checking condition again
    if(p->next==nullptr){
        p->next=p->prev;
        p->prev=nullptr;
        head=p;
    }
}
DoublyLL::~DoublyLL(){
    Node* p=head;
    while(head){
        head=head->next;
        delete p;
        p=head;
    }
}
int main() {
 
    int A[] {1, 3, 5, 7, 9};
 
    DoublyLL dll(A, sizeof(A)/sizeof(A[0]));
    cout << "Length: " << dll.length() << endl;
 
    dll.insert(0, 11);
    dll.insert(6, 13);
    dll.Display();
 
    dll.Delete(1);
    dll.Delete(6);
    dll.Display();
 
    dll.Reverse();
    dll.Display();
 
    return 0;
}