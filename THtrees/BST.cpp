#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        Node *lchild;
        int data;
        Node *rchild;
};
class BST{
    private:
        Node *root;
    public:
        BST(){ root = nullptr; }
        Node *Getroot(){ return root; }

        void iInsert(int key);
        Node *rInsert(Node *p, int key);

        Node *iSearch(int key);
        Node *rSearch(Node *p, int key);
        
        void inorder(Node *p);
        Node *Delete(Node*p, int key);
        int height(Node *p);
        Node *inPre(Node *p);  //inorder predecessor
        Node *inSucc(Node *p); //inorder succecessor\

        void CreateFromPreorder(int *pre,int n);

};

void BST::iInsert(int key){
    Node *t = root;
    Node *p;
    Node *r;
    if(root==nullptr){
        p=new Node;
        p->data = key;
        p->lchild = nullptr;
        p->rchild = nullptr;
        root= p;
        return ;
    }
    while(t!=nullptr){
        r=t;
        if(key < t->data)
            t= t->lchild;
        else if(key > t->data) 
            t= t->rchild;
        else return;
    }
    p=new Node;
    p->data = key;
    p->lchild = nullptr;
    p->rchild = nullptr;

    if(key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}
Node *BST:: rInsert(Node *p, int key){
    Node *t;
    if(p==nullptr){
        t= new Node;
        t->data = key;
        t->lchild = nullptr;
        t->rchild = nullptr;
        return t;
    }
    if(key < p->data)
        p->lchild = rInsert(p->lchild, key);
    else if(key > p->data)
        p->rchild = rInsert(p->rchild, key);

    return p;
}

Node *BST:: iSearch(int key){
    Node *t = root;
    while(t){
        if(key == t->data) return t;
        else if(key < t->data)  t=t->lchild;
        else  t=t->rchild;
    }
    return nullptr;
}
Node *BST:: rSearch(Node *p, int key){
    if(p==nullptr) return nullptr;
    if(key==p->data) return p;
    else if(key < p->data)
        rSearch(p->lchild,key);
    else
        rSearch(p->rchild, key);
}

void BST:: inorder(Node *p){
    if(p){
        inorder(p->lchild);
        cout<<p->data;
        inorder(p->rchild);
    }
}

Node *BST:: Delete(Node *p, int key){
    Node *q;
    if(p==nullptr) return nullptr;

    if(p->lchild == nullptr && p->rchild == nullptr){
        if(p==root){ root = nullptr; }
        delete p;
        return nullptr;
    }
    if(key < p->data)
        p->lchild = Delete(p->lchild, key);
    else if(key > p->data) 
        p->rchild = Delete(p->rchild, key);
    else{
        if(height(p->lchild) > height(p->rchild)){
            q= inPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else{
            q= inSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

int BST:: height(Node *p){
    int x,y;
    if(p==nullptr) return 0;
    x= height(p->lchild);
    y= height(p->rchild);
    return x>y ? x+1:y+1;
}

Node *BST::inPre(Node *p){
    while(p && p->rchild){
        p= p->rchild;
    }
    return p;
}
Node *BST:: inSucc(Node *p){
    while(p && p->lchild){
        p= p->lchild;
    }
    return p;
}

void BST:: CreateFromPreorder(int *pre, int n){
    int i=0;
    root=new Node;
    root->data = pre[i++];
    root->lchild = nullptr;
    root->rchild = nullptr;

    Node *t;
    Node *p= root;
    stack <Node*> stk;

    while(i<n){
        if(pre[i] < p->data){
            t= new Node;
            t->data = pre[i++];
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            stk.push(p);
            p=t;
        }
        else{
            if(pre[i] > p->data && pre[i] < stk.empty() ? 32767:stk.top()->data){
                t= new Node;
                t->data = pre[i++];
                t->lchild = nullptr;
                t->rchild = nullptr;
                p->rchild = t;
                stk.push(p);
                p=t;
            }
            else{
                p=stk.top();
                stk.pop();
            }
        }
    }

}

int main() {
 
    BST bst;
 
    // Iterative insert
    bst.iInsert(10);
    bst.iInsert(5);
    bst.iInsert(20);
    bst.iInsert(8);
    bst.iInsert(30);
 
    // Inorder traversal
    bst.inorder(bst.Getroot());
    cout << endl;
 
    // Iterative search
    Node* temp = bst.iSearch(2);
    if (temp != nullptr){
        cout << temp->data << endl;
    } else {
        cout << "Element not found" << endl;
    }
 
    // Recursive search
    temp = bst.rSearch(bst.Getroot(), 20);
    if (temp != nullptr){
        cout << temp->data << endl;
    } else {
        cout << "Element not found" << endl;
    }
 
    // Recursive insert
    bst.rInsert(bst.Getroot(), 50);
    bst.rInsert(bst.Getroot(), 70);
    bst.rInsert(bst.Getroot(), 1);
    bst.inorder(bst.Getroot());
    cout << "\n" << endl;
 
    // Inorder predecessor and inorder successor
    BST bs;
    bs.iInsert(5);
    bs.iInsert(2);
    bs.iInsert(8);
    bs.iInsert(7);
    bs.iInsert(9);
    bs.iInsert(1);
 
    temp = bs.inPre(bs.Getroot());
    cout << "InPre: " << temp->data << endl;
 
    temp = bs.inSucc(bs.Getroot());
    cout << "InSucc: " << temp->data << endl;
 
    bs.inorder(bs.Getroot());
    cout << endl;
 
    // Delete
    bs.Delete(bs.Getroot(), 7);
    bs.inorder(bs.Getroot());

    // BST from Preorder traversal
    cout << "BST from Preorder: " << flush;
    int pre[] = {30, 20, 10, 15, 25, 40, 50, 45};
    int n = sizeof(pre)/sizeof(pre[0]);
    BST b;
    b.CreateFromPreorder(pre, n);
    b.inorder(b.Getroot());
    cout << endl;
    
    return 0;
}
