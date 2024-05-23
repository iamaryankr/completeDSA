#include<iostream>
using namespace std;
class Node{
    public:
        int col;
        int val;
        Node *next;
};
class Sparse{
    private:
        int trow;
        int tcol;
        Node **a;
    public:
        Sparse(int r,int c){
            trow=r;
            tcol=c;
            Node *t, *last;
            a=new Node*[r];
            int i,x;
            for(i=0;i<r;i++){
                a[i]=NULL;
            }
            for(i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    cout<<"enter the element at row: "<<i<<"and column: "<<j<<endl;
                    cin>>x;
                    if(x!=0){
                        if(a[i]=NULL){
                            t=new Node;
                            t->col=j;
                            t->val=x;
                            t->next=NULL;
                            a[i]=t;
                            last=t;
                        }
                        else{
                            t=new Node;
                            t->col=j;
                            t->val=x;
                            t->next=t;
                            last=t;
                        }
                    }
                }
                cout<<endl;
            }
        }
        void Display(){
            Node* p;
            for(int i=0;i<trow;i++){
                p=a[i];
                for(int j=0;j<tcol;j++){
                    if(p!=NULL && j==p->col){
                        cout<<p->val<<" ";
                        p=p->next;
                    }
                    else
                        cout<<"0 ";
                }
                cout<<endl;
            }
        }
};

int main(){
    Sparse a(2,2);
    a.Display();
}