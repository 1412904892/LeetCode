#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> sta;
        
        int push_len=pushed.size();
        int pop_len=popped.size();
        
        int index=0;
        for (int i=0;i<push_len;i++){
            //cout<<"top="<<sta.top()<<endl;
            while (!sta.empty()&&sta.top()==popped[index]){
                cout<<popped[index]<<endl;
                index++;
                sta.pop();
            }
            sta.push(pushed[i]);
        }
        while (!sta.empty()&&sta.top()==popped[index]){
            index++;
            sta.pop();
        }
        
        return sta.empty();
    }
};
int main(){
    vector<int> pushed={1,2,3,4,5};
    vector<int> poped={4,5,3,2,1};
    Solution sol;
    sol.validateStackSequences(pushed,poped);
}