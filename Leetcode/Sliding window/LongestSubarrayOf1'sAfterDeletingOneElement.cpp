#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    } 
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int left = 0;
        int right = 0;
        int zCount = 0;
        while (right < n) {
            if (nums[right] == 0) zCount ++;
            while (zCount > 1) {
                if (nums[left] == 0) zCount --;
                left ++;
            }
            ans = max(ans, right-left);
            right ++;
        }
        return ans;
    }
};

int main() {
    Solution problem1;
    // vector<int> nums {1, 1, 0, 1};
    // vector<int> nums {0, 1, 1, 1, 0, 1, 1, 0, 1};
    vector<int> nums {1, 1, 1};
    cout << problem1.longestSubarray(nums) << endl;
    return 0;
}
