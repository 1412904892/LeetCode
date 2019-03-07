#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int left=0,right=0;
        int len=A.size();
        int zero_count=0;
        int res=0;

        while (right<len){
            if (A[right]==0) zero_count++;
            right++;
            while(zero_count>K){
                if (A[left]==0) zero_count--;
                left++;
            }
            res=max(right-left,res);
        }
        return res;
    }
};