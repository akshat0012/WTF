#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int left = 0;
        int right = 0;
        int distinct = 0;
        long long ans = 0;
        int n = nums.size();
        long long currSum = 0;
        unordered_map<int, int> mp;
        while (right < n) {
            if (mp[nums[right]] == 0) distinct ++;
            mp[nums[right]] ++;
            currSum += nums[right];
            while (right-left+1 > k) {
                mp[nums[left]] --;
                currSum -= nums[left];
                if (mp[nums[left]] == 0) {
                    mp.erase(nums[left]);
                    distinct --;
                }
                left ++;
            }
            if (distinct >= m) ans = max(ans, currSum);
            right ++;
        }
        return ans;
    }
}obj;

int main() {
    vector<int> nums {2,6,7,3,1,7};
    int m = 3;
    int n = 4;
    cout << obj.maxSum(nums, m, n) << '\n';
    return 0;
}
