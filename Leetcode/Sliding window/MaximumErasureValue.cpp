#include <bits/stdc++.h>
using namespace std;

/*
 * LeetCode Sliding Window
 * Maximum Erasure Value
*/

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // condition is subarray must have unique elements
        int n = nums.size();
        int ans = 0;

        int left = 0;
        int right = 0;
        
        int sum = 0;
        unordered_map<int, int> map;

        while (right < n) {
            sum += nums[right];
            map[nums[right]]++;

            while (map[nums[right]] >= 2) {
                map[nums[left]]--;
                sum -= nums[left];
                if (map[nums[left]] == 0) map.erase(nums[left]);
                left ++;
            }
            ans = max(ans, sum);
            right ++;
        }
        return ans;
    }
};

int main() {
    Solution problem1;
    vector<int> nums {5, 2, 1, 2, 5, 2, 1, 2, 5};
    cout << problem1.maximumUniqueSubarray(nums) << '\n';
    return 0;
}
