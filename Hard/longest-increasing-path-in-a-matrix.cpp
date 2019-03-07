#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    bool isValid(int x,int y,int raw,int col){
        if (x >= 0 && x < raw && y >= 0 && y < col){
            return true;
        }
        return false;
    }
    int DFS(vector<vector<int>> &mat,vector<vector<int>> &vis,int x,int y,int &max_len){
        if (vis[x][y]!=0){
            return vis[x][y];
        }
        int raw=mat.size(),col=mat[0].size();
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        vis[x][y]=1;
        for (int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            if (isValid(xx,yy,raw,col) && mat[xx][yy]>mat[x][y]){
                int tmp=DFS(mat,vis,xx,yy,max_len);
                vis[x][y]=max(vis[x][y],tmp+1);
            }
        }
        max_len=max(max_len,vis[x][y]);
        return vis[x][y];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size()==0) return 0;

        int raw=matrix.size(),col=matrix[0].size();
        vector<vector<int>> vis(raw,vector<int>(col,0));
        int max_len=0;
        for (int i=0;i<raw;i++){
            for (int j=0;j<col;j++){
                if (vis[i][j]==0){
                    //cout<<"long :"<<" i="<<i<<" j="<<j<<endl;
                    DFS(matrix,vis,i,j,max_len);
                }
            }
        }
        return max_len;
    }
};

int main(){
    vector<vector<int>> vec={{9,9,4},{6,6,8},{2,1,1}};
    Solution sol;
    cout<<sol.longestIncreasingPath(vec);
}