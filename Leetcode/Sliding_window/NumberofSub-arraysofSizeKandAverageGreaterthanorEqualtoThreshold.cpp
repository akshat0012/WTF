#include <bits/stdc++.h>
using namespace std;
/*
 * Sliding Window
 * just use a initial loop to get the first window and then just update the left and right.
 */
class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {

        int n = arr.size();
        int ans = 0;
        int sum = 0;
        // initial loop
        for (int i = 0; i < k; i ++) sum += arr[i];
        if ((sum/k) >= threshold) ans ++;
        int left = 1;
        int right = k;
        while (right < n) {
            sum = sum + arr[right] - arr[left-1];
            if ((sum/k) >= threshold) ans ++;
            right ++;
            left ++;
        }
        return ans;
    }
};


int main() {
    Solution main;
    vector<int> arr {11,13,17,23,29,31,7,5,2,3};
    int k = 11, threshold = 5;
    cout << main.numOfSubarrays(arr, k, threshold) << endl;
    return 0;
}