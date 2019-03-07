#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if (A.size()==0) return 0;
        sort(A.begin(),A.end());

        map<int,int> m;
        int ans=0;
        int len=A.size();
        for (int i=len-1;i>=0;i--){
            if (m[A[i]]==0){
                m[A[i]]=1;
            }
            else{
                while(m[A[i]]==1){
                    A[i]++;
                    ans++;
                }
                m[A[i]]=1;
            }
        }      
        return ans;
    }
};