#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int ans = 0;
        int left = 0;
        int right = 0;
        int n = s.length();
        string temp = "";
        unordered_map<int, int> mp;
        unordered_map<string, int> substrMap;
        while (right < n) {
            mp[s[right]] ++;
            temp = temp + s[right];
            while (mp.size() > maxLetters || temp.size() > minSize) {

                mp[s[left]] --;
                if (mp[s[left]] == 0) mp.erase(s[left]);
                temp.erase(temp.begin()); // removing from the left of the temp string that is for substr map
                left ++;

            }
            if (mp.size() <= maxLetters && (temp.size() >= minSize && temp.size() <= maxSize)) {
                substrMap[temp] ++;
            }
            right ++;
        }

        for (auto& el:substrMap) {
            ans = max(ans, el.second);
        }
        return ans;
    }
}obj;

int main() {
    string str = "aababcaab";
    // string str = "aaaa";
    int maxLetters = 2;
    int minSize = 3;
    int maxSize = 4;
    cout << obj.maxFreq(str, maxLetters, minSize, maxSize) << '\n';
}
