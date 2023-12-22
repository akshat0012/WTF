#include <bits/stdc++.h>
using namespace std;
long long countSubarrays(vector<int>& nums, int k) {
    int ans = 0;
    int maxEl = INT_MIN;
    for (int i=0; i<nums.size(); i++) maxEl = max(maxEl, nums[i]);
    int left = 0;
    int right = 0;
    int count = 0;
    while (right < nums.size()) {
        count += (nums[right] == maxEl);
        while (count >= k) {
            ans += nums.size()-right;
            count -= (nums[left++] == maxEl);
        }
        right ++;
    }
    return ans;
}
int main() {
    vector<int> nums = {1, 3, 2, 3, 3};
    int k = 2;
    cout << countSubarrays(nums, k);
    return 0;
}
