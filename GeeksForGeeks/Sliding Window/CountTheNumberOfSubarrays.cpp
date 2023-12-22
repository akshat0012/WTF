#include <bits/stdc++.h>
using namespace std;

long long subarray(int n, vector<int> nums, long long limit) {
    int left = 0;
    int right = 0;
    long long ans = 0;
    long long currSum = 0;
    while (right < n) {
        currSum += nums[right];
        while (currSum > limit) {
            currSum -= nums[left];
            left ++;
        }
        ans += (right-left+1);
        right ++;
    }
    return ans;
}
long long countSubarray(int n, vector<int> nums, long long L, long long R) {
    return subarray(n, nums, R) - subarray(n, nums, L-1);
}

int main() {
    vector<int> nums = {2, 3, 5, 8};
    cout << countSubarray(4, nums, 4, 13) << "\n";
    return 0;
}
