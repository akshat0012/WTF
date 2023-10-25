#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve(vector<ll> &v, ll k) {
    ll left = 0, right = 0, distinct = 0, ans = 0;
    unordered_map<ll, ll> mp;
    for (;right<v.size();right++) {
        mp[v[right]] ++;
        if (mp[v[right]] == 1) distinct ++;
        while (distinct>k) {
            mp[v[left]]--;
            if (mp[v[left]] == 0) {
                distinct --;
                mp.erase(v[left]);
            }
            left ++;
        }
        if (distinct <= k) ans += right-left+1;
    }
    return ans;
}
int main() {
    ll n, x; cin >> n >> x;
    vector<ll> v(n);
    for (ll i=0; i<n; i++) cin >> v[i];
    cout << solve(v, x);
}
