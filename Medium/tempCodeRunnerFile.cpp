#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Solution {
private:
    struct Node{
        string change_str;
        int step;
    };
public:
    int minMutation(string start, string end, vector<string>& bank) {
        Node fron;
        fron.change_str=start,fron.step=0;
        queue<Node> que;
        que.push(fron);

        while (!que.empty()){
            fron=que.front();
            que.pop();
            cout<<fron.change_str<<endl;
            system("pause");
            if (fron.change_str==end) return fron.step;

            for (int i=0;i<bank.size();i++){
                int diff=0;
                for(int k=0;k<bank[i].size();k++){
                    if (fron.change_str[k]!=bank[i][k]) 
                        diff++;
                }
                if (diff==1) {
                    Node temp;
                    temp.change_str=bank[i],temp.step=fron.step+1;
                    que.push(temp);
                }
            }
        }
        return -1;
    }
};

int main(){
    vector<string> vec={"AAAAAAAA","AAAAAAAC","AAAAAACC","AAAAACCC","AAAACCCC","AACACCCC","ACCACCCC","ACCCCCCC","CCCCCCCA"};
    Solution sol;
    sol.minMutation("AAAAAAAA","CCCCCCCC",vec);
}