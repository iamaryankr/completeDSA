#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
};
class CircularLL{
    private:
        Node *head;
    public:
        CircularLL(int A[],int n);
        void Display();
        void Rdisplay(Node *p);
        Node * getHead(){ return head; }
        ~CircularLL();
        void Insert(int pos,int x);
        int Delete(int pos);

};
CircularLL::CircularLL(int A[],int n){
    Node* t;
    Node* tail;
    head = new Node;
    head->data = A[0];
    head->next = head;
    tail = head;
    for(int i=1;i<n;i++){
        t=new Node;
        t->data = A[i];
        t->next= tail->next;
        tail->next = t;
        tail=t;
    }
}
void CircularLL:: Display(){
    Node *p = head;
    do{
        cout<<p->data<<" -> " <<flush;
        p=p->next;
    }
    while(p!=head);
    cout<<endl;
}
void CircularLL:: Rdisplay(Node* p){
    static int flag=0;
    if(p!=head || flag==0){
        flag =1 ;
        cout<<p->data <<" -> "<<flush;
        Rdisplay(p->next);
    }
    flag = 0;
}
CircularLL:: ~CircularLL(){
    Node *p=head;
    while(p->next != head)  p=p->next;
    while(p!=head){
        p->next = head->next;
        delete head;
        head= p->next;
    }
    if(p==head){
        delete head;
        head= nullptr;
    }
}
void CircularLL:: Insert(int pos,int x){
    Node *t,*p;
    if(pos==0){
        t=new Node;
        t->data=x;
        if(head==NULL){
            head =t ;
            head->next=head;
        }
        else{
            p=head;
            while(p->next!=head){
                p=p->next;
            }
            p->next;
            t->next=head;
            head=t;
        }
    }
    else{
        for(int i=0;i<pos-1;i++) 
            p=p->next;
        t=new Node;
        t->data=x;
        t->next=p->next;
        p->next=t;
    }
}
int CircularLL:: Delete(int pos){
    Node *p;
    int i,x;
    if(pos==0){
        while(p->next!=head)
            p=p->next;
        x=head->data;
        if(head==p){
            free(head);
            head=NULL;
        }
        else{
            p->next=head->next;
            free(head);
            head=p->next;
        }
    }
    else{
        Node *q;
        for(int i=0;i<pos-1;i++)
            p=p->next;
            q=p->next;
            p->next=q->next;
            x=q->data;
            free(q); 
    }
    return x;
}