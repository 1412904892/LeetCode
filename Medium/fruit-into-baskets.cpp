#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int len=tree.size();
        int first_type=-1,first_num=0;
        int secon_type=-1,secon_num=0;
        int ans=0;
        for (int i=0;i<len;i++){
            if (first_type==-1){
                first_type=tree[i];
                first_num++;
                continue;
            }
            else if (first_type!=tree[i]&&secon_type==-1){
                secon_type=tree[i];
                secon_num++;
                continue;
            }

            if (first_type==tree[i]) first_num++;
            else if (secon_type==tree[i]) secon_num++;
            else {
                ans=max(ans,first_num+secon_num);
                if (tree[i-1]==first_type){
                    int star=i-1;
                    first_num=0;
                    while (star>=0){
                        if (tree[star]==first_type) first_num++;
                        else break;
                        star--;
                    }
                    secon_type=tree[i];
                    secon_num=1;
                }
                else{
                    int star=i-1;
                    secon_num=0;
                    while (star>=0){
                        if (tree[star]==secon_type) secon_num++;
                        else break;
                        star--;
                    }
                    first_type=secon_type;
                    first_num=secon_num;
                    secon_type=tree[i];
                    secon_num=1;
                }
            }
            //cout<<"first_type="<<first_type<<" first_num="<<first_num<<endl;
            //cout<<"secon_type="<<secon_type<<" secon_num="<<secon_num<<endl;
            //cout<<endl;
        }
        return max(ans,first_num+secon_num);
    }
};

int main(){
    vector<int> vec;
    int n;
    cin>>n;
    for (int i=0;i<n;i++) {
        int tmp;
        cin>>tmp;
        vec.push_back(tmp);
    }
    Solution sol;
    cout<<sol.totalFruit(vec)<<endl;
}