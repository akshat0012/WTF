#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, ans = 0;
    cin >> n;
    vector<ll> nums(n);
    for (int i = 0; i < n; i ++) cin >> nums[i];
    for (ll i = 1; i < n; i ++) {
        if (nums[i] < nums[i-1]) {
            ans += abs(nums[i] - nums[i-1]);
            nums[i] = nums[i-1];
        }
    }
    cout << ans << endl;
    return 0;
}