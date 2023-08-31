class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st;
        for (int i=0; i<nums.size(); i++) st.insert(nums[i]);
        int kDistinctElement = st.size();
        int ans = 0;
        int left = 0;
        int right = 0;
        
        unordered_map<int, int> map;
        while (right < nums.size()) {
            map[nums[right]]++;
            while (map.size() >= kDistinctElement) {
                ans += nums.size()-right;
                map[nums[left]]--;
                if (map[nums[left]] == 0) map.erase(nums[left]);
                left ++;
            }
            right ++;
        }
        return ans;
    }
};
