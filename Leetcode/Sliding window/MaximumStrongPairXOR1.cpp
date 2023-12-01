#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int ans = 0;
        for (int x=0; x<nums.size(); x++) {
            for (int y=0; y<nums.size(); y++) {
                if (abs(nums[x]-nums[y]) <= min(nums[x], nums[y])) {
                    // valid pair
                    ans = max(ans, nums[x] ^ nums[y]);
                }
            }
        }
        return ans;
    }
}obj;

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << obj.maximumStrongPairXor(nums) << "\n";
}
