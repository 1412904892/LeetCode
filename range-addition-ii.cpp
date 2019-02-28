#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int row=m,col=n;
        for (int i=0;i<ops.size();i++){
            row=min(row,ops[i][0]);
            col=min(col,ops[i][1]);
        }
        return col*row;
    }
};

int main(){

}