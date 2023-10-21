#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int ans = 0;
        int left = 0;
        int right = 0;
        int distinct = 0;
        int n = nums.size();
        vector<int> seen(n);
        while (right < n) {
            seen[nums[right]] ++;
            if (seen[nums[right]] == 1) distinct ++;
            while (distinct > 2) {
                seen[nums[left]] --;
                if (seen[nums[left++]] == 0) distinct --;
            }
            ans = max(ans, (right++)-left+1);
        }
        return ans;
    }
}obj;

int main() {
    vector<int> nums = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    cout << obj.totalFruit(nums);
    return 0;
}
