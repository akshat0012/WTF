#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution () {
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length();
        int t_count = 0, f_count = 0;
        int ans = 0;
        int left = 0;
        int right = 0;
        while (right < n) {
            //update the count
            if (answerKey[right] == 'T') t_count ++;
            else f_count ++;
            // window validation
            while (min(t_count, f_count) > k) {
                if (answerKey[left] == 'T') t_count --;
                else f_count --;
                left ++;
            }
            ans = max(ans, right-left+1);
            right ++;
        }
        return ans;
    }
};

int main() {
    Solution problem1;
    cout << problem1.maxConsecutiveAnswers("TTFF", 2) << "\n";
    
    return 0;
}
