#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        // Implement the Sliding Window
        int ans = 0;
        int diff = 0;
        int left = 0;
        int right = 0;
        int currCost = 0;
        int n = s.length();
        while (right < n) {
            currCost += abs(s[right]-t[right]);
            while (currCost > maxCost) {
                currCost -= abs(s[left]-t[left++]);
            ans = max(ans, right-left+1);
            right ++;
        }
        return ans; 
    }
}obj;

int main() {
    string s = "abcd", t = "bcdf";
    int maxCost = 3;
    cout << obj.equalSubstring(s, t, maxCost) << '\n';;
    return 0;
}
