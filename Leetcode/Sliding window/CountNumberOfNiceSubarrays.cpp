#include <bits/stdc++.h>
using namespace std;
/*
 * Sliding Window
 * Sub-arrays with K odd number = Sub-arrays with k Most odd numbers - Sub-arrays with most k-1 odd numbers
 */
class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int allSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0, odd = 0;
        int left = 0;
        int right = 0;
        while (right < n) {
            if (nums[right] %2 != 0) odd ++;
            while (odd > k) {
                if (nums[left] %2 != 0) odd --;
                left ++;
            }
//            if (odd == k) ans ++;
            ans += right-left+1;
            right ++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return allSubarrays(nums, k) - allSubarrays(nums, k-1);
    }
};

int main() {

    Solution problem1;
    vector<int> nums {1, 1, 2, 1, 1};
//    vector<int> nums {2,4,6};
//    vector<int> nums {2,2,2,1,2,2,1,2,2,2};
    int k = 3;
    cout << problem1.numberOfSubarrays(nums, k) << "\n";
    return 0;
}

