#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        int  num;
        cin>>num;
        vector<int> vec1;
        int cnt=num;
        while (cnt){
            int tem=cnt%10;
            vec1.push_back(tem);
            cnt/=10;
        }
        sort(vec1.begin(),vec1.end());
        for (int i=2;;i++){
            int tem=i*num;
            vector<int> vec2;
            while (tem){
                int tmp=tem%10;
                vec2.push_back(tmp);
                tem=tem/10;
            }
            sort(vec2.begin(),vec2.end());
            if (vec1.size()==vec2.size()){
                bool flag=true;
                for (int i=0;i<vec1.size();i++){
                    if (vec1[i]!=vec2[i]) flag=false;
                }
                if (flag) {
                    cout<<"Possible"<<endl;
                    break;
                }
            }
            else if (vec2.size()>vec1.size()){
                cout<<"Impossible"<<endl;
                break;
            }
        }
    }
}