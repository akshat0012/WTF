#include <bits/stdc++.h>
using namespace std;
// Fixed Sliding Window
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    int isVowel(char& ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') ? 1 : 0;
    }
    int maxVowels(string s, int k) {
        int n= s.length();
        int ans = 0;
        int vowelsCount = 0;
        unordered_set<char> vowels {'a', 'e', 'i', 'o', 'u'};

        for (int i = 0; i < k; i++) {
            vowelsCount += isVowel(s[i]);
        }
        ans = vowelsCount;
        int left = 1;
        int right = k;
        while (right < n) {
            vowelsCount += isVowel(s[right++]);
            vowelsCount -= isVowel(s[left-1]);
            left ++;
            ans = max(ans, vowelsCount);
        }
        return ans;
    }
};
// t n f a z c w r r y i t g a c a a b w m
// k = 4;

int main() {
    Solution problem1;
    cout << problem1.maxVowels("tnfazcwrryitgacaabwm", 4) << '\n';
    return 0;
};