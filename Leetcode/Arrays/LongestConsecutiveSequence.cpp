#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool linearSearch(vector<int>& nums, int el) {
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == el) return true;
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int ans = 1;
        for (int i=0; i<nums.size(); i++) {
            int element = nums[i];
            int count = 0;
            while (linearSearch(nums, element) == true) {
                element ++;
                count ++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
}obj;

int main() {
    vector<int> nums {100, 4, 200, 1, 2, 3};
    cout << obj.longestConsecutive(nums) << '\n';
    return 0;
}
