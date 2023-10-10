#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int helper(int arr[], int n, int k) {
        int ans = 0;
        int left = 0;
        int right = 0;
        unordered_map<int, int> mp;
        while (right < n) {
            mp[arr[right]] ++;
            while (mp.size() > k) {
                mp[arr[left]] --;
                if (mp[arr[left]] == 0) mp.erase(arr[left]);
                left ++;
            }
            ans += right-left+1;
            right ++;
        }
        return ans;
    }
    int countDistinctSubarray(int arr[], int n)
    {
        //code here.
        unordered_set<int> st;
        for (int i=0; i<n; i++) st.insert(arr[i]);
        int k = st.size();
        return helper(arr, n, k) - helper(arr, n, k-1);
    }
};

int main() {
    // int arr[] = {2, 1, 3, 2, 3};
    int arr[] = {2, 4, 4, 2, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << obj.countDistinctSubarray(arr, n);
    return 0;
}
