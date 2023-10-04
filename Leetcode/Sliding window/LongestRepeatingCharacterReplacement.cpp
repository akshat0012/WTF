#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int left = 0, right = 0;
        int ans = 0;
        int max_count = 0;

        map<char, int> mp;
        while (right < n) {
            mp[s[right]] ++;
            max_count = max(max_count, mp[s[right]]);
            while (right-left-max_count+1 > k) {
                mp[s[left]] --;
                if (mp[s[left]] == 0) mp.erase(s[left]);
                left ++;
            }
            ans = max(ans, right-left+1);
            right ++;
        }
        return ans;
    }
};

int main() {
  Solution problem;
  string s = "AABABBACCCCCAC";
  int k = 1;
  cout << problem.characterReplacement(s, k) << '\n';
  return 0;
}

