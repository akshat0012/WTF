#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rowSize = grid[0].size();
        int rowCount = grid.size();
        int ans = 0;
        int i = rowCount-1;
        int j = 0;
        
        while (i >= 0 && j < rowSize) {
            if (grid[i][j] < 0) {
                ans += rowSize-j;
                i--;
            }
            else {
                j++;
            }
        }
        return ans;
    }
}obj;

int main() {
    // vector<vector<int>> nums {
    //    {4, 3, 2, -1},
    //    {3, 2, 1, -1},
    //    {1, 1, -1, -2},
    //    {-1, -1, -2, -3}
    //};
    vector<vector<int>> nums {
        {3,-1,-3,-3,-3},
        {2,-2,-3,-3,-3},
        {1,-2,-3,-3,-3},
        {0,-3,-3,-3,-3}
    };
    cout << obj.countNegatives(nums);
}
