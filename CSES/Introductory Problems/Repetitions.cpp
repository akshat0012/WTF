#include <iostream>
using namespace std;
#define ll long long
/*
 * Used Sliding window
 */
class Solution {
public:
    int repetitions(string s) {
        ll n = s.length();
        // base case
        if (n == 1) {
            return 1;
        }
        ll ans = 0;
        ll left = 0;
        ll right = 1;
        while (right < n) {
            if (s[right] != s[right-1]) {
                left = right;
            }
            ans = max(ans, right-left+1);
            right ++;
        }
        return ans;
    }
};

int main() {
    Solution problem1;
    string sequence;
    cin >> sequence;
    cout << problem1.repetitions(sequence);
    return 0;
}