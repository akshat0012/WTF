#include <bits/stdc++.h>
using namespace std;

int kDistinctChars(string& str, int k) {
    // Sliding Window --> 
    int ans = 0;
    int left = 0;
    int right = 0;
    int distinct = 0;
    int n = str.length();

    vector<char> charr(26);
    while (right < n) {
        charr[str[right] - 'a'] ++;
        if (charr[str[right] - 'a'] == 1) distinct ++;

        while (distinct > k) {
            if (charr[str[left] - 'a'] == 1) {
                distinct --;
            }
            charr[str[left] - 'a'] --;
            left ++;
        }
        ans = max(ans, right-left+1);
        right ++;
    }
    return ans;
}

int main() {
    string str = "cglnbksuyrl";
    int k = 3;
    cout << kDistinctChars(str, k);
    return 0;
}
