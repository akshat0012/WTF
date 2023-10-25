#include <bits/stdc++.h>
using namespace std;
long long solve(vector<long long> &v, long long t) {
    long long right = 0, currSum = 0, n = v.size();
    long long ans = 0;
    unordered_map<long long, long long> mp;
    mp[0] = 1;
    for (right = 0; right<n; right++) {
        currSum += v[right];
        if (mp.find(currSum-t) != mp.end())ans += mp[currSum-t];
        mp[currSum] ++;
    }
    return ans;
}
int main() {
    long long n, x; cin >> n >> x;
    vector<long long> v(n);
    for (int i=0; i<n; i++) cin >> v[i];
    cout << solve(v, x);
    return 0;
}
