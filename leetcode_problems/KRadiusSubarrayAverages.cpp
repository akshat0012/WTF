#include <bits/stdc++.h>
using namespace std;
/*
 * K Radius Subarray Averages
 * Prefix Sum approach || O(N)
 */
class Solution {
    vector<int> prefixSumArray;
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0) {
            return nums;
        }
        if (nums.size() == 1) {
            return {-1};
        }

        vector<int> ans(n, -1);
        vector<long long> prefixArray(n+1);
        for (int i = 0; i < nums.size(); i ++) {
            prefixArray[i+1] = prefixArray[i] + nums[i];
        }
        for (int index = k; index < n-k; index ++) {
            // calculate the average and push it.
            int left = index - k, right = index + k; // i and j
            long long average = prefixArray[right + 1] - prefixArray[left] / (right - left + 1);
            ans[index] = average;
        }
        return ans;
    }

    void display(vector<int>* nums) {
         for (int l = 2; l < prefixSumArray.size(); l ++) cout << prefixSumArray[l] << " ";
         cout << endl;
         for (auto& i:*nums) cout << i << " ";
         cout << endl;
         cout << prefixSumArray.size() << endl;
    }
};

int main() {
    Solution problem1;
    vector<int> nUmS {7,4,3,9,1,8,5,2,6};
    int k = 3;
    problem1.getAverages(nUmS, k);
    problem1.display(&nUmS);
    return 0;
}