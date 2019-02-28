#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
using namespace std;


struct ListNode {
    int val;     
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL) return head;
        ListNode *Head=head;
        int len=0;
        ListNode *cur=head;
        while (cur!=NULL){
            cur=cur->next;
            len++;
        }
        k=k%len;
        if (k==0) return head;
        //找到倒数第k个节点
        cur=head;
        int num=len-k;
        while (cur!=NULL){
            num--;
            if (num==0) {
                break;
            }
            cur=cur->next;
        }
        ListNode* lasthead=cur->next;
        ListNode* lastcur=lasthead;
        cur->next=NULL;
        while (lastcur!=NULL){
            if (lastcur->next==NULL) break;
            lastcur=lastcur->next;
        }
        lastcur->next=head;
        return lasthead;
        
    }
};

int main(){
    ListNode* node1=new ListNode(0);
    ListNode* node2=new ListNode(1);
    ListNode* node3=new ListNode(2);
    ListNode* node4=new ListNode(4);
    node1->next=node2;
    node2->next=node3;
    //node3->next=node4;
    ListNode* cur=node1;
    while (cur){
        cout<<cur->val<<' ';
        cur=cur->next;
    }
    Solution sol;


}

