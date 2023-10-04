#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0;
        int col = m-1;
    
        while (row < n && col >= 0) {
            if (matrix[row][col] == target) return true;
            else if (target < matrix[row][col]) col -= 1;
            else row += 1;
        }
        return false; 
    }
}obj;

int main() {
    vector<vector<int>> nums {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 23},
        {18, 21, 23, 26, 30}
    };
    int target = 99;
    if (obj.searchMatrix(nums, target)) cout << "True";
    else cout << "False";
    return 0;
}
