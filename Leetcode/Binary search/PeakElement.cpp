#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return 0;
    if (nums[0] > nums[1]) return 0;
    if (nums[n-1] > nums[n-2]) return n-1;

    int low = 1;
    int high = n-2;
    while (low <= high)  {
        int mid = (low + high) >> 1;
        if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])  return mid;
        if (nums[mid] > nums[mid-1]) low = mid+1;
        else high = mid-1;
    }
    return -1;
}

int main() {
    // vector<int> nums {1, 2, 3, 4, 6, 1, 2, 4};
    // vector<int> nums {1, 2};
    vector<int> nums {6, 5, 4, 3, 2, 3, 2};
    cout << nums[solve(nums)];
    return 0;
}
