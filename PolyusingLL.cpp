#include<iostream>
#include<math.h>
using namespace std;
class Node{
    public:
        int coeff;
        int exp;
        Node *next;
};
class Poly{
    private:
        Node *p;
    public:
        Poly();
        ~Poly();
        void Create();
        void Display();
        long eval(int x);
        void Add(Poly *p1,Poly *p2);
};
Poly::Poly(){
    this->p=NULL;
}
Poly:: ~Poly(){
}
void Poly:: Create(){
    int term;
    Node *t, *last;
    cout<<"Enter the no of terms: ";
    cin>>term;
    while(term--){
        t=new Node;
        t->next=NULL;
        cout<<"Enter the coeff and exp of each term: ";
        cin>>t->coeff>>t->exp;
        if(p==NULL){
            p=last=t;
        }
        else{
            last->next=t;
            last=t;
        }
    }
}
void Poly:: Display(){
    Node *p= this->p;
    while(p){
        cout<<p->coeff<<"x^"<<p->exp;
        p=p->next;
    }
}
long Poly:: eval(int x){
    int val=0;
    Node *p1=p;
    while(p1){
        val+=p1->coeff*pow(x,p1->exp);
        p1=p1->next;
    }
    return val;
}
void Poly:: Add(Poly * p1, Poly * p2){
    Node *r=NULL;
    Node *ptr=p1->p;
    Node *q=p2->p;
    if(ptr->exp > q->exp){
        p=r=ptr;
        ptr=ptr->next;
        r->next=NULL;
    }
    else if(q->exp > ptr->exp){
        p=r=q;
        q=q->next;
        r->next=NULL;
    }
    else{
        p=r=ptr;
        r->coeff+=q->coeff;
        ptr=ptr->next;
        q=q->next;
        r->next=NULL;
    }
    while(ptr && q){
        if(ptr->exp > q->exp){
            r->next=ptr;
            r=ptr;
            ptr=ptr->next;
            r->next=NULL;
        }
        else if(q->exp > ptr->exp){
            r->next=q;
            r=q;
            q=q->next;
            r->next=NULL;
        }
        else{
            r->next=ptr;
            r=ptr;
            r->coeff += q->coeff;
            ptr=ptr->next;
            q=q->next;
            r->next=NULL;
        }
    }
    while(ptr){
        r->next=ptr;
        r=ptr;
        ptr=ptr->next;
        r->next=NULL;
    }
    while(q){
        r->next=q;
        r=q;
        q=q->next;
        r->next=NULL;
    }
}
int main(){
    Poly ptr;
    Poly r;
    int x=1;
    ptr.Create();
    ptr.Display();
 
// cout<<"\n"<<ptr.Eval(x)<<"\n";
    Poly q;
    q.Create();
    q.Display();
// cout<<"\n"<<q.Eval(x)<<"\n";
    r.Add(&ptr,&q);
    r.Display();
return 0;
}