class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return {-1, -1};
        vector<int> ans(2, -1);

        int low = 0;
        int high = nums.size() - 1;
        if (nums[0] == target)
            ans[0] = 0;
        else {
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (nums[mid] == target && target != nums[mid - 1]) {
                    ans[0] = mid;
                    break;
                }
                else if (nums[mid] < target)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        low = 0;
        high = nums.size() - 1;
        if (nums[nums.size() - 1] == target)
            ans[1] = nums.size() - 1;
        else {
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (nums[mid] == target && target != nums[mid + 1]) {
                    ans[1] = mid;
                    break;
                }
                else if (nums[mid] > target)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }

        return ans;
    }
};
