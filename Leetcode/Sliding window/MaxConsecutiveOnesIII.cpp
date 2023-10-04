#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
//    int longestOnes(vector<int>& nums, int k) {
//        int n = nums.size();
//        int ans = 0;
//
//        int left = 0;
//        int right = 0;
//        unordered_map<int, int> map;
//        while (right < n) {
//            map[nums[right]]++;
//            while (map[0] > k) {
//                map[nums[left]]--;
//                if (map[nums[left]] == 0) map.erase(nums[left]);
//                left ++;
//            }
//            ans = max(ans, right-left+1);
//            right ++;
//        }
//        return ans;
//    }

    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        int left = 0;
        int right = 0;
        int zeroCount = 0;

        while (right < n) {
            if (nums[right] == 0) zeroCount ++;
            while (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }
            ans = max(ans, right-left+1);
            right ++;
        }
        return ans;
    }
};


int main() {
    Solution problem1;
//    vector<int> nums {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    vector<int> nums {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout << problem1.longestOnes(nums, k) << "\n";

    return 0;
}