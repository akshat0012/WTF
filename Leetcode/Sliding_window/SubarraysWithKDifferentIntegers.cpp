class Solution {
public:
    int helper(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int count = 0;
        int n = nums.size();
        unordered_map<int, int> mp;
        while (right < n) {
            mp[nums[right]] ++;
            while (mp.size() > k) {
                mp[nums[left]] --;
                if (mp[nums[left]] == 0) mp.erase(nums[left]);
                left ++;
            }
            count += right-left+1;
            right ++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k-1);
    }
};
