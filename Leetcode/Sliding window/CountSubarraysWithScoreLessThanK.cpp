#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        long long left = 0;
        long long right = 0;
        long long currSum = 0;
        int n = nums.size();

        while (right < n) {
            currSum += nums[right];
            long long score = currSum * (right-left+1);
            while (score >= k) {
                currSum -= nums[left++];
                score = currSum * (right-left+1);
            }
            if (score < k) ans += right-left+1;
            right ++;
        }
        return ans;
    }
}obj;

int main() {
    vector<int> nums {2, 1, 4, 3, 5};
    // vector<int> nums {1, 1, 1};
    long long k = 10;
    cout << obj.countSubarrays(nums, k);
    return 0;
}
