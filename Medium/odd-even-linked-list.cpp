#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head==NULL || head->next==NULL) return head;
        ListNode * odd=head;
        ListNode * even=head->next;
        ListNode * evenHead=even;

        while(odd->next!=NULL && even->next!=NULL){
            odd->next=odd->next->next;
            even->next=even->next->next;

            odd=odd->next;
            even=even->next;
        }
        odd->next=evenHead;
        return head;
    }
};