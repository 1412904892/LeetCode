#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct ErrorLog{
    string name;
    string line;
    int count;
};

ErrorLog CreateLog(string name,string line){
    ErrorLog log;
    int nameLen=name.size();
    int index=-1; // '/'所在的位置
    
    for (int i=nameLen-1;i>=0;i--){
        if (name[i]=='\\'){
            index=i;
            break;
        }
    }
    name=name.substr(index+1);
    nameLen=name.size();
    if (nameLen>16){
        name=name.substr(nameLen-16);
    }
    log.name=name;
    log.line=line;
    log.count=1;
    return log;
}

void RecordErrorLog(int &number,ErrorLog log,vector<ErrorLog> &result){
    int resultSize=result.size();
    bool isExist=false;

    for (int i=0;i<resultSize;i++){
        if (result[i].name==log.name&&result[i].line==log.line){
            isExist=true;
            result[i].count++;
        }
    }
    if (isExist==false){
        result.push_back(log);
    }
}

bool cmp(ErrorLog &a,ErrorLog &b){
    return a.count>b.count;
}

int main(){
    string name,line;
    vector<ErrorLog> result;
    int number; //错误记录的数量

    while (cin>>name>>line){
        ErrorLog log=CreateLog(name,line);
        RecordErrorLog(number,log,result);
    }
    sort(result.begin(),result.end(),cmp);
    for (int i=0;i<result.size()&&i<8;i++){
        cout<<result[i].name<<' '<<result[i].line<<' '<<result[i].count<<endl;
    }
}