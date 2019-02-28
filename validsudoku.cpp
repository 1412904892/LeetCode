#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
using namespace std;

class Solution
{
  public:
    int isValidSudoku(vector<vector<char>> &board)
    {
        set<int> s;
        s.clear();
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] != '.')
                {
                    if (s.find(board[row][col]) != s.end())
                        return 1;
                    else
                        s.insert(board[row][col]);
                }
            }
            s.clear();
        }
        for (int col = 0; col < 9; col++)
        {
            for (int row = 0; row < 9; row++)
            {
                if (board[row][col] != '.')
                {
                    if (s.find(board[row][col]) != s.end())
                        return 2;
                    else
                        s.insert(board[row][col]);
                }
            }
            s.clear();
        }
        for (int row = 0; row < 9; row += 3)
        {
            for (int col = 0; col < 9; col += 3)
            {
                for (int i = row; i < row + 3; i++)
                {
                    for (int j = col; j < col + 3; j++)
                    {
                        if (s.find(board[i][j]) != s.end())
                            return 3;
                        else
                            s.insert(board[i][j]);
                    }
                }
            }
            s.clear();
        }
        return 4;
    }
};

int main()
{
    
    vector<vector<char>> vec;
    vector<char> tmp={};
    return 0;
}
