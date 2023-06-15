#include <vector>
#include <iostream>
#include <algorithm>
using namespace  std;

/*
 *  Two Pointer Problem
 *  O(N)
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;

        int area = 0;

        while (i < j) {
            area = max(area, (j-i)*min(height[i], height[j]));
            if (height[j] < height[i]) {
                j --;
            }
            else if (height[i] < height[j]) {
                i ++;
            }
            else if (height[i] == height[j]) {
                i ++;
            }
        }
        return area;
    }
};

int main() {
    Solution problem_1;
    vector<int> height {1, 8, 100, 2, 100, 4, 8, 3, 7};
    problem_1.maxArea(height);

    return 0;
}