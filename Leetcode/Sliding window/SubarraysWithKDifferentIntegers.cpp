#include <bits/stdc++.h>
using namespace std;
// coding ninjas
int helper(vector<int>& arr, int n, int k) {
    int ans = 0;
    int left = 0;
    int right = 0;
    unordered_map<int, int> mp;
    while (right < n) {
        mp[arr[right]] ++;
        while (mp.size() > k) {
            mp[arr[left]] --;
            if (mp[arr[left]] == 0) mp.erase(arr[left]);
            left ++;
        }
        ans += right-left+1;
        right ++;
    }
    return ans;
}
int goodSubarrays(vector<int>& arr, int n, int b) {
    return helper(arr, n, b) - helper(arr, n, b-1);
}

int main() {
    vector<int> nums {1, 2, 1, 3, 4};
    cout << goodSubarrays(nums, nums.size(), 3);
    return 0;
}
