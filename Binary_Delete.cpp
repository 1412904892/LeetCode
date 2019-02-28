#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

template<class K>
struct BSTreeNode{
    BSTreeNode* lchild;
    BSTreeNode* rchild;
    K key;

    BSTreeNode(const K& key_){
        lchild=NULL;
        rchild=NULL;
        key=key_;
    }  
};

template<class K>
class BSTree{
private:
    typedef BSTreeNode<K> Node;
    Node *root;
public:
    //构造函数
    BSTree():root(NULL){}


    //非递归插入节点
    bool Insert(const K& key_){
        //如果是根节点 直接初始化
        if (root==NULL){
            root=new Node(key_);
        }

        Node* cur=root;
        Node* parent=NULL;

        while (cur){
            if (cur->key > key_){
                parent=cur;
                cur=cur->lchild;
            }
            else if (cur->key<key_){
                parent=cur;
                cur=cur->rchild;
            }
            else{
                //树中已经存在该值
                return false;
            }
        }

        if (parent->key>key_){
            parent->lchild=new Node(key_);
        }
        else{
            parent->rchild=new Node(key_);
        }

        return true;
    }

    //递归插入节点
    bool Insert_R(const K& key_){
        _Insert_R(root,key_);
    }    

    //前序遍历
    void Pre_Order(){
        _Pre_Order(root);
        cout<<endl;
    }
    //中序遍历
    void In_Order(){
        _In_Order(root);
        cout<<endl;
    }

    Node* Find(const K&key_){
        Node* cur=root;
        while (cur){
            if (cur->key>key_){
                cur=cur->lchild;
            }
            else if (cur->key<key_){
                cur=cur->rchild;
            }
            else return cur;
        }
        return NULL;
    }
    //递归查找
    Node * Find_R(const K&key_){
        return _Find_R(root,key_);
    }

    bool Remove(const K&key_){
        //如果根节点为空 失败
        if (root==NULL) return false;
        if (root->lchild==NULL&&root->rchild==NULL){
        }
    }

protected:
    //前序遍历
    void _Pre_Order(Node *T){
        if (T!=NULL){
            cout<<T->key<<" ";
            _Pre_Order(T->lchild);
            _Pre_Order(T->rchild);
        }
    }

    void _In_Order(Node *T){
        if (T!=NULL){
            _In_Order(T->lchild);
            cout<<T->key<<" ";
            _In_Order(T->rchild);
        }
    }

    bool _Insert_R(Node *& T,const K& key_){
        if (T==NULL){
            T=new Node(key_);
        }
        if (T->key>key_){
            return _Insert_R(T->lchild,key_);
        }
        else if (T->key<key_){
            return _Insert_R(T->rchild,key_);
        }
        else return false;
    }

    Node * _Find_R(Node *T,const K&key_){
        if (T==NULL) return NULL;
        if (T->key==key_) return T;
        else if (T->key>key_) {
            return _Find_R(T->lchild,key_);
        }
        else if (T->key<key_){
            return _Find_R(T->rchild,key_);
        }
    }
};



int main(){
    int A[]={4,2,3,9,6,5,10,1,7};
    BSTree<int> bstree;
    for (int i=0;i<9;i++){
        bstree.Insert_R(A[i]);
    }
    bstree.Pre_Order();
    BSTreeNode<int>* tmp= bstree.Find(3);
    if (tmp==NULL) cout<<"failed\n";
    else cout<<tmp->key<<endl;

    tmp=bstree.Find_R(5);
    if (tmp==NULL) cout<<"failed\n";
    else cout<<tmp->key<<endl;
    return 0;
}
