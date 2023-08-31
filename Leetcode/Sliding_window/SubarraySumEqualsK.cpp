class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int right = 0;
        int currSum = 0;
        unordered_map<int,int> mp;
        int n = nums.size();
        while (right<n) {
            currSum += nums[right];
            if (currSum == k) ans ++;
            if (mp.find(currSum-k) != mp.end()) {
                ans = mp[currSum-k] + ans;
            }
            if (mp.find(currSum) != mp.end()) {
                mp[currSum] ++;
            } else {
                mp[currSum] = 1;
            }
            right ++;
        }
        return ans;
    }
};
