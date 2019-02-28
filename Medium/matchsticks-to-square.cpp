#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& nums) {
       int sum=0;
       for (int i=0;i<nums.size();i++){
           sum+=nums[i];
       }

       if (sum%4!=0) return false;
       int *sums=new int[4];
       memset(sums,0,sizeof 0);
       return DFS(nums,sums,0,sum/4);
    }
    bool DFS(vector<int> vec,int sums[],int index,int average){
        if (vec.size()<=3 || index>vec.size()) return false;

        if (index==vec.size()){
            if (sums[0]==average&&sums[1]==average&&sums[2]==average&&sums[3]==average){
                return true;
            }
            else return false;
        }

        for (int i=0;i<4;i++){
            if (vec[index]+sums[i]<=average){
                if (i>0 && sums[i]==sums[i-1]) continue;
                sums[i]+=vec[index];
                if (DFS(vec,sums,index+1,average)) return true;
                sums[i]-=vec[index];
            }
        }
        return false;
    }
       
};

int main(){
    vector<int> nums={1,1,2,2,2};
    Solution sol;
    sol.makesquare(nums);
    return 0;
}