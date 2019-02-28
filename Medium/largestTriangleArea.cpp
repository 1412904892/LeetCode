#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double max_area=0.0;
        for (int i=0;i<points.size();i++){
            for (int j=i+1;j<points.size();j++){
                for (int k=j+1;k<points.size();k++){
                    double a=dist(points[i][0],points[i][1],points[j][0],points[j][1]);
                    double b=dist(points[i][0],points[i][1],points[k][0],points[k][1]);
                    double c=dist(points[j][0],points[j][1],points[k][0],points[k][1]);
                    if (check(a,b,c)){
                        double p=(a+b+c)/2;
                        double ans=sqrt(p*(p-a)*(p-b)*(p-c));
                        max_area=max(ans,max_area);
                    }
                }
            }
        }
        return max_area;
    }

    double dist(double x1,double y1,double x2,double y2){
        double ans=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        return ans;
    }

    bool check(double a,double b,double c){
        if (a+b>c&&a+c>b&&b+c>a) return true;
        else return false;
    }
};

int main(){
    return 0;
}