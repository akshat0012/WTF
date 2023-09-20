#include <bits/stdc++.h>
using namespace std;

// Size = 7
// 7 - 3 = 4


int maxScore(vector<int>& nums, int k) {
    int totalSum = 0;
    for (int i =0; i<nums.size(); i++) {
        totalSum += nums[i];
    }

    int ans = INT_MAX;
    int left = 0;
    int right = 0;
    int currSum = 0;
    int n = nums.size();

    while (right < n) {
        currSum += nums[right];
        while (right-left+1 > n-k) {
            currSum -= nums[left++];
        }
        if (right-left+1 == n-k) ans = min(ans, currSum);
        right ++;
    }
    return totalSum - ans; 
}


int main() {
//     vector<int> nums {1,2,3,4,5,6,1};
    vector<int> nums {96,90,41,82,39,74,64,50,30};
    cout << maxScore(nums, 8) << '\n';
    return 0;
}
