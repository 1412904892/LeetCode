#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

/**
 * Time:2019.1.14
 * 题目描述：给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。
 *          一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。
 *          你可以假设网格的四个边均被水包围。
 * 
*/
struct Node{
    int x,y;
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        if (grid.size()==0) return 0;

        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[i].size();j++){
                if (grid[i][j]=='1'){
                    BFS(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }

    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};

    void BFS(vector<vector<char>>& grid,int star_x,int star_y){
        queue<Node> que;
        Node fron;
        fron.x=star_x,fron.y=star_y;
        que.push(fron);
        grid[star_x][star_y]='2';

        while (!que.empty()){
            fron=que.front();
            que.pop();
            for (int i=0;i<4;i++){
                int x=fron.x+dx[i];
                int y=fron.y+dy[i];
                if (x>=0&&x<grid.size()&&y>=0&&grid[0].size()&&grid[x][y]=='1'){
                    grid[x][y]='2';
                    Node tem;
                    tem.x=x;
                    tem.y=y;
                    que.push(tem);
                }
            }
        }
    }
};