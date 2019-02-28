#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

template<typename T>
struct BSTreeNode{
    T value;
    BSTreeNode* lchild;
    BSTreeNode* rchild;

    BSTreeNode(const T& value_):value(value_),lchild(NULL),rchild(NULL){}
};

template<typename T>
class BSTree{
    typedef BSTreeNode<T> node_type;
public:
    BSTree():root(NULL){}
    ~BSTree();
public:
    BSTree<T> &operator=(const BSTree<T>&);

    void insert_elem(const T&); //插入元素
    bool remove_elem(const T&); //删除元素
    void inoreder_traverse()const;

    T find_min()const; //查找最左边的元素 即为最小
    T find_max()const; //查找最右边的元素 即为最大
    node_type* search_elem(const T&)const; //查找某个元素
protected:
    node_type*  copy_tree(node_type*);

    void insert_elem(node_type* &,const T&);
    bool remove_elem(node_type* &,const T&);
    void inoreder_traverse(node_type*)const;
    void destory_tree(node_type* &);

    T find_max(node_type*) const;
    T find_min(node_type*) const;

    node_type* search_elem(node_type*,const T&)const;
private:
    node_type * root;  //每个对象都有一个根节点
};

// public interface
//销毁树
template<typename T>
BSTree<T>::~BSTree(){
    destory_tree(root);
}

template<typename T>
void BSTree<T>::insert_elem(const T& val){
    insert_elem(root,val);
}

template<typename T>
bool BSTree<T>::remove_elem(const T& val){
    remove_elem(root,val);
}

template<typename T>
void BSTree<T>::inoreder_traverse() const{
    inoreder_traverse(root);
}

template<typename T>
T BSTree<T>::find_min() const{
    return find_min(root);    
}

template<typename T>
T BSTree<T>::find_max()const{
    return find_max(root);
}

template<typename T>
BSTreeNode<T>* BSTree<T>::search_elem(const T& target) const{
    return search_elem(root,target);
}

//protected interface
template<typename T>
BSTreeNode<T>* BSTree<T>::copy_tree(node_type* t){
    node_type* tmp;
    if (t!=NULL){
        tmp=new node_type(t->value);
        tmp->lchild=copy_tree(t->lchild);
        tmp->rchild=copy_tree(t->rchild);
    }
    return tmp;
}

// void insert_elem(node_type* &,const T&);
template<typename T>
void BSTree<T>::insert_elem(node_type* &t,const T& val){
    if (t==NULL){
        t=new node_type(val);
        return;
    }
    if (t->value>val){
        return insert_elem(t->lchild,val);
    }
    else if (t->value<val){
        return insert_elem(t->rchild,val);
    }
    else return;
}

template<typename T>
bool BSTree<T>::remove_elem(node_type* &t,const T& val){
    if (t==NULL) return false;

    if (t->value>val){
        remove_elem(t->lchild,val);
    }
    else if (t->value<val){
        remove_elem(t->rchild,val);
    }
    else{
        if (t->rchild!=NULL&&t->lchild!=NULL){
            node_type* tmp=t;
            tmp=t->rchild;
            while(tmp->lchild!=NULL) tmp=tmp->lchild;
            t->value=tmp->value;
            //将右子树中最小的值，放到被删节点 然后在继续在被删几点的右子树中删除 这个值
            //这时 又变成了前面的几种情况
            remove_elem(t->rchild,t->value);
        }
        else{
            node_type* tmp=t;
            if (t->lchild!=NULL)
                t=t->lchild;
            else
                t=t->rchild;
            delete tmp;
        }
        return true;
    }
}

template<typename T>
void BSTree<T>::destory_tree(node_type*& t){
    if (t!=NULL){
        destory_tree(t->lchild);
        destory_tree(t->rchild);
        delete t;
    }
}

template<typename T>
T BSTree<T>::find_min(node_type * t)const{
    while (t->lchild!=NULL) t=t->lchild;
    return t->value;
}

template<typename T>
T BSTree<T>::find_max(node_type *t)const{
    while (t->rchild!=NULL) t=t->rchild;
    return t->value;
}

template<typename T>
BSTreeNode<T>* BSTree<T>::search_elem(node_type *t,const T& val)const{
    if (t==NULL) return NULL;
    else if (t->value>val) search_elem(t->lchild,val);
    else if (t->value<val) search_elem(t->rchild,val);
    else return t;
}

template<typename T>
void BSTree<T>::inoreder_traverse(node_type* t)const{
    if (t!=NULL){
        cout<<t->value<<' ';
        inoreder_traverse(t->lchild);
        inoreder_traverse(t->rchild);
    }
}

int main(){
    BSTree<int> bst;
    int A[]={46,20,23,60,50,55,70};
    for (int i=0;i<7;i++){
        bst.insert_elem(A[i]);
    }
    bst.inoreder_traverse();
    cout<<"before\n";
    bst.remove_elem(46);
    cout<<"after\n";
    bst.inoreder_traverse();
}