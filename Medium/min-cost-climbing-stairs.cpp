#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size()==2) return min(cost[0],cost[1]);
        for (int i=2;i<cost.size();i++){
            cost[i]=min(cost[i-1]+cost[i],cost[i-2]+cost[i]);
        }
        return min(cost[cost.size()-1],cost[cost.size()-2]);
    }
};

int main(){
    map<int,int> m;
    cout<<m[4]<<endl;
    return 0;
}