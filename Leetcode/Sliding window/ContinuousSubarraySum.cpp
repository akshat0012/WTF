#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int n = nums.size();
        int currSum = 0;
        unordered_map<int, int> mp;
        mp[0] = 0;

        while (right < n) {
            currSum += nums[right];
            int rem = currSum % k;
            
            if (mp.find(rem) != mp.end() && right-mp[rem]+1 >= 2) {
                return true;
            }
            else if (mp.find(rem) == mp.end()) {
                mp[rem] = right+1;
            }
            right ++;
        }
        return false;
    }
}obj;

int main() {
    vector<int> nums {23, 2, 6, 4, 7};
    int k = 13;
    if (obj.checkSubarraySum(nums, k)) cout << "True";
    else cout << "False";
    return 0;
}
