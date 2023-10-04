#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums) {      
    int n = nums.size();
    if (n == 1) return nums[0];
    // cases for the left most and right most element
    if (nums[0] != nums[1]) return nums[0];
    if (nums[n-1] != nums[n-2]) return nums[n-1];
    
    // Binary Search from here on trimmed down space
    int low = 1;
    int high = n-2;
    while (low <= high) {    
        int mid = (low + high) / 2;
        if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];

        if ( (mid % 2 == 1 && nums[mid-1] == nums[mid]) || (mid%2 == 0 && nums[mid] == nums[mid+1])) {
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return -1;
}

int main() {
//    vector<int> nums = {1, 1, 3, 3, 4, 4, 8, 8, 9};
    vector<int> nums {3, 3, 7, 7, 10, 11, 11};
    cout << solve(nums) << '\n';
}
