#include <cstdio>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        unordered_map<int,unordered_set<int>> in_one_route;

        for (int i=0;i<routes.size();i++){
            for (int k=0;k<routes[i].size();k++){
                in_one_route[routes[i][k]].insert(i);
            }
        }

        queue<pair<int,int>> que;
        que.push(make_pair(S,0));
        unordered_set<int> visited={S};
        while (!que.empty()){
            int stop=que.front().first;
            int bus_num=que.front().second;
            que.pop();
            if (stop==T) return bus_num;

            for (auto& route:in_one_route[stop]){
                for (auto& next_stop:routes[route]){
                    if (visited.find(next_stop)==visited.end()){
                        visited.insert(next_stop);
                        que.push(make_pair(next_stop,bus_num+1));
                    }
                }
            }
        }
        return -1;
    }
};