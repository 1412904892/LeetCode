#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (K==0 || N>=(K+W)) return 1.0;
        double dp[N+1];
        double res=0.0;
        double sum=0.0;

        for (int i=1;i<=N;i++){
            dp[i]=i<=W?sum/W+1.0/W:sum/W;
            cout<<dp[i]<<endl;
            if (i<K) sum+=dp[i];
            if (i>W) sum-=dp[i-W];
            if (i>=K) res+=dp[i];
        }
        return res;
    }
};

int main(){
    Solution sol;
    cout<<sol.new21Game(21,17,10);
}