
/*
 *  Two Pointer Approach
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
