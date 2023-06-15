#include <bits/stdc++.h>
using namespace std;

/*
 * Daily leetcode challenge
 * 13 June 23
 */

class Solution {
public:
    /*
     * Brute Force Solution
     * Time Complexity = O(N*N*N)
     */

//    int equalPairs(vector<vector<int>>& grid) {
//
//        int n = grid.size();
//        int count = 0;
//        for (int row = 0; row < n; row ++) {
//            for (int col = 0; col < n; col++) {
//                bool same = 1;
//                for (int element = 0; element < n; element ++) {
//                    if (grid[row][element] != grid[element][col]){
//                        same = false;
//                        break;
//                    }
//                }
//                count += same ? 1 : 0;
//            }
//        }
//        return count;
//    }

/*
 * we can't use unordered_map<vector<int>, int> c++ doesn't allow us to use
 * vector inside a unordered map
 *
 * Time complexity O(N*N)
 */
    int equalPairs(vector<vector<int>>& grid) {

        int n = grid.size();

        map<vector<int>, int> rowmap;

        vector<int> rowVector;
        vector<int> storingVector;

        for (int i = 0; i < n; i ++) {
            for (int col = 0; col < n; col ++) {
                rowVector.push_back(grid[i][col]);
            }
            rowmap[rowVector]++;
            rowVector.clear();
        }
        int count = 0;
        for (int i = 0; i < n; i ++) {
            for (int col = 0; col < n; col ++) {
                storingVector.push_back(grid[col][i]);
            }
            if (rowmap[storingVector] != 0) {
                count += rowmap[storingVector];
            }
            storingVector.clear(); // clear the vector to store next incoming column
        }
        cout << "Breakpoint" << endl; // for debugging purpose.
        return count;
    }
};

int main() {

    vector<vector<int>> grid = {
            {3, 1, 2, 2}, // --> row
            {1, 4, 4, 5},
            {2, 4, 2, 2},
            {2, 4, 2, 2}
    };

    Solution problem_1;
    problem_1.equalPairs(grid);




    return 0;
}