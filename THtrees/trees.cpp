#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node{
    public:
        Node* lchild;
        int data;
        Node* rchild;
        Node(){};
        Node(int data);
};
Node:: Node(int data){
    lchild= nullptr;
    this->data= data;
    rchild= nullptr;
}

class Tree{
    private:
        Node *root;
    public:
        Tree();
        ~Tree();
        void CreateTree();
        void Preorder(Node* p);
        void Preorder(){
            Preorder(root);
        }
        void Inorder(Node *p);
        void Inorder(){
            Inorder(root);
        }
        void Postorder(Node *p);
        void Postorder(){
            Postorder(root);
        }
        void Levelorder(Node *p);
        void Levelorder(){
            Levelorder(root);
        }
        int height(Node *p);
        int height(){
             height(root);
        }
        void iterativeInorder(Node *p);
        void iterativeInorder(){
            iterativeInorder(root);
        }

        Node* generatefromtraversal(int *inorder,int *preorder,int instart, int inend);

        int Count(Node *p);
        int Count(){
            Count(root);
        }
        int Sum(Node *p);
        int Sum(){
            Sum(root);
        }
};
Tree:: Tree(){
    root = nullptr;
}
Tree:: ~Tree(){
}

void Tree:: CreateTree(){
    Node *p,*t;
    int x;
    queue <Node*> q;
    root = new Node;
    cout<<"enter root data: "<<flush;
    cin>>x;
    root->data=x;
    root->lchild=nullptr;
    root->rchild=nullptr;

    q.emplace(root);

    while(!q.empty()){
        p=q.front();
        q.pop();

        cout<<"enter left child data: "<<p->data<<": "<<flush;
        cin>>x;
        if(x!=-1){
            t= new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            q.emplace(t);
        }
        cout<<"enter right child data: "<<p->data<<": "<<flush;
        cin>>x;
        if(x!=-1){
            t= new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            q.emplace(t);
        }
     }
}

void Tree:: Preorder(Node *p){
    if(p){
        cout<<p->data<<", "<<flush;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Tree:: Inorder(Node *p){
    if(p){
        Inorder(p->lchild);
        cout<<p->data<<", "<<flush;
        Inorder(p->rchild);
    }
}
void Tree:: Postorder(Node *p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout<<p->data;
    }
}

void Tree:: Levelorder(Node *p){
    queue<Node*> q;
    cout<< root->data <<", "<<flush;
    q.emplace(root);
    while(!q.empty()){
        p=q.front();
        q.pop();
        if(p->lchild){
            cout<<p->lchild->data<<", "<<flush;
            q.emplace(p->lchild);
        }
        if(p->rchild){
            cout<<p->rchild->data<<", "<<flush;
            q.emplace(p->rchild);
        }
    }
}
int Tree:: height(Node *p){
    int l=0; int r=0;
    if(p==nullptr){ return 0; }
    l= height(p->lchild);
    r= height(p->rchild);
    if(l>r) return l+1;
    else return r+1;
}

void Tree::iterativeInorder(Node *p){
    stack<Node *> stk;
    while(p!=nullptr || !stk.empty()){
        if(p!=nullptr){
            stk.emplace(p);
            p=p->lchild;
        }
        else{
            p=stk.top();
            stk.pop();
            cout<<p->data<<", "<<flush;
            p=p->rchild;
        }
    }
}

int searchInorder(int *inArray,int instart,int inend,int data){
    for(int i=instart;i<=inend;i++){
        if(inArray[i]==data){
            return i;
        }
        return -1;
    }
}
Node* Tree:: generatefromtraversal(int *inorder,int *preorder,int instart,int inend){
    static int preindex=0;
    if(instart>inend) return nullptr;
    Node *n =new Node(preorder[preindex]++);
    if(instart== inend) return n;

   int  splitindex= searchInorder(inorder,instart,inend,n->data);
    n->lchild=generatefromtraversal(inorder,preorder,instart,splitindex-1);
    n->rchild=generatefromtraversal(inorder,preorder,splitindex+1,inend);

    return n;
}

int Tree:: Count(Node* p){
    int x,y;
    if(p){
        x=Count(p->lchild);
        y=Count(p->rchild);
        return x+y+1;
    }
    return 0;
}
int Tree:: Sum(Node *p){
    int x,y;
    if(p){
        x=Sum(p->lchild);
        y=Sum(p->rchild);
        return x+y+1;
    }
    return 0;
}



int main() {
 
    Tree bt;
 
    // bt.CreateTree();
    // cout << endl;

    // cout<<"preorder : "<<flush;
    // bt.Preorder(); cout<<endl;

    // cout<<"inorder : "<<flush;
    // bt.Inorder(); cout<<endl;

    // cout << "Height: " << bt.height() << endl;

    // cout << "Levelorder: " << flush;
    // bt.Levelorder();
    // cout << endl;

    int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};
    int size=sizeof(inorder)/sizeof(inorder[0]);
    Node *T= bt.generatefromtraversal(inorder,preorder,0,size-1);

    cout<<"preorder: "<<flush;
    bt.Preorder(T);
    cout<<endl;

    cout<< "height "<<bt.height(T)<<endl;
    cout<< "count "<<bt.Count(T)<<endl;
    cout<< "sum "<<bt.Sum(T)<<endl;

return 0;
}

