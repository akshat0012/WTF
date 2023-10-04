#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestEqualSubarray(vector<int> & nums, int k) {
        int ans = 1;
        int left = 0;
        int right = 0;
        int n = nums.size();
        unordered_map<int, int> map;
        while (right < n) {
            map[nums[right]] ++;
            int maxFreq = max(maxFreq, map[nums[right]]);
            int distinctElement = right-left+1 - maxFreq;
            while (distinctElement > k) {
                map[nums[left]]--;
                left ++;
                maxFreq = max(maxFreq, map[nums[right]]);
                distinctElement = right-left+1 - maxFreq;
            }
            ans = max(ans, right-left+1 - distinctElement);
            right ++;
        }
        return ans;
    }
}obj;

int main() {
    // vector<int> nums {1, 3, 2, 3, 1, 3};
    // vector<int> nums {1, 1, 2, 2, 1, 1};
    vector<int> nums {2, 1};
    int k = 0;
    cout << obj.longestEqualSubarray(nums, k);
}
