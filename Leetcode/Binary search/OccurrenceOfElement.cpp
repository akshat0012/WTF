#include <bits/stdc++.h>
using namespace std;
int solve(vector<int>& nums, int target) {
    int n = nums.size();
    int ans = 0;
    int fPos = -1;
    int lPos = n;

    int low = 0;
    int high = n-1;
        
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target && nums[mid] != nums[mid-1]) {
            fPos = mid;
            break;
        }
        else if (nums[mid] < target) {
            low = mid+1;
        }
        else high = mid-1;
    }
    low = 0;
    high = n-1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target && nums[mid] != nums[mid+1]){
            lPos = mid;
            break;
        }
        else if (nums[mid] > target) high = mid-1;
        else low = mid+1;
    }
    return lPos - fPos + 1;
}

int main() {
    int target = 3;
    vector<int> nums {1, 1, 1, 2, 2, 3, 3};
    cout << solve(nums, target);
//     for (int i=0; i<ans.size(); i++) cout << ans[i] << '\n';
    return 0;
}
