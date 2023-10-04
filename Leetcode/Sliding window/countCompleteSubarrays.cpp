#include <bits/stdc++.h>
using namespace std;

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
            if (map.size() == kDistinctElement) {
                map[nums[left]]--;
                if (map[nums[left]] == 0) map.erase(map[left]);
                left ++;
            }
            cout << left << " " << right << "\n";
            right ++;
        }
        return ans;
    }
};

int main() {
    vector<int> nums {1, 3, 1, 2, 2};
    Solution problem;
    cout << problem.countCompleteSubarrays(nums) << "\n";

    return 0;
}
