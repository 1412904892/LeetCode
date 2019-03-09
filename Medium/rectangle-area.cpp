#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1=(C-A)*(D-B);
        int area2=(G-E)*(H-F);
        if (E>=C || F>=D || A>=G || B>=H) return area1+area2;
        int topX=min(G,C),topY=min(H,D);
        int bottomX=min(A,E),bottomY=min(B,F);
        return area1-(topX-bottomX)*(topY-bottomY)+area2;
    }
};