#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m==n) return head;
        ListNode* p=head;
        ListNode* last=NULL;
        ListNode* front=NULL;
        ListNode* cur=NULL;
        ListNode* pre=NULL;
        ListNode* post=NULL;
        int num=0;
        while(p){
            num++;
            ListNode* tmp=p->next;
            cout<<"num="<<num<<endl;
            if (num==m){
                front=p;
                front->next=NULL;
                cur=front;
                cout<<1<<endl;
            }
            if (num==n){
                last=p;
                last->next=cur;
                cur=last;
                cout<<2<<endl;
            }
            if (num>m&&num<n){
                p->next=cur;
                cur=p;
                cout<<3<<endl;
            }
            if (num==m-1){
                pre=p;
                cout<<4<<endl;
            }
            if (num==n+1){
                post=p;
                cout<<5<<endl;
            }
            p=tmp;
        }
        if (pre!=NULL){
            pre->next=last;
        }
        else {
            head=last;
        }
        front->next=post;


        p=head;
        while (p){
            cout<<p->val<<' ';
            p=p->next;
        }
        return head;
    }
};

int main(){
    ListNode* node1=new ListNode(1);
    ListNode* node2=new ListNode(2);
    ListNode* node3=new ListNode(3);
    ListNode* node4=new ListNode(4);
    ListNode* node5=new ListNode(5);
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;
    Solution sol;
    sol.reverseBetween(node1,1,5);
    return 0;
}