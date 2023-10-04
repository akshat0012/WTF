/*
 * Sliding Window and Bit Manipulation
 */
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int num = 0;
        int j = 0;
        for (int i = 0; i < n; i ++) {
            while ((num & nums[i]) == 0) {
                num ^= nums[j];  // here unset the bits set by nums[j]
            }
            num |= nums[i];
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};
