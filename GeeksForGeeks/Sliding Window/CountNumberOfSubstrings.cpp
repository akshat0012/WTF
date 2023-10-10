#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    long long helper(string s, int k) {
    	int freq[26] = {0};
    	int left = 0;
    	int right = 0;
    	int n = s.size();
    	int distinctCount = 0;
    	long long int ans = 0;
    	
    	while (right < n) {
    	    if (freq[s[right] - 'a'] == 0) distinctCount ++;
    	    freq[s[right] - 'a'] ++;
    	    while (distinctCount > k) {
    	        freq[s[left] - 'a'] --;
    	        if (freq[s[left] - 'a'] == 0) distinctCount --;
    	        left ++;
    	    }
    	    ans += (right-left+1);
    	    right ++;
    	}
    	return ans;
    }
    
    long long int substrCount (string s, int k) {
        return helper(s, k) - helper(s, k-1);
    }
}obj;

int main() {
    string str = "abaaca";
    int k = 1;
    cout << obj.substrCount(str, k);
    return 0;
}
