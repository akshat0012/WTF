class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans = 0;
        bool flag = 0;
        int count = 0;
        for (int i=0; i<nums.size(); i++) {

            if (nums[i] <= threshold && nums[i]%2 == flag) {
                count ++;
                flag = flag^1;
            }
            else {
                // calculate the answer
                ans = max(ans, count);
                flag = 0;
                count = 0;
                if (nums[i] <= threshold && nums[i]%2 == 0) {
                    count = 1;
                    flag = 1;
                }
            }
        }
        ans = max(ans, count);
        return ans;
    }
};
