#include <bits/stdc++.h>
using namespace std;

/*
 * Leetcode Daily Challenge
 * 16 June 23
 * O(N) Solution
 */

class Solution {
public:
    typedef  long long ll;
    ll MOD = 1e9 + 7;

    vector<vector<ll>> PT;

    int solve(vector<int>& nums) {

        int m = nums.size();
        if (m < 3) return 1;

        vector<int> leftArr, rightArr;
        int root = nums[0];

        for (int i = 0; i < m; i ++) { // populating the array
            if (nums[i] < root) {
                leftArr.push_back(nums[i]);
            }
            if (nums[i] > root) {
                rightArr.push_back(nums[i]);
            }
        }

        ll x = solve(leftArr) % MOD;
        ll y = solve(rightArr) % MOD;

        ll z = PT[m-1][leftArr.size()];
        return (((x * y) % MOD) * z) % MOD;
    };


    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        // Populating Pascal's Triangle to get NCR optimally

        PT.resize(n+1);
        for (int i = 0; i < n; i ++) {
            PT[i] = vector<ll>(i+1, 1);

            for (int j = 1; j < i; j ++) {
                PT[i][j] = (PT[i - 1][j] + PT[i - 1][j - 1]) % MOD;
            }
        }
        return (solve(nums)-1) % MOD;
    }
};
