#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        int ans = 0;
        int left = 0;
        int right = 0;
        int currProduct = 1;
        int n = nums.size();

        while (right < n) {
            currProduct *= nums[right];
            while (currProduct >= k && left < right) {
                currProduct /= nums[left];
                left ++;
            }
            if (currProduct < k) ans += right-left+1;
            right ++;
        }
        return ans;
    }
}obj;

int main() {
    // vector<int> nums {10, 5, 2, 6};
    // vector<int> nums {1, 2, 3};
    //vector<int> nums {10,9,10,4,3,8,3,3,6,2,10,10,9,3};
    vector<int> nums {1, 1, 1};
    int k = 1;
    cout << obj.numSubarrayProductLessThanK(nums, k);
    return 0;
}
