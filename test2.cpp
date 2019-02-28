#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        queue<int> que;
        int indegree[numCourses];
        int vis[numCourses];
        memset(indegree,0,sizeof indegree);
        memset(vis,0,sizeof vis);
        for (int i=0;i<prerequisites.size();i++){
            indegree[prerequisites[i].first]++;
        }
        for (int i=0;i<numCourses;i++){
            if (indegree[i]==0) que.push(i);
        }

        while (!que.empty()){
            int pre=que.front();
            vis[pre]=1;
            que.pop();
            for (int i=0;i<prerequisites.size();i++){
                if (prerequisites[i].second==pre){
                    indegree[prerequisites[i].first]--;
                    if (indegree[prerequisites[i].first]==0) que.push(prerequisites[i].first);
                }
            }
        }
        for (int i=0;i<numCourses;i++){
            if (vis[i]==0) return false;
        }
        return true;
    }
};

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int *ptr=(int *)(&a + 1);
    printf("%d, %d",*(a + 1), *(ptr -1 ));
    return 0;
}