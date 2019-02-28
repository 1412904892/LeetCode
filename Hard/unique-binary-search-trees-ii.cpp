#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n==0) return {};
        return *generateTreesDFS(1,n);
    }

    vector<TreeNode*>* generateTreesDFS(int start,int end){
        vector<TreeNode*> *subTree=new vector<TreeNode*>();
        if (start>end){
            subTree->push_back(NULL);
        }
        else{
            for (int i=start;i<=end;i++){
                vector<TreeNode*> *leftTree=generateTreesDFS(start,i-1);
                vector<TreeNode*> *rightTree=generateTreesDFS(i+1,end);
                for (int j=0;j<leftTree->size();j++){
                    for (int k=0;k<rightTree->size();k++){
                        TreeNode *node=new TreeNode(i);
                        node->left=(*leftTree)[j];
                        node->right=(*rightTree)[k];
                        subTree->push_back(node);
                    }
                }
            }
        }
        return subTree;
    }
};