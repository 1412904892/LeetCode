#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int len=S.length()-1;
        vector<int> lr(len);
        vector<int> rl(len);
        stack<int> sta;

        for (int i=0;i<=len;i++){
            if (S[i]==C){
                sta.push(i);
            }
        }
        int last_index=S.length();
        for (int i=len;i>=0;i--){
            if (last_index>i) {
                if (!sta.empty()){
                    last_index=sta.top();
                    //cout<<"last_index="<<last_index<<endl;
                    sta.pop();
                }
            }
            rl[i]=abs(i-last_index);
        }
        
        for (int i=len;i>=0;i--){
            if (S[i]==C){
                sta.push(i);
            }
        }
        int first_index=-1;
        for (int i=0;i<=len;i++){
            if (first_index<i){
                 if (!sta.empty()){
                    first_index=sta.top();
                    //cout<<"last_index="<<last_index<<endl;
                    sta.pop();
                }
            }
            lr[i]=abs(i-first_index);
        }
        vector<int> ans;
        for (int i=0;i<=len;i++){
            ans.push_back(min(rl[i],lr[i]));
        }
        return ans;
    }
};

int main(){
    Solution sol;
    string S="loveleetcode";
    sol.shortestToChar(S,'e');
    return 0;
}