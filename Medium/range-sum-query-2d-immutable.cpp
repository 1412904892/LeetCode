#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class NumMatrix {
private:
    vector<vector<int>> matrix;
public:
    NumMatrix(vector<vector<int>> matrix_) {
        matrix=matrix_;
        if (matrix.size())
            matrix=sumMatrix(matrix);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1==0 && col1==0) return matrix[row2][col2];
        else if (row1==0&&col1!=0){
            int ans=matrix[row2][col2]-matrix[row2][col1-1];
            return ans;
        } 
        else if (row1!=0 && col1==0){
            int ans=matrix[row2][col2]-matrix[row1-1][col2];
        }
        else {
            int ans=matrix[row2][col2]-matrix[row1-1][col2]-matrix[row2][col1-1];
            return ans+matrix[row1-1][col1-1];
        }
    }

    vector<vector<int>> sumMatrix(vector<vector<int>> matrix){
        int raw=matrix.size(),col=matrix[0].size();
        
        vector<vector<int>> sum(raw,vector<int>(col,0));
        for (int i=0;i<col;i++) sum[0][i]=matrix[0][i];

        for (int i=1;i<raw;i++){
            for (int j=0;j<col;j++){
                sum[i][j]=sum[i-1][j]+matrix[i][j];
            }
        }

        for (int i=1;i<col;i++){
            for (int j=0;j<raw;j++){
                sum[j][i]=sum[j][i]+sum[j][i-1];
            }
        }
        return sum;
    }
};
int main(){
    vector<vector<int>> vec={{1,2,3},{4,5,6},{7,8,9}};
    NumMatrix *num=new NumMatrix(vec);
    cout<<num->sumRegion(0,0,1,1)<<endl;
    cout<<num->sumRegion(0,1,2,2)<<endl;
    cout<<num->sumRegion(1,0,2,2)<<endl;
}
