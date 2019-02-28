#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int knightDialer(int N) {
        int mod=1000000000+7;
        if (N==1) return 10;
        if (N==0) return 0;
        if (N==2) return 20;
        int pre=20;
        for (int i=3;i<=N;i++){
            int sum=(pre*2)%mod+i*(i-1)%mod;
            pre=sum;
        }
        //cout<<pre<<endl;
        return pre;
    }
};

int main(){
    Solution sol;
    while (true){
        int n;
        cin>>n;
        sol.knightDialer(n);
    }
}