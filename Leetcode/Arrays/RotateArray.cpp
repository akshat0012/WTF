#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> helper(n);
        for (int i=0; i<n; i++) helper[ (i+k)%n ] = nums[i];
        for (int i=0; i<n; i++) nums[i] = helper[i];
    }
}obj;

int main() {
    vector<int> nums {1, 2, 3, 4, 5, 6};
    int k = 3;
    obj.rotate(nums, k);

    for (int i=0; i<nums.size(); i++) cout << nums[i] << " ";
}
