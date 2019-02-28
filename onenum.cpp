#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.size()==0) return;
        int row=board.size();
        int col=board[0].size();

        for (int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                int count=0;
                for (int x=max(0,i-1);x<=min(row-1,i+1);x++){
                    for (int y=max(0,j-1);y<=min(col-1,j+1);y++){
                        if (x==i && y==j) continue;
                        if (board[x][y]==1 || board[x][y]==2){
                            count++;
                        }
                    }
                }
                if (board[i][j]==0 && count==3)
                    board[i][j]=3;
                else if (board[i][j]==1 &&(count>3||count<2))
                    board[i][j]=2;
            }
        }
        for (int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                board[i][j]=board[i][j]%2;
            }
        }
    }
};

int main(){
    vector<vector<int>> vec={{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    Solution sol;
    sol.gameOfLife(vec);
    for (int i=0;i<vec.size();i++){
        for (int j=0;j<vec[i].size();j++){
            cout<<vec[i][j]<<' ';
        }
        cout<<endl;
    }
}
