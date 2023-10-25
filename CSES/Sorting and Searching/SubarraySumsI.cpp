#include <iostream>
#include <vector>
using namespace std;
int solve(vector<int>v, int t) {
    int left = 0, right = 0, ans = 0, currSum = 0;
    for (right = 0; right<v.size(); right++) {
        currSum += v[right];
        while (currSum > t) currSum -= v[left++];
        if (currSum == t) ans += 1;
    }
    return ans;
}
int main() {
    int n, x; cin >> n >> x;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin >> v[i];
    cout << solve(v, x);
}
