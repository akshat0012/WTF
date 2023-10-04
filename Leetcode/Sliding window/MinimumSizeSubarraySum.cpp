class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int sum = 0;
        int left = 0;
        int right = 0;
        while (right < n) {
            sum += nums[right];
            
            while (sum >= target) {
                ans = min(ans, right-left+1);
                sum -= nums[left];
                left ++;
            }

            right ++;
        }
        return (ans == INT_MAX) ? 0 : ans;
    }
};  
