#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
 * Finding K Beauty Of A Number
 * Sliding window (fixed)
 */
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string str = to_string(num);
        ll n = str.length();

        if (k == n) {
            return 1;
        }

        int left = 0;
        int right = k-1;
        int counter = 0;
        for (right = k-1; right < n; right ++) {
            int number = stoi(str.substr(left, k));
            if (number == 0) {
                counter = counter;
            }
            else {
                if (num % number == 0) counter ++;
            }
            left ++;
        }
        return counter;
    }
};

int main() {
    Solution problem1;
    int num = 0240;
    int k = 2;
    cout << problem1.divisorSubstrings(num, k);
    return 0;
}
