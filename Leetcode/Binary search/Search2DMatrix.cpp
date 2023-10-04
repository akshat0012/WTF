#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool binarySearch(vector<int>& row, int target) {
        int low = 0;
        int high = row.size()-1;
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (target == row[mid]) return true;
            else if (target < row[mid]) high = mid-1;
            else low = mid+1;
        }
        return false;
    }
    bool search(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size()-1;
        int n = matrix[0].size();
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (matrix[mid][0] <= target && target <= matrix[mid][n-1]) return binarySearch(matrix[mid], target);
            // perform the rest of the Binary search Logic to shift the low and high
            else if (target < matrix[mid][0]) high = mid-1;
            else low = mid +1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0;
        int high = (m * n) - 1;
    
        while (low <= high) {
            int mid = (low + high)/2;
            int row = mid / n;
            int col = mid % n;
            if (target == matrix[row][col]) return true;
            else if (target > matrix[row][col]) low = mid+1;
            else high = mid-1;
        }
        return false;
    }

}obj;

int main() {
    vector<vector<int>> nums { 
        {1, 3, 5, 7},
        {10, 11, 16, 12},
        {23, 30, 34, 60}
    };
    int target = 7;

    if (obj.searchMatrix(nums, target)) cout << "True";
    else cout << "False";
    return 0;
}

