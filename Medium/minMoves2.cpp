#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if (nums.size()%2==0){
            return solve(nums,nums[nums.size()/2-1]);
        }
        else{
            return solve(nums,nums[(nums.size())/2]);
        }
    }
    int solve(vector<int> vec,int x){
        int num=0;
        for (int i=0;i<vec.size();i++){
            num=num+abs(vec[i]-x);
        }
        return num;
    }
};

int main(){
    int i=0;
    const int ci=i;
    auto b=ci;
    b=3;
    int *p=&i;
    decltype(*p) c=i;
}