#include <bits/stdc++.h>
using namespace std;
/*
 * Sliding window
 * just monitor the changes you have to make to get the desired window of k consecutive Blacks
 * and just return window with minimum changes.
 */
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        // sliding window
        int n = blocks.size();
        int changes = 0;
        int ans = INT_MAX;

        // initial loop
        for (int i = 0; i < k; i ++) if (blocks[i] == 'W') changes ++;
        ans = changes;
        // base case
        if (n == k) return changes;

        int left = 0;
        int right = k-1;
        while (right < n) {
            if (blocks[right+1] == 'W' && blocks[left] == 'B') changes ++;
            if (blocks[right+1] == 'B' && blocks[left] == 'W') changes --;
            ans = min(ans, changes);
            left ++;
            right ++;
        }
        return ans;
    }
};

int main() {
    Solution problem1;
    string blocks = "BWBBWWBBBWBWWWBWWBBWBWBBWBB";
    int k = 11;
    cout << problem1.minimumRecolors(blocks, k);
    return 0;
}