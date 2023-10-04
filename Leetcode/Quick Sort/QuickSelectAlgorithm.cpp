#include <bits/stdc++.h>
using namespace std;
// Improvised Quick Select
int quickSelect(vector<int>& nums, int s, int e, int k) {
    if (s <= e) {
        // <--------Partition Logic--------->
        int n = nums.size();
        int pivot = nums[e];
        int pivotIndex = s;

        for (int i=s; i<e; i++) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[pivotIndex]);
                pivotIndex ++;
            }
        }
        swap(nums[pivotIndex], nums[e]);

        //<------- main Logic----------------->
        if (n - pivotIndex == k) { // this is going to give me kth largest element.
            return nums[pivotIndex];
        }
        else if (n - pivotIndex  < k) {
            return quickSelect(nums, s, pivotIndex-1, k);
        }
        else {
            return quickSelect(nums, pivotIndex+1, e, k);
        }
    }
    return -1;
}

int main() {
    cout << "Quick Select\n";
    //vector<int> nums {4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
    vector<int> nums {10, 3, 6, 7};
    int k = 5;
    cout << quickSelect(nums, 0, nums.size()-1, k) << '\n';
    
}
