#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int table[100000+10];
        memset(table,0,sizeof table);
        for (int i=0;i<difficulty.size();i++){
            table[difficulty[i]]=max(profit[i],table[difficulty[i]]);
        }

        for (int i=1;i<=100000;i++){
            if (table[i-1]>table[i] || table[i]==0){
                table[i]=table[i-1];
            }
        }
        
        int ans=0;
        for (int i=0;i<worker.size();i++){
            ans+=table[worker[i]];
        }
        return ans;
    }
};

int main(){
    /*
    [66,1,28,73,53,35,45,60,100,44,59,94,27,88,7,18,83,18,72,63]
    [66,20,84,81,56,40,37,82,53,45,43,96,67,27,12,54,98,19,47,77]
    [61,33,68,38,63,45,1,10,53,23,66,70,14,51,94,18,28,78,100,16]
*/
    
}