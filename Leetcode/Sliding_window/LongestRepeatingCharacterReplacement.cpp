class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length(); 
        int ans = 0;
        int max_count = 0;
        int left = 0;
        int right = 0;
        unordered_map<char, int> map;

        while (right < n) {
            map[s[right]]++;
            max_count = max(max_count, map[s[right]]);
            while (right-left+1-max_count > k) {
                map[s[left]] --;
                if (map[s[left]] == 0) map.erase(s[left]);
                left ++;
            }
            ans = max(ans, right-left+1);
            right ++;
        }
        return ans;
    }
};
