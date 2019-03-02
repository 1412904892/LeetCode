#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

struct Points{
    int x,y;
};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        queue<Points> que;
        if (grid.size()==0) return 0;
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));

        int ans=0;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (grid[i][j]==1 && vis[i][j]==false){
                    int tmp=BFS(grid,vis,i,j);
                    ans=max(tmp,ans);
                }
            }
        }
        return ans;
    }
    
    int BFS(vector<vector<int>>&grid,vector<vector<bool>> &vis,int x_,int y_){
        cout<<"x="<<x_<<" y="<<y_<<endl;
        queue<Points> que;
        Points cur;
        cur.x=x_,cur.y=y_;
        que.push(cur);
        vis[x_][y_]=true;
        int area=0;

        while (!que.empty()){
            cur=que.front();
            que.pop();
            area++;
            cout<<area<<endl;
            cout<<"cur.x="<<cur.x<<" cur.y="<<cur.y<<endl;
            for (int i=0;i<4;i++){
                cout<<"dx="<<dx[i]<<" dy="<<dy[i]<<endl;
                int xx=cur.x+dx[i];
                int yy=cur.y+dy[i];
                cout<<"xx="<<xx<<" yy="<<yy<<endl;
                if (xx>=0 && xx<grid.size() && yy>=0 && yy<grid[0].size()){
                    if (grid[xx][yy]==1 && vis[xx][yy]==false){
                        Points tmp;
                        tmp.x=xx;
                        tmp.y=yy;
                        vis[xx][yy]=true;
                        que.push(tmp);

                    }
                }
            }
        }
        return area;
    }
};

int main(){
    vector<vector<int>> vec={{1,1},{1,0}};
    Solution sol;
    sol.maxAreaOfIsland(vec);
}