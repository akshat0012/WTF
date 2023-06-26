#include <bits/stdc++.h>
using namespace std;
/*
 * K Radius Subarray Averages
 * Sliding window || o(N)
 *
 */
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);

        // base cases
        if (k == 0) {
            return nums;
        }
        if (2 * k + 1 > n) {
            return ans;
        }

        long currWindowSum = 0;
        for (int i = 0; i < (2*k+1); i ++) { // first window sum
            currWindowSum += nums[i];
        }
        ans[k] = currWindowSum/(2*k+1); // assign the average

        for (int l = k+1; l < n-k; l ++) {
            currWindowSum = currWindowSum - nums[abs(l - k) - 1] + nums[(l + k)];
            long average = currWindowSum / (abs(l + k) - (l - k) + 1);
            ans[l] = average;
        }
        return ans;
    }
};

int main() {
    Solution Problem1;
    vector<int> nums {7,4,3,9,1,8,5,2,6};
    Problem1.getAverages(nums, 3);

    return 0;
}
