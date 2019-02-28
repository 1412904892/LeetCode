#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> que;
        map<string,int> IsExist; //字典中是否存在
        map<string,int> level; //层次
        for (int i=0;i<wordList.size();i++){
            IsExist[wordList[i]]=1;
        }
        level[beginWord]=1;
        que.push(beginWord);
        while (!que.empty() && IsExist.size()){
            string cur=que.front();
            que.pop();
            int num=level[cur];
            int len=cur.length();

            for (int i=0;i<len;i++){
                string tmp=cur;
                for (char j='a';j<='z';j++){
                    if (tmp[i]==j) continue;
                    else tmp[i]=j;

                    if (IsExist.find(tmp)!=IsExist.end()){
                        if (tmp==endWord){
                            return num+1;
                        }
                        que.push(tmp);
                        level[tmp]=num+1;
                        IsExist.erase(tmp);
                    }
                }
            }
        }
        return 0;
    }
};

int main(){

    return 0;
}