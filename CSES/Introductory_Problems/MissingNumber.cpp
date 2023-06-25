#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int n;
    cin >> n;
    vector<long long int> nums(n);
    for (int i = 0; i < n-1; i ++) cin >> nums[i];
    long long int expectedSum = (n * (n+1)) / 2;
    long long int currSum = 0;
    for (int i = 0; i < nums.size(); i ++) currSum += nums[i];
    cout << expectedSum - currSum;
    return 0;
}
