#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int ans = 0;
        int left = 0;
        int right = 0;
        int n = s.length();
        unordered_map<int, int> mp;
        while (right < n) {
            mp[s[right]] ++;
            while (mp.size() > maxLetters) {
                mp[s[left]] --;
                if (mp[s[left]] == 0) mp.erase(s[left]);
                left ++;
            }
            if (right-left+1 >= minSize && right-left+1 <= maxSize) ans = max(ans, right-left+1);
            right ++;
        }
        return ans;
    }
}obj;
int main() {
    string str = "aababcaab";
    int maxLetters = 2;
    int minSize = 3;
    int maxSize = 4;
    
    cout << obj.maxFreq(str, maxLetters, minSize, maxSize) << '\n';

    return 0;
}
