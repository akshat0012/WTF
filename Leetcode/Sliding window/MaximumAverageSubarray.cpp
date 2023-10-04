#include <bits/stdc++.h>
using namespace std;
/*
 * Maximum Average Subarray
 * Fixed Sliding Window
 */
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // some base cases;
        if (nums.size() == 1) {
            return static_cast<double>(nums[0]);
        }
        if (nums.size() == k) {
            double _sum = 0;
            for (int l = 0; l < nums.size(); l ++) {
                _sum += nums[l];
            }
            return (_sum/k);
        }


        // calculate for first window
        double ans = INT_MIN;
        double sum = 0;
        for (int i = 0; i <= k-1; i ++) {
            sum += nums[i];
        }
        ans = max(ans, (sum/k));
        int left = 0;
        int right = k-1;
        while (right < nums.size()-1) {
            sum = sum + nums[right+1] - nums[left];
            ans = max(ans, (sum/k));
            left ++;
            right ++;
        }
        return ans;
    }
};


int main() {

    Solution problem1;
//    vector<int> nums {1, 12, -5, -6, 50, 3};
    vector<int> nums {1, -2, -3, -50, 7, 8};
    int k = 4;
    cout << problem1.findMaxAverage(nums, k) << endl;

    return 0;
}