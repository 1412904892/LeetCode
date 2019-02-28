#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> hash;
        int ans=0;

        for (int i=0;i<wall.size();i++){
            int sum=0;
            for (int j=0;j<wall[i].size()-1;j++){
                sum+=wall[i][j];
                hash[sum]++;
            }
        }

        for (auto it:hash){
            ans=max(ans,it.second);
        }
        return wall.size()-ans;
    }
};

int main(){

}