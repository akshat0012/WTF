#include <bits/stdc++.h>
using namespace std;

/*
 *  Daily leetcode challenge
 *  Summary Ranges
 *  12 June 23
 */

class Solution {
private:
    vector<string> result_vector;
public:
    vector<string> summaryRanges(vector<int>& nums) {

        int j = nums[0]; // start pointer

        for (int i = 0; i < nums.size(); ++ i) {

            if (i == nums.size()-1 || nums[i]+1 != nums[i+1]) // this means it reaches the end of the array
            {
                // push the elements
                if (nums[i] != j)
                {
                    result_vector.push_back(to_string(j) + "->" + to_string(nums[i]));
                }
                else
                {
                    result_vector.push_back(to_string(j));
                }
                if (i == nums.size() - 1) j = nums[i+1];
            }
        }
        return result_vector;

    }

    void display() {
        for (int i = 0; i < result_vector.size(); i ++) {
            cout << result_vector[i] << " ";
        }
    }
};

int main() {

    Solution problem1;
//    vector<int> nums {0, 1, 4, 5, 7};
    vector<int> nums {0, 1};
//    vector<int> nums {1};
    problem1.summaryRanges(nums);
    problem1.display();


    return 0;
}
