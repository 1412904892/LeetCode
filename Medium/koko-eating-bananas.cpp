#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int min_pile=__INT_MAX__,max_pile=-1;

        int len_piles=piles.size();
        for (int i=0;i<len_piles;i++){
            min_pile=min(min_pile,piles[i]);
            max_pile=max(max_pile,piles[i]);
        }

        if (len_piles==H) return max_pile;

        int low=1,high=max_pile;
        while(low<high){
            int mid=(low+high)/2;
            int hours=check(piles,mid);
            if (hours>H) low=mid+1;
            else if(hours<=H) high=mid;
            //cout<<"mid="<<mid<<" hour="<<hours<<endl;
        }
        cout<<low<<endl;
        return low;
    }
    int check(vector<int> pile,int eat){
        int len=pile.size();
        int hours=0;
        for (int i=0;i<len;i++){
            if (pile[i]%eat==0) hours=hours+pile[i]/eat;
            else hours=hours+pile[i]/eat+1;
        }
        return hours;
    }
};

int main(){
    vector<int> vec={332484035, 524908576, 855865114, 632922376, 222257295, 690155293, 112677673, 679580077, 337406589, 290818316, 877337160, 901728858, 679284947, 688210097, 692137887, 718203285, 629455728, 941802184};
    Solution sol;
    sol.minEatingSpeed(vec,823855818);
}

