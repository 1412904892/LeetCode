#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    bool vis[222];
    int n;
public:
    int findCircleNum(vector<vector<int>>& M) {
        int ans=0;
        memset(vis,false,sizeof vis);
        if (M.size()==0) return 0;
        n=M[0].size();
        for (int i=0;i<M.size();i++){
            for (int j=0;j<M[0].size();j++){
                if (vis[i]==false&&M[i][j]==1){
                    ans++;
                    BFS(i,M);
                }
            }
        }
        return ans;
    }

    void BFS(int start,vector<vector<int>> M){
        queue<int> que;
        que.push(start);
        vis[start]=true;

        while (!que.empty()){
            int fr=que.front();
            que.pop();
            //cout<<fr<<endl;
            for (int i=0;i<n;i++){
                if (vis[i]==false&&M[fr][i]==1){
                    que.push(i);
                    vis[i]=true;
                }
            }
        }
    }
};

int main(){
    vector<vector<int>> vec={{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};
    Solution sol;
    cout<<sol.findCircleNum(vec);

}