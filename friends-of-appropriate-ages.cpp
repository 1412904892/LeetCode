#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int times[130];
        memset(times,0,sizeof times);
        for (int i=0;i<ages.size();i++){
            times[ages[i]]++;
        }

        int ans=0;
        for (int age=120;age>=1;age--){
            if (times[age]==0) continue;
            for (int k=age-1;k>=1;k--){
                if (times[k]==0) continue;
                if (check(age,k)){
                    ans=ans+times[age]*times[k];
                    //cout<<age<<"->"<<k<<endl;
                }
            }
        }
        for (int i=1;i<=120;i++){
            if (times[i]>=2){
                if (check(i,i))
                    ans=ans+(times[i]-1)*times[i];
            }
        }
        return ans;
    }
    bool check(int ageA,int ageB){
        if (ageB<=0.5*ageA+7) return false;
        if (ageB>ageA) return false;
        if (ageB>100 && ageA<100) return false;
        return true;
    }
};

int main(){


    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
}