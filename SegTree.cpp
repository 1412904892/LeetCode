#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int max_tree[30000*4+100];
int score[30000+10];
const int INF=1<<29;
void build(int num,int le,int ri){
    if (le==ri) max_tree[num]=score[le];
    else{
        build(num*2,le,(le+ri)/2);
        build(num*2+1,(le+ri)/2+1,ri);
        max_tree[num]=max(max_tree[num*2],max_tree[num*2+1]);
    }
}

void update(int num,int le,int ri,int pos,int x){
    if (le==ri){
        max_tree[num]=x;
        return;
    }
    int mid=(le+ri)/2;
    if (pos<=mid) update(num*2,le,mid,pos,x);
    else update(num*2+1,mid+1,ri,pos,x);
    max_tree[num]=max(max_tree[2*num],max_tree[num*2+1]);
}

int query(int num,int le,int ri,int l,int r){
    int p1=-INF,p2=-INF;
    if (le>=l&&ri<=r) return max_tree[num];
    int mid=(le+ri)/2;
    if (l<=mid) p1=query(2*num,le,mid,l,r);
    if (r>mid) p2=query(2*num+1,mid+1,ri,l,r);
    return max(p1,p2);
}

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for (int i=1;i<=n;i++){
            cin>>score[i];
        }
        build(1,1,n);
        char str[10];
        for (int i=1;i<=m;i++){
            int l,r;
            cin>>str>>l>>r;
            if (str[0]=='Q'){
                if (l>r) {
                    int tmp=l;
                    l=r;
                    r=tmp;
                }
                cout<<query(1,1,n,l,r)<<endl;
            }
            else{
                update(1,1,n,l,r);
            }
        }
    }
}