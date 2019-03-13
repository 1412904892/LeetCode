#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        stack<int> move_right;
        int len=asteroids.size();
        
        for (int i=0;i<len;i++){
            if (move_right.empty() && asteroids[i]<0){
                res.push_back(asteroids[i]);
            }
            else if (!move_right.empty() && asteroids[i]<0){
                while(!move_right.empty() && move_right.top()< -asteroids[i]){
                    move_right.pop();
                }
                if (!move_right.empty() &&  move_right.top()== -asteroids[i]){
                    move_right.pop();
                    continue;
                }
                if (move_right.empty()) res.push_back(asteroids[i]);
            }
            else if (asteroids[i]>0) move_right.push(asteroids[i]);
        }
        if (move_right.size()){
            int arr[move_right.size()];
            int index=0;
            while(!move_right.empty()){
                int top=move_right.top();
                arr[index++]=top;
                move_right.pop();
            }
            for (int i=index-1;i>=0;i--){
                res.push_back(arr[i]);
            }
        }
        return res;
    }
};

int main(){
    vector<int> vec;
    while(true){
        int n;
        cin>>n;
        for (int i=0;i<n;i++) {
            int tmp;
            cin>>tmp;
            vec.push_back(tmp);
        }
        Solution sol;
        vector<int> ans= sol.asteroidCollision(vec);
        for (int i=0;i<ans.size();i++){
            cout<<ans[i]<<' ';
        }
        cout<<endl;
        vec.clear();
        ans.clear();
    }
}