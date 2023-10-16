#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int left = 0;
        int right = 0;
        int n = s.size();
        vector<string> ans;
        unordered_map<string, int> mp;
        if (n <= 10) return ans;
        while (right < n) {
            int windowSize = right-left+1;
            string temp;
            if (windowSize > 10) {
                left ++;
                temp = s.substr(left, 10);
                mp[temp] ++;
            }
            else if (windowSize == 10) {
                string temp = s.substr(left, 10);
                mp[temp] ++;
            }
            right ++;
        }
        for (auto& el: mp) if (el.second >= 2) ans.push_back(el.first);
        return ans;
    }
}obj;

int main() {
    string str = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> result = obj.findRepeatedDnaSequences(str);
    for (auto& el:result) cout << el << '\n';
    return 0;
}
