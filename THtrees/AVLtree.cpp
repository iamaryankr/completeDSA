#include<iostream>
using namespace std;

class Node{
    public:
        Node *lchild;
        int data;
        Node *rchild;
        int height;
};

class AVL{
    public:
        Node *root;

        AVL(){ root = nullptr ; }
        int NodeHeight(Node *p);
        int BalanceFactor(Node *p);
        Node *LLrotation(Node *p);
        Node *RRrotation(Node *p);
        Node *LRrotation(Node *p);
        Node *RLrotation(Node *p);

        Node *inPre(Node *p);
        Node *inSucc(Node *p);

        Node *rInsert(Node *p, int key);
        void Inorder(Node *p);
        void Inorder() { Inorder(root); }
        Node *GetRoot(){ return root; }

        Node *Delete(Node *p,int key); 
};

int AVL:: NodeHeight(Node *p){
    int hl, hr;
    hl = (p && p->lchild) ? p->lchild->height : 0 ;
    hr = (p && p->rchild) ? p->rchild->height : 0 ;

    return hl > hr ? hl+1 : hr+1 ;
}
int AVL:: BalanceFactor(Node *p){
    int hl,hr;
    hl = (p && p->lchild) ? p->lchild->height : 0 ;
    hr = (p && p->rchild) ? p->rchild->height : 0 ;

    return hl-hr;
}

Node *AVL:: LLrotation(Node *p){
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = p;  //after rotating
    p->lchild = plr;

    p->height = NodeHeight(p); //updating height
    pl->height = NodeHeight(pl);

    if(root == p) root = pl;  //if rotation was about rootnode

    return pl;
}

Node *AVL:: RRrotation(Node *p){
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if(root==p) root= pr;

    return pr;
}
Node *AVL:: LRrotation(Node *p){
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = plr->lchild;  //after rotating
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    plr->height = NodeHeight(plr); //updating height
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(root == p) root = plr; //updating root

    return plr;
}
Node *AVL:: RLrotation(Node *p){
    Node *pr= p->rchild;
    Node *prl= pr->lchild;
    
    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;

    prl->rchild = pr;
    prl->lchild = p;

    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);

    if(root == p)  root = prl;

    return prl;
}

Node *AVL:: inPre(Node *p){
    while(p && p->rchild){
        p = p->rchild;
    }
    return p;
}
Node *AVL:: inSucc(Node *p){
    while(p && p->lchild){
        p = p->lchild;
    }
    return p;
}

Node *AVL:: rInsert(Node *p, int key){
    Node *t;
    if(p == nullptr){
        t=new Node;
        t->data = key;
        t->lchild = nullptr;
        t->rchild = nullptr;
        t->height = 1;   //starting height from 1
        return t;
    }
    if(key < p->data){
        p->lchild = rInsert(p->lchild, key);
    }
    else if(key > p->data){
        p->rchild = rInsert(p->rchild, key);
    }

    p->height = NodeHeight(p);

    if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
        return LLrotation(p);
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
        return LRrotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
        return RRrotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == 1)
        return RLrotation(p);

    return p;
}
void AVL:: Inorder(Node *p){
    if(p){
        Inorder(p->lchild);
        cout<< p->data <<", "<< flush;
        Inorder(p->rchild);
    }
}

Node *AVL:: Delete(Node *p, int key){
    if(p==nullptr) return nullptr;
    if(p->lchild == nullptr && p->rchild == nullptr){
        if(p==root) root = nullptr;
        delete p;
        return nullptr;
    }
    if(key < p->data){
        p->lchild = Delete(p->lchild,key);
    }
    else if(key > p->data){
        p->rchild = Delete(p->rchild, key);
    }
    else{
        Node *q;
        if(NodeHeight(p->lchild) > NodeHeight(p->rchild)){
            q = inPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else{
            q = inSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }

    p->height = NodeHeight(p); //updating height

    if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1){
        return LLrotation(p);  //L1 rotation
    }
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1){
        return LRrotation(p);  //L1 rotation
    }
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1){
        return RRrotation(p);  //R1 rotation
    }
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1){
        return RLrotation(p);  //R1 rotation
    }
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == 0){
        return LLrotation(p);  //L0 rotation
    }
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == 0){
        return RRrotation(p);  //R0 rotation
    }

    return p;
}



int main() {
 
    AVL tree;
 
    int A[] = {10, 20, 30, 25, 28, 27, 5};
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        tree.root = tree.rInsert(tree.root, A[i]);
    }
 
    tree.Inorder();
    cout << endl;
 
    tree.Delete(tree.root, 28);
   
    tree.Inorder();
    cout << endl;
 
    return 0;
}