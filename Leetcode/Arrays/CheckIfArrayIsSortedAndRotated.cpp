#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int ans = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i-1] > nums[i]) ans ++;
        }
        if (nums[nums.size()-1] > nums[0]) ans ++;
        return ans <= 1;
    }
}obj;

int main() {
    vector<int> nums {3, 4, 5, 1, 2};
    cout << obj.check(nums) << '\n';
}
