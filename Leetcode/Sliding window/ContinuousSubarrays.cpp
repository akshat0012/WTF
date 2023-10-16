#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int left = 0;
        int right = 0;
        long long ans = 0;
        int n = nums.size();
            
        deque<int> maxQueue;
        deque<int> minQueue;    

        while (right < n) {
            // update the queues
            while (!maxQueue.empty() && nums[right] > maxQueue.back()) {
                maxQueue.pop_back();
            }
            while (!minQueue.empty() && nums[right] < minQueue.back()) {
                minQueue.pop_back();
            }

            maxQueue.push_back(nums[right]);
            minQueue.push_back(nums[right]);

            // check the diff fo the max and min element of the window
            while (maxQueue.front() - minQueue.front() > 2) {
                if (maxQueue.front() == nums[left]) maxQueue.pop_front();
                if (minQueue.front() == nums[left]) minQueue.pop_front();
                left ++;
            }
            ans += right-left+1;
            right ++;
        }   
        return ans;
    }   
}obj;

int main() {
    vector<int> nums = {5, 4, 2, 4};
    cout << obj.continuousSubarrays(nums);
    return 0;
}
