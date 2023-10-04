#include <bits/stdc++.h>
using namespace std;
#define long long ll;
/*
 * Minimum Difference Between Highest and lowest of K scores.
 * Easy
 */
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;

        // sort the array
        sort(nums.begin(), nums.end());

        // base cases
        if (k == n) {
            return (nums[n-1] - nums[0]);
        }

        // implement the sliding window
        int left = 0;
        int right = k-1;
        for (right = k-1; right < nums.size(); right++) {
            ans = min(ans, nums[right]-nums[left]);
            left ++;
        }
        return ans;
    }
};

int main() {
    Solution problem1;
    vector<int> nums {9, 4, 1, 7};
    int k = 4;
    cout << problem1.minimumDifference(nums, k) << endl;
    return 0;
}